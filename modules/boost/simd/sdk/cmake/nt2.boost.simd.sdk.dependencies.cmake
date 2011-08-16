################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(nt2.simd)

MESSAGE( STATUS "[boost.simd.sdk] target system: ${NT2_OS} (${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION})" )
MESSAGE( STATUS "[boost.simd.sdk] target processor: ${NT2_ARCH} (${CMAKE_SYSTEM_PROCESSOR})" )

SET(NT2_BOOST.SIMD.SDK_FLAGS ${NT2_SIMD_FLAGS})
SET(NT2_BOOST.SIMD.SDK_DEPENDENCIES_EXTRA boost.dispatch)
SET(NT2_BOOST.SIMD.SDK_LIBRARIES boost_simd)
