//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_NEGATION_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_NEGATION_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/seladd.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::negation_, tag::cpu_,
                           (A0)(X),
                           ((simd_<arithmetic_<A0>,X>))
                           ((simd_<arithmetic_<A0>,X>))
                          )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return  sel(is_ltz(a1),-a0,b_and(is_nez(a1), a0));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::negation_, tag::cpu_,
                           (A0)(X),
                           ((simd_<unsigned_<A0>,X>))
                           ((simd_<unsigned_<A0>,X>))
                          )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
        return  is_nez(a1)&a0;
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::negation_, tag::cpu_,
                           (A0)(X),
                           ((simd_<real_<A0>,X>))
                           ((simd_<real_<A0>,X>))
                          )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      A0 tmp = is_nez(a1)&a0;
      tmp = select(is_ltz(a1), -a0, tmp);
      tmp = seladd(is_nan(a1), tmp, a1); //TODO signed Nan ?
        return tmp;
    }
  };
} }
#endif
