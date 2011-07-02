//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_EVEN_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_EVEN_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_flint.hpp>
#include <nt2/include/functions/is_eqz.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::is_even_, tag::cpu_,
                          (A0)(X),
                          ((simd_<arithmetic_<A0>,X>))
                         )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
       return is_eqz(a0 & One<A0>());
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::is_even_, tag::cpu_,
                          (A0)(X),
                          ((simd_<real_<A0>,X>))
                         )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      return is_flint(a0*Half<A0>());
    }
  };
} }
#endif
