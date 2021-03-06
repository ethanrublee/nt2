//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the \c value_of extension point
 */

namespace boost { namespace dispatch { namespace details
{
  template<class T, class Enable = void>
  struct value_of
  {
    typedef T type;
  };
}
    
namespace meta
{
  template<class T>
  struct value_of : details::value_of<T> {};

  template<class T>
  struct value_of<T&>
  {
    typedef typename value_of<T>::type& type;
  };
  
  template<class T>
  struct value_of<T const>
  {
    typedef typename value_of<T>::type const type;
  };
} } }

#endif
