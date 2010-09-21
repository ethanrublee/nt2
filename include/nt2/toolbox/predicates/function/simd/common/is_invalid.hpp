//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_INVALID_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_INVALID_HPP_INCLUDED
#include <nt2/sdk/constant/boolean.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_nan.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for is_invalid

  /////////////////////////////////////////////////////////////////////////////
  // Compute is_invalid(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<is_invalid_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (2, (real_,arithmetic_))
    )

    // Check for NAN, +infin, or -infin (exponent: 111 1111 1)
    // Are the exponent bits all 1's?
    //    if( (*val & 0x7F800000) = 0x7F800000 )
    //    if( (*val & 0x7FF0000000000000ll) = 0x7FF0000000000000ll )
    NT2_FUNCTOR_CALL_EVAL_IF(1,       real_)
    {
      return isnan(a0-a0);
    }

    NT2_FUNCTOR_CALL_EVAL_IF(1,       arithmetic_)
    {
      details::ignore_unused(a0);
      return False<A0>();
    }
  };
} }

      
#endif
