//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*
 * cache_exception.cpp
 */
#include <nt2/sdk/config/details/cache_exception.hpp>


namespace nt2{ namespace config{ namespace details{

  void cache_exception::display(std::ostream& os) const throw()
  {
    os  << "Assertion: "
        << *boost::get_error_info<nt2::config::details::cache_exc>(*this)
        << " failed.\n";
  }

} } }

