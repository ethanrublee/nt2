//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_EXPONENTBITS_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_EXPONENTBITS_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/strip.hpp>
//
/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::exponentbits_, tag::cpu_,
                               (A0)(X),
                               ((simd_<arithmetic_<A0>,X>))
                              )
  {
 typedef typename meta::as_integer<A0, signed>::type  result_type; 
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      typedef typename meta::as_integer<A0, signed>::type result_type;
      typedef typename meta::scalar_of<A0>::type             s_type;
      typedef typename meta::scalar_of<result_type>::type sint_type;
      const sint_type me = Maxexponent<s_type>();
      const sint_type nmb= Nbmantissabits<s_type>();
      const result_type Mask = splat<result_type>((2*me+1)<<nmb);
      return (b_and(Mask, a0));
    }
  };
} }
#endif
