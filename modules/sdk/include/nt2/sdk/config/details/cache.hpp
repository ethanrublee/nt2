//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_CONFIG_DETAILS_CACHE_HPP_INCLUDED
#define NT2_SDK_CONFIG_DETAILS_CACHE_HPP_INCLUDED

#include <boost/array.hpp>
#include <exception>

/*!
 *\file cache.hpp
 *\Runtime implementation for vendor oriented cache information detection.
*/

namespace nt2{ namespace config{ namespace details{

  struct cache_infos
  {
    typedef int result_type;
    // Initialize the static members with the expected values
    static void init();
    // Return the cache size according to the level in KBytes
    static result_type cache_size(int const& level);
    // Return the cache line size according to the level in Bytes
    static result_type cache_line_size(int const& level);

  private:
    static bool is_init_;
    static boost::array<int,3> cache_sizes_;
    static boost::array<int,3> cache_line_sizes_;
  };

} } }

#endif /* NT2_SDK_CONFIG_CACHE_HPP */
