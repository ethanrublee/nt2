//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/sdk/config/details/cache.hpp>
#include <boost/simd/sdk/config/details/get_vendor.hpp>
#include <boost/simd/sdk/config/details/cpuid.hpp>
#include <nt2/sdk/config/arch.hpp>
#include <cassert>

namespace bsc = boost::simd::config::details;

namespace nt2{ namespace config{ namespace details{

  bool cache_infos::is_init_=false;

  boost::array<int, 3> cache_infos::cache_sizes_      = {-1,-1,-1};
  boost::array<int, 3> cache_infos::cache_line_sizes_ = {-1,-1,-1};

  void cache_infos::init()
  {
    if(is_init_ == false)
    {

#ifdef NT2_ARCH_X86 

      int regs[4] = {0,0,0,0};
      int byte0, byte1, byte2, byte3;
      int cache_ecx = 0;
      int cache_eax = 0;

      switch(bsc::get_vendor())
      {
      case bsc::intel :

        do{
          bsc::cpuidex(regs, 0x00000004, cache_ecx);
          cache_eax = regs[0] & 0x0000001F;
          if(cache_eax == 1 || cache_eax == 3)
          {
            int level      = (regs[0] & 0x000000E0) >> 5; 
            int ways       = (regs[1] & 0xFFC00000) >> 22; 
            int partitions = (regs[1] & 0x003FF000) >> 12; 
            int line_size  = (regs[1] & 0x00000FFF) >>  0; 
            int sets       = (regs[2]);                   
            int size       = (ways+1)*(partitions+1)*(line_size+1)*(sets+1);
            
            switch(level)
            {
            case 1  : cache_sizes_[0] = size/1024; cache_line_sizes_[0] = line_size+1; break; 
            case 2  : cache_sizes_[1] = size/1024; cache_line_sizes_[1] = line_size+1; break;
            case 3  : cache_sizes_[2] = size/1024; cache_line_sizes_[2] = line_size+1; break;
            default : break;
            }
          }
          cache_ecx++;
        }while(cache_eax != 0x00000000);

        break;

      case bsc::amd : 

        bsc::cpuidex(regs,0x80000005,0);
        cache_line_sizes_[0] = regs[2] & 0x000000FF;
        cache_sizes_[0]      = regs[2] >> 24; 

        regs[0] = regs[1] = regs[2] = regs[3] = 0;
        bsc::cpuidex(regs,0x80000006,0);

        cache_line_sizes_[1] = regs[2] & 0x000000FF;
        cache_sizes_[1]      = (regs[2] >> 16); 
        cache_line_sizes_[2] = regs[3] & 0x000000FF;
        cache_sizes_[2]      = ((regs[3] & 0xFFFC000) >> 18)*512; // D[31;18] = l3 cache size in 512KB

        break;

      default : break;

      }
#elif NT2_ARH_POWERPC
      // TODO : PowerPC cache detection version with auxvec (need some work in branch new_config)
#else
#warning "Unkown Architecture for cache detection"
#endif
      is_init_ = true;
    }
  }

  int cache_infos::cache_size(int const& level)
  {
    assert(is_init_ == true);
    return cache_sizes_[level-1];
  }

  int cache_infos::cache_line_size(int const& level)
  {
    assert(is_init_ == true);
    return cache_line_sizes_[level-1];
  }

} } } 
