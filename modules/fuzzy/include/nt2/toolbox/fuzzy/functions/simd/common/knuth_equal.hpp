//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTIONS_SIMD_COMMON_KNUTH_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTIONS_SIMD_COMMON_KNUTH_EQUAL_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/maxnummag.hpp>
#include <nt2/include/functions/dist.hpp>
#include <nt2/include/functions/exponent.hpp>
#include <nt2/include/functions/ldexp.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::tag::knuth_equal_, tag::cpu_,
                              (A0)(X),
                              ((simd_<real_<A0>,X>))
                              ((simd_<real_<A0>,X>))
                              ((simd_<real_<A0>,X>))
                             )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(3)
    {
      return b_or( eq(a0, a1)
                   , le( dist(a0, a1)
                     , ldexp(a2,
                           exponent(maxnummag(a0, a1))
                           )
                     )
                   );
    }
  };
} }
#endif
