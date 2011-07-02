//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_REDUCTION_FUNCTION_SIMD_COMMON_MINIMUM_HPP_INCLUDED
#define NT2_TOOLBOX_REDUCTION_FUNCTION_SIMD_COMMON_MINIMUM_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::minimum_, tag::cpu_,
                          (A0)(X),
                          ((simd_<arithmetic_<A0>,X>))
                         )
  {
 typedef typename meta::scalar_of<A0>::type result_type; 
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      typedef result_type type;
      type r = a0[0];
      for(size_t i=1; i < meta::cardinal_of<A0>::value; i++)
      r = (r >  a0[i]) ? a0[i] : r;
      return r;
    }
  };
} }
#endif
