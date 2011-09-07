//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/sdk/config/details/get_vendor.hpp>
#include <nt2/sdk/config/cache.hpp>
#include <nt2/sdk/config/details/cache.hpp>

/*!
 *\file cache.cpp
*/

namespace nt2{ namespace config{

  int cache_size(int const& cache_level)
  {
    details::cache_infos::init();
    switch(cache_level) 
    {
    case 1 : return details::cache_infos::cache_size(1); 
      break;
    case 2 : return details::cache_infos::cache_size(2); 
      break;
    case 3 : return details::cache_infos::cache_size(3); 
      break;
    default : return 0; break;
    }
  }

  int cache_line_size(int const& cache_level)
  {
    details::cache_infos::init();
    switch(cache_level) 
    {
    case 1 : return details::cache_infos::cache_line_size(1); 
      break;
    case 2 : return details::cache_infos::cache_line_size(2); 
      break;
    case 3 : return details::cache_infos::cache_line_size(3); 
      break;
    default : return 0; break;
    }
  }

} }
