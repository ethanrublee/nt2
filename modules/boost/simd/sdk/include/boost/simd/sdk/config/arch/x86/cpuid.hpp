//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_CONFIG_ARCH_X86_CPUID_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_ARCH_X86_CPUID_HPP_INCLUDED

/*!
 *\file cpuid.hpp
 *\brief cpuid function to get x86 processor infos
*/

#include <boost/simd/sdk/config/arch/x86.hpp>
#ifdef BOOST_SIMD_ARCH_X86

namespace boost { namespace simd { namespace config { namespace x86
{
  void cpuid(int CPUInfo[4],int InfoType);
} } } }

#endif
#endif
