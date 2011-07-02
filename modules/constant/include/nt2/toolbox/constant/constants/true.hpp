//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_CONSTANT_CONSTANTS_TRUE_HPP_INCLUDED
#define NT2_TOOLBOX_CONSTANT_CONSTANTS_TRUE_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/sdk/constant/constant.hpp>
#include <nt2/toolbox/constant/include.hpp>
#include <nt2/sdk/constant/common.hpp>

namespace nt2
{
  namespace tag
  {
    struct true_  { typedef bool default_type; };
  }
  
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::true_, True)
}

#include <nt2/toolbox/constant/constants/scalar/true.hpp>
#include <nt2/toolbox/constant/constants/simd/all/true.hpp>

#endif
