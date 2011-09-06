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
#include <boost/simd/sdk/config/details/get_vendor.hpp>
#include <boost/simd/sdk/config/arch/x86/cpuid.hpp>

#define INTEL "GenuineIntel"
#define AMD   "AuthenticAMD"

namespace boost { namespace simd { namespace config { namespace details
{  
  static bool str_match(const int abcd[4], const char* vendor)
  {
    return (abcd[1] == ((int*)(vendor))[0] && abcd[2] == ((int*)(vendor))[2] && abcd[3] == ((int*)(vendor))[1]);
  }

  int get_vendor()
  {
    static const int function = 0x00000000;
    int regs_x86[4]; 
    x86::cpuid(regs_x86, function);
    if( str_match(regs_x86, INTEL) ) return intel;
    else if( str_match(regs_x86, AMD) ) return amd;
    else return -1;
  }
} } } }

#endif
