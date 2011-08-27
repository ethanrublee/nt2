/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SIMD_COMMON_IMPL_TRIGO_TRIG_BASE_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SIMD_COMMON_IMPL_TRIGO_TRIG_BASE_HPP_INCLUDED

#include <nt2/include/functions/any.hpp>
#include <nt2/include/functions/is_invalid.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/is_flint.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/shri.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/sdk/simd/tags.hpp>

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template < class A0, class unit_tag, class mode> 
      struct trig_base < A0, unit_tag,  tag::simd_type, mode>
      {
        typedef trig_reduction<A0,unit_tag, tag::simd_type, mode> redu_t;
        typedef trig_evaluation<A0,tag::simd_type>                eval_t;
        typedef typename meta::scalar_of<A0>::type                   sA0; // scalar version of A0
        typedef typename meta::as_integer<A0, signed>::type     int_type; // signed integer type associated to A0
        typedef typename meta::scalar_of<int_type>::type       sint_type; // scalar version of the associated type   
        typedef typename mode::type                                style;
        typedef typename A0::native_type                            A0_n; 
        // for all functions the scalar algorithm is:
        // * range reduction
        // * computation of sign and evaluation selections flags
        // * evaluations of the two branches and selection using flags
        // * return with flag based corrections and inf and nan or specific invalid cases inputs considerations

        static inline A0_n cosa(const A0& a0){ return cosa(a0, style()); }
        static inline A0_n sina(const A0& a0){ return sina(a0, style()); }
        static inline A0_n tana(const A0& a0){ return tana(a0, style()); }
        static inline A0_n cota(const A0& a0){ return cota(a0, style()); }
        static inline A0_n sincosa(const A0& a0, A0& c){ return sincosa(a0,c,style()); }
        
      private:
        static inline A0_n cosa(const A0_n a0_n, const fast&)
        {
	  const A0 a0 = { a0_n };
	  const A0 x =  scale(a0);
          return  eval_t::cos_eval(sqr(x), x, Zero<A0>());
        }

        static inline A0_n cosa(const A0_n a0_n, const regular&)
        {
	  const A0 a0 = { a0_n };
	  static const sint_type de = sizeof(sint_type)*8-1;
          // de is the size in bits of the scalar types minus one
          const A0 x = nt2::abs(a0);
          A0 xr = Nan<A0>(), xc;
          const int_type n =  redu_t::reduce(x, xr, xc); 
          const int_type swap_bit = n&One<int_type>();
          const int_type sign_bit = shli(b_xor(swap_bit, shri(n&Two<int_type>(), 1)), de); 
          const A0 z = sqr(xr);
	  const A0 se =  {eval_t::sin_eval(z, xr, xc)};
	  const A0 ce =  {eval_t::cos_eval(z, xr, xc)}; 
          return  b_xor(sel(is_nez(swap_bit), se, ce), sign_bit); 
        }

        static inline A0_n sina(const A0_n a0_n, const fast&)
        {
	  const A0 a0 = { a0_n };
          const A0 x =  scale(a0);
	  const A0 se =  {eval_t::sin_eval(sqr(x), x, Zero<A0>())}; 
          return se; 
        }

        static inline A0_n sina(const A0_n a0_n, const regular&)
        {
	  const A0 a0 = { a0_n };
          static const sint_type de = sizeof(sint_type)*8-1;
          // size in bits of the scalar types minus one
          const A0 x = nt2::abs(a0);
          A0 xr = Nan<A0>(), xc;
          const int_type n = redu_t::reduce(x, xr, xc);
          const int_type swap_bit = n&One<int_type>();
          const A0 sign_bit = b_xor(bitofsign(a0), shli(n&Two<int_type>(), de-1)); 
          const A0 z = sqr(xr);
	  const A0 se =  {eval_t::sin_eval(z, xr, xc)};
	  const A0 ce =  {eval_t::cos_eval(z, xr, xc)}; 
          return b_xor(sel(is_eqz(swap_bit),se, ce), sign_bit); 
        }

        static inline A0_n tana(const A0_n a0_n, const fast&)
        {
	  const A0 a0 = { a0_n };
          const A0 bte = { eval_t::base_tancot_eval(scale(a0))};
	  return bte; 
        }

        static inline A0_n tana(const A0_n a0_n, const regular&)
        {
	  const A0 a0 = { a0_n };
          const A0 x =  nt2::abs(a0); 
          A0 xr = Nan<A0>(), xc;
          const int_type n = redu_t::reduce(x, xr, xc);
          const A0 y = {eval_t::tan_eval(xr, xc, oneminus(shli((n&One<int_type>()), 1)))};
          // 1 -- n even  -1 -- n odd 
          const A0 testnan = redu_t::tan_invalid(a0);
          return b_or(testnan, b_xor(y, bitofsign(a0)));                        
        }

        static inline A0_n cota(const A0_n a0_n, const fast&)
        {
	  const A0 a0 = { a0_n };
	  const A0 bte = {eval_t::base_tancot_eval(scale(a0))}; 
          return rec(bte); 
        }

        static inline A0_n cota(const A0_n a0_n, const regular&)
        {
	  const A0 a0 = { a0_n };
          const A0 x =  nt2::abs(a0); 
          A0 xr = Nan<A0>(), xc;
          const int_type n = redu_t::reduce(x, xr, xc);
          const A0 y = {eval_t::cot_eval(xr, xc, oneminus(shli((n&One<int_type>()), 1)))};
          // 1 -- n even -1 -- n odd 
          const A0 testnan = redu_t::cot_invalid(a0); 
          return b_or(testnan, b_xor(y, bitofsign(a0)));                        
        }

        // simultaneous cosa and sina function
        static inline A0_n sincosa(const A0_n a0_n, A0& c, const fast&)
        {
	  const A0 a0 = { a0_n };
          const A0 x =  scale(a0);
          const A0 z =  sqr(x);
          c = eval_t::cos_eval(z, x, Zero<A0>());
          return eval_t::sin_eval(z, x, Zero<A0>());
        }
        
        static inline A0_n sincosa(const A0_n a0_n, A0& c, const regular&)
        {
	  const A0 a0 = { a0_n };
          static const sint_type de = sizeof(sint_type)*8-1;
          // size in bits of the scalar types minus one
          const A0 x =  nt2::abs(a0);
          A0 xr = Nan<A0>(), xc;
          const int_type n = redu_t::reduce(x, xr, xc);
          const int_type swap_bit = n&One<int_type>();
          const A0 z = nt2::sqr(xr);
          const int_type cos_sign_bit = shli(b_xor(swap_bit, shri(n&Two<int_type>(), 1)), de); 
          const int_type sin_sign_bit = b_xor(shli(n&Two<int_type>(), de-1), bitofsign(a0)); 
          const A0 t1 = {eval_t::sin_eval(z, xr, xc)};
          const A0 t2 = {eval_t::cos_eval(z, xr, xc)};
          const int_type test = is_nez(swap_bit);
          c = b_xor(sel(test, t1, t2),cos_sign_bit);
          return b_xor(sel(test, t2, t1),sin_sign_bit); 
        }

        static inline A0 scale(const A0& a0)
        {
          return b_or(a0, gt(nt2::abs(a0),
                             trig_ranges<A0,unit_tag>::max_range()))
            *trig_ranges<A0,unit_tag>::scale();
        }

      }; 
    }
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of trig_base.hpp
// /////////////////////////////////////////////////////////////////////////////
