//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_CONFIG_DETAILS_CACHE_DETECT_HPP_INCLUDED
#define NT2_SDK_CONFIG_DETAILS_CACHE_DETECT_HPP_INCLUDED

#include <vector>
 
namespace nt2{ namespace config{ namespace details{

  void detect_cache(std::vector<int>& cache_sizes_, std::vector<int>& cache_line_sizes_);

} } }

#endif
