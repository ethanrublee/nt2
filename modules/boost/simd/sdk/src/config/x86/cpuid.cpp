//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/sdk/config/arch/x86.hpp>

#ifdef BOOST_SIMD_ARCH_X86
#include <boost/simd/sdk/config/arch/x86/cpuid.hpp>
#include <boost/simd/sdk/config/compiler/gcc.hpp>
#include <boost/simd/sdk/config/compiler/msvc.hpp>

#if defined(BOOST_SIMD_COMPILER_MSVC)
#include <intrin.h>
#endif

namespace boost { namespace simd { namespace config { namespace x86
{
  void cpuid(int CPUInfo[4],int InfoType)
  {
#if defined(BOOST_SIMD_COMPILER_GNU_C)
    enum { eax,ebx,ecx,edx };
    __asm__ __volatile__
    (
      "cpuid":\
      "=a" (CPUInfo[eax]), "=b" (CPUInfo[ebx])
    , "=c" (CPUInfo[ecx]), "=d" (CPUInfo[edx])
    : "a" (InfoType)
    );
#elif defined(BOOST_SIMD_COMPILER_MSVC)
    __cpuid(CPUInfo,InfoType);
#endif
  }
} } } }

#endif

