//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/sdk/config/os/linux/hwcap.hpp>

#ifdef BOOST_SIMD_OS_LINUX
#include <linux/auxvec.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

namespace boost { namespace simd { namespace config { namespace linux_
{
  unsigned int hwcap()
  {
    int fd;
    Elf32_auxv_t auxv;
    
    fd = open("/proc/self/auxv", O_RDONLY);
    if (fd >= 0)
    {
      while(read(fd, &auxv, sizeof(Elf32_auxv_t)) == sizeof(Elf32_auxv_t))
      {
        if (auxv.a_type == AT_HWCAP)
        {
          close(fd);
          return auxv.a_un.a_val;
        }
      }
      close(fd);
    }
    return 0;
  }
} } } }

#endif
