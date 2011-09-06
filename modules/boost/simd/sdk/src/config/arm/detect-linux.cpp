//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/sdk/config/arch/arm.hpp>
#include <boost/simd/sdk/config/os/linux/hwcap.hpp>

#if defined(BOOST_SIMD_ARCH_ARM) && defined(BOOST_SIMD_OS_LINUX)
#include <boost/simd/sdk/config/details/detect.hpp>
#include <asm/hwcap.h>

namespace boost { namespace simd { namespace config { namespace details
{
  bool detect(tag::neon_ const&)
  {
    return linux_::hwcap() & HWCAP_NEON;
  }
} } } }

#endif
