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
#include <nt2/sdk/error/error.hpp>
#include <vector>
/*!
 *\file cache.hpp
 *\Runtime implementation for vendor oriented cache information detection.
*/

namespace nt2{ namespace config{ namespace details{

  struct cache_infos
  {
    typedef int result_type;
    typedef std::vector<int>::const_iterator const_iterator;

    // Initialize the static members with the expected values
    static void init();
    // Return the cache size according to the level in KBytes
    static result_type cache_size(int const& level);
    // Return the cache line size according to the level in Bytes
    static result_type cache_line_size(int const& level);
    //Returns the number of levels
    static result_type get_max_level();
    //Return an iterator that point to the first element of
    //the vector that contains the cache size infos index by the level
    static const_iterator cache_size_begin();
    //Return an iterator that point to the first element of
    //the vector that contains the cache line size infos index by the level
    static const_iterator cache_line_size_begin();
    //Return an iterator that point to the last element of
    //the vector that contains the cache size infos index by the level
    static const_iterator cache_size_end();
    //Return an iterator that point to the last element of
    //the vector that contains the cache line size infos index by the level
    static const_iterator cache_line_size_end();

  private:
    static bool is_init_;
    static std::vector<int> cache_sizes_;
    static std::vector<int> cache_line_sizes_;

  };

} } }

#endif /* NT2_SDK_CONFIG_CACHE_HPP */
