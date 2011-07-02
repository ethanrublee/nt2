//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_CONSTANT_CONSTANTS_IEEE_SPEC_HPP_INCLUDED
#define NT2_TOOLBOX_CONSTANT_CONSTANTS_IEEE_SPEC_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Make some real based constants
////////////////////////////////////////////////////////////////////////////////
#include <nt2/include/simd.hpp>
#include <nt2/sdk/constant/constant.hpp>
#include <nt2/toolbox/constant/include.hpp>
#include <nt2/sdk/constant/common.hpp>

namespace nt2
{
  namespace tag
  {
    struct ldexp_mask_        { typedef double default_type; };
    struct nb_digits_         { typedef double default_type; };
    struct nb_mantissa_bits_  { typedef double default_type; };
    struct nb_exponent_bits_  { typedef double default_type; };
    struct max_exponent_      { typedef double default_type; };
    struct min_exponent_      { typedef double default_type; };
  }
  
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::ldexp_mask_       , Ldexpmask      )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::nb_mantissa_bits_ , Nbmantissabits )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::nb_exponent_bits_ , Nbexponentbits )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::max_exponent_     , Maxexponent    )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::min_exponent_     , Minexponent    )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::nb_digits_        , Nbdigits       )
}

#include <nt2/toolbox/constant/constants/scalar/ieee_spec.hpp>
#include <nt2/toolbox/constant/constants/simd/all/ieee_spec.hpp>

#endif
