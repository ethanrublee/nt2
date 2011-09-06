//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_CONFIG_OS_LINUX_HWCAP_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_OS_LINUX_HWCAP_HPP_INCLUDED

#include <boost/simd/sdk/config/os/linux.hpp>
#ifdef BOOST_SIMD_OS_LINUX

namespace boost { namespace simd { namespace config { namespace linux_
{
  unsigned int hwcap();
} } } }

#endif
#endif
