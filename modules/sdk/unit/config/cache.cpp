//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2::config::cache"

#include <nt2/sdk/config/details/cache.hpp>
#include <nt2/sdk/config/cache.hpp>
#include <iostream>
#include <vector>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

using namespace nt2::config;
using namespace nt2::config::details;

////////////////////////////////////////////////////////////////////////////////
// Show the result of cache infos detected at runtime
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(cache_sizes)
{
  for (int i = 1; i < 4; ++i)
  {
    std::cout << "Cache L" << i << " size : " << cache_size(i) << " KBytes" << std::endl;
  }

}

NT2_TEST_CASE(cache_line_sizes)
{
  cache_infos::const_iterator it = cache_infos::cache_line_size_begin();
  int i = 1;
  for (; it != cache_infos::cache_line_size_end(); ++it)
  {
    std::cout << "Cache L" << i << " line size : " << *it << " Bytes" << std::endl;
    i++;
  }
}