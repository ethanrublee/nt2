//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_CONFIG_DETAILS_CACHE_EXCEPTION_HPP
#define NT2_SDK_CONFIG_DETAILS_CACHE_EXCEPTION_HPP
/*
 * cache_exception.hpp
 *
 */

#include <nt2/sdk/error/error.hpp>

namespace nt2{ namespace config{ namespace details{

  NT2_ERROR_INFO(cache_exc, const char *);

  struct cache_exception : virtual nt2::exception
  {
    virtual ~cache_exception() throw() {}
    virtual void display(std::ostream& os) const throw();
  };
} } }

#endif /* NT2_SDK_CONFIG_DETAILS_CACHE_EXCEPTION_HPP */
