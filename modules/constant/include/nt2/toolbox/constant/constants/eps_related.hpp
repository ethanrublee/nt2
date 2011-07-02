//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_CONSTANT_CONSTANTS_EPS_RELATED_HPP_INCLUDED
#define NT2_TOOLBOX_CONSTANT_CONSTANTS_EPS_RELATED_HPP_INCLUDED

#include <nt2/include/simd.hpp>
#include <nt2/sdk/constant/constant.hpp>
#include <nt2/toolbox/constant/include.hpp>
#include <nt2/sdk/constant/common.hpp>

namespace nt2 { namespace tag
{
  struct eps__            { typedef double default_type; };
  struct half_eps__       { typedef double default_type; };
  struct _3_x_eps_        { typedef double default_type; };
  struct sqrt_eps_        { typedef double default_type; };
  struct forth_root_eps_  { typedef double default_type; };
  struct third_root_eps_  { typedef double default_type; };
  struct mlog_eps_2_      { typedef double default_type; };
  struct min_denormal_    { typedef double default_type; };
  struct smallest_pos_val_{ typedef double default_type; };
} }

namespace nt2
{
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::eps__            , Eps           )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::half_eps__       , Halfeps       )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::_3_x_eps_        , Threeeps      )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::sqrt_eps_        , Sqrteps       )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::forth_root_eps_  , Fourthrooteps  )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::third_root_eps_  , Thirdrooteps  )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::mlog_eps_2_      , Mlogeps2      )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::min_denormal_    , Mindenormal   )
  NT2_CONSTANT_IMPLEMENTATION(nt2::tag::smallest_pos_val_, Smallestposval)
}

#include <nt2/toolbox/constant/constants/scalar/eps_related.hpp>
#include <nt2/toolbox/constant/constants/simd/all/eps_related.hpp>

#endif
