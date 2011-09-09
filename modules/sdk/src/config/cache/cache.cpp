//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/sdk/config/details/get_vendor.hpp>
#include <boost/simd/sdk/config/details/cpuid.hpp>
#include <nt2/sdk/config/details/detect_cache.hpp>
#include <nt2/sdk/config/details/cache_exception.hpp>
#include <nt2/sdk/error/assert.hpp>
#include <nt2/sdk/config/details/cache.hpp>
#include <nt2/sdk/config/arch.hpp>
#include <cassert>
#include <vector>

namespace nt2{ namespace config{ namespace details{

  bool cache_infos::is_init_=false;
  std::vector<int> cache_infos::cache_sizes_;
  std::vector<int> cache_infos::cache_line_sizes_;

  void cache_infos::init()
  {
    if(!is_init_)
    {
      detect_cache(cache_sizes_, cache_line_sizes_);
      is_init_ = true;
    }
  }

  cache_infos::result_type cache_infos::cache_size(int const& level)
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    if(level > cache_sizes_.size())
      throw cache_exc("This level of cache is not available on the current target.");
    else return cache_sizes_[level-1];
  }

  cache_infos::result_type cache_infos::cache_line_size(int const& level)
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    if(level > cache_line_sizes_.size())
      throw cache_exc("This level of cache is not available on the current target.");
    else return cache_line_sizes_[level-1];
  }

  cache_infos::result_type cache_infos::get_max_level()
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    return cache_sizes_.size();
  }

  cache_infos::const_iterator cache_infos::cache_size_begin()
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    const_iterator it = cache_sizes_.begin();
    return it;
  }

  cache_infos::const_iterator cache_infos::cache_line_size_begin()
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    const_iterator it = cache_line_sizes_.begin();
    return it;
  }

  cache_infos::const_iterator cache_infos::cache_size_end()
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    const_iterator it = cache_sizes_.end();
    return it;
  }

  cache_infos::const_iterator cache_infos::cache_line_size_end()
  {
    BOOST_ASSERT_MSG(is_init_ == true, "Objet needs to be initialized first.");
    const_iterator it = cache_line_sizes_.end();
    return it;
  }

} } } 
