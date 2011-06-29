//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_IS_SET_HPP_INCLUDED
#define NT2_SDK_META_IS_SET_HPP_INCLUDED

/*!
 * \file
 * \brief Defines and implements nt2::meta::is_set \metafunction
 */

#include <boost/mpl/bool.hpp>

namespace nt2 { namespace meta
{
  //============================================================================
  /*!
   * Checks if a given type behaves as a nt2::meta::set
   *
   * \model
   *
   * \metafunction
   *
   * \semantic
   *
   * For any type \c T,
   *
   * \code
   * typedef nt2::meta::is_set<T>::type r;
   * \endcode
   *
   * evaluates to \true_ if \c T is usable as a nt2::meta::set. Otherwise, it
   * evaluates to \false_.
   *
   * \usage
   *
   * \include is_set.cpp
   */
  //============================================================================
  template<class T, class V = void> struct is_set : boost::mpl::false_ {};

  template<class T>
  struct is_set<T, typename T::is_set_type> : boost::mpl::true_ {};
} }

#endif
