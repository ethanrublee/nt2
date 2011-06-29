//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_DETAILS_IS_RESULT_OF_SUPPORTED_HPP_INCLUDED
#define NT2_SDK_META_DETAILS_IS_RESULT_OF_SUPPORTED_HPP_INCLUDED

#include <boost/mpl/has_xxx.hpp>
#include <nt2/sdk/meta/enable_if_type.hpp>

namespace nt2 { namespace details
{
  //============================================================================
  // Is result_type defined in a given type ?
  //============================================================================
  BOOST_MPL_HAS_XXX_TRAIT_DEF(result_type)

  //============================================================================
  // Is a inner result struct defined in a given type ?
  //============================================================================
  template<class F, class FArgs, class Enable=void>
  struct result_defined
       : boost::mpl::false_ {};

  template<class F, class Args>
  struct result_defined< F
                       , Args
                       , typename meta::enable_if_type<
                                  typename F::template result<Args>::type
                                                      >::type
                       >
       : boost::mpl::true_ {};
} }

#endif
