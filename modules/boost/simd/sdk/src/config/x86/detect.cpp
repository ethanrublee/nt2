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
#include <boost/simd/sdk/config/details/detect.hpp>
#include <boost/simd/sdk/config/details/get_vendor.hpp>
#include <boost/simd/sdk/config/arch/x86/cpuid.hpp>

#define BOOST_SIMD_DECLARE_X86_DETECTION_CALL(x, y, z)                         \
static const int bit = x, function = y, register_id = z;                       \
int regs_x86[4];                                                               \
x86::cpuid(regs_x86, function);                                                \
return has_bit_set(regs_x86[register_id-1], bit);                              \
/**/

namespace boost { namespace simd { namespace config { namespace details
{
  static bool has_bit_set(int value, int bit)
  {
    return (value & (1<<bit)) != 0;
  }
    
  bool detect(tag::sse2_ const&)
  {
    if(get_vendor() == intel || get_vendor() == amd) 
    { BOOST_SIMD_DECLARE_X86_DETECTION_CALL(26,0x00000001,4) }
    else return false;
  }

  bool detect(tag::sse3_ const&)
  {
    if(get_vendor() == intel || get_vendor() == amd) 
    { BOOST_SIMD_DECLARE_X86_DETECTION_CALL(0,0x00000001,3) }
    else return false;
  }

  bool detect(tag::ssse3_ const&)
  {
    if(get_vendor() == intel || get_vendor() == amd) 
    { BOOST_SIMD_DECLARE_X86_DETECTION_CALL(9,0x00000001,3) }
    else return false;
  }

  bool detect(tag::sse4a_ const&)
  {
    if(get_vendor() == amd){ BOOST_SIMD_DECLARE_X86_DETECTION_CALL(6,0x80000001,3); }
    else return false;
  }

  bool detect(tag::sse4_1_ const&)
  {
    if(get_vendor() == intel || get_vendor() == amd) 
    { BOOST_SIMD_DECLARE_X86_DETECTION_CALL(19,0x00000001,3) }
    else return false;
  }

  bool detect(tag::sse4_2_ const&)
  {
    if(get_vendor() == intel || get_vendor() == amd) 
    { BOOST_SIMD_DECLARE_X86_DETECTION_CALL(20,0x00000001,3) }
    else return false;
  }

  bool detect(tag::avx_ const&)
  {
    if(get_vendor() == intel || get_vendor() == amd) 
    { BOOST_SIMD_DECLARE_X86_DETECTION_CALL(28,0x00000001,3) }
    else return false;
  }
} } } }

#endif
