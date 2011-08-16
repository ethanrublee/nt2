//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EULER_FUNCTIONS_SIMD_COMMON_EXPNI_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTIONS_SIMD_COMMON_EXPNI_HPP_INCLUDED
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/exp.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/pow.hpp>
#include <nt2/include/functions/gamma.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_odd.hpp>
#include <nt2/include/functions/bitwise_ornot.hpp>
#include <nt2/include/functions/seladd.hpp>
#include <nt2/include/functions/nbtrue.hpp>
#include <nt2/include/functions/any.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::expni_, tag::cpu_
			      , (A0)(A1)(X)
                            , (scalar_< integer_<A0> >)((simd_<integer_<A1>,X>))
                            )
  {

    typedef typename meta::as_real<A1>::type result_type;

    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return expni(a0, tofloat(a1));
    }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A1 is real_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(nt2::tag::expni_, tag::cpu_,
			     (A0)(A1)(X),
			     ((scalar_<integer_<A0> > ))
			     ((simd_<real_<A1>,X>))
			     )
  {
    typedef A1 result_type; 
    NT2_FUNCTOR_CALL(2)
      {
	A1 isltza1 = is_ltz(a1); 
	A1 x =  b_or(a1, isltza1);
	const int32_t sn =  a0;
	if( sn == 0 )  return nt2::exp(-x)/x;
	if (sn < 0 )   return Nan<A1>();
	A1 n = splat<A1>(sn);
	if (sn  > 5000 )
	  {
	    A1 xk = x + n;
	    A1 yk = rec(sqr(xk));
	    A1 t = n;
	    A1 ans = yk*t*(Six<A1>()*sqr(x)-Eight<A1>()*t*x+sqr(t));
	    ans = yk*(ans+t*(t-Two<A1>()*x));
	    ans = yk*(ans+t);
	    return oneplus(ans)*exp(-x)/xk;
	  }
	A1 r =  Nan<A1>();
	A1 test1 = le(a1, One<A1>());
	uint32_t nb = 0;
	if ((nb = nbtrue(test1)) > 0)
	  {
	    A1 xx = sel(test1, x, One<A1>());
	    A1 y1 = case_1(xx, sn, n);
	    r = b_ornot(y1, test1);
	    if (nb >= meta::cardinal_of<A1>::value) return b_or(r, isltza1);
	  }
	A1 xx = sel(test1, Two<A1>(), x);
	A1 y2 =  case_2(xx, sn, n);
	r &= b_or(y2, test1);
	r =  seladd(lt(x, Maxlog<A1>()), Zero<A1>(), r);
	return b_or(r,  b_or(is_nan(a1), isltza1)); // we are done
      }
  private :
    template < class AA1 >
      static inline AA1 case_1(AA1 & x,  int32_t sn, const AA1 & n)
      {
	typedef typename meta::scalar_of<AA1>::type sA1; 
      /*		Power series expansion		*/
      AA1 eqzx = is_eqz(x);
      x = seladd(is_eqz(x), x, One<A1>()); //loop is infinite for x == 0
      sA1 psi1 = Zero<sA1>(); 
      for( int32_t i=sn-1; i; --i )  psi1 += rec((sA1)i);
      AA1 psi = -Euler<A1>()-nt2::log(x)+splat<A1>(psi1); 
      AA1 t; 
      AA1 z = -x;
      AA1 xk = Zero<A1>();
      AA1 yk = One<A1>();
      AA1 pk = One<A1>() - n;
      AA1 ans = ( sn == 1 ) ? Zero<A1>() : rec(pk);
      do
 	{
	  xk += One<AA1>();
 	  yk *= z/xk;
	  pk += One<AA1>();
	  ans = seladd(is_nez(pk), ans, yk/pk); 
	  t = select(is_nez(ans), nt2::abs(yk/ans), One<AA1>());
 	}
      while( nt2::any(gt(t, Halfeps<A1>())));
      return seladd(eqzx,(nt2::powi(z, sn-1) * psi / nt2::gamma(n)) - ans, Inf<A1>());
      //TO DO pow->powi and gamma splatted from scalar or mere factorial call
      }
    
    template < class AA1 >
      static inline AA1 case_2(const AA1 & x,  int32_t /*sn*/, const AA1 & n)
      {
	typedef typename meta::scalar_of<AA1>::type sAA1;
      int32_t sk = 1;
      AA1 t; 
      AA1 pkm2 = One<AA1>();
      AA1 qkm2 = x;
      AA1 pkm1 = One<AA1>();
      AA1 qkm1 = x + n;
      AA1 ans = pkm1/qkm1;
      do
	{
	  AA1 test =  is_nez(splat<AA1>(is_odd(++sk)));
	  AA1 k_2 =  splat<AA1>(sk >> 1); 
	  AA1 yk = sel(test, One<AA1>(), x);
	  AA1 xk = seladd(test, k_2, n); 
	  AA1 pk = pkm1 * yk  +  pkm2 * xk;
	  AA1 qk = qkm1 * yk  +  qkm2 * xk;
	  AA1 r = pk/qk;
	  test = is_nez(qk); 
	  t = sel(test,nt2::abs((ans-r)/r),One<AA1>());
	  ans = sel(test, r, ans);
	  pkm2 = pkm1;
	  pkm1 = pk;
	  qkm2 = qkm1;
	  qkm1 = qk;
	  test = gt(nt2::abs(pk), Expnibig<AA1>());
	  AA1 fac = sel(test, Halfeps<AA1>(), One<AA1>()); 
	  pkm2 *= fac;
	  pkm1 *= fac;
	  qkm2 *= fac;
	  qkm1 *= fac;
	}
      while( nt2::any(gt(t, Halfeps<AA1>())) );
      return ans*nt2::exp(-x);
    }
  };
} }

#endif
