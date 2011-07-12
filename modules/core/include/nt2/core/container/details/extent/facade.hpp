//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_FACADE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_FACADE_HPP_INCLUDED

#include <cstddef>
#include <boost/array.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/settings/storage_kind.hpp>
#include <nt2/core/settings/storage_order.hpp>
#include <nt2/core/container/details/extent/container.hpp>
#include <nt2/core/container/details/extent/fusion.hpp>
#include <nt2/core/container/details/extent/domain.hpp>

namespace nt2 { namespace ext
{
  //============================================================================
  // extent facade - extent builds terminals out of boost::array of proper size
  //============================================================================
  template<class Dimensions,class S>
  struct facade<tag::extent_,Dimensions, S>
  {
    typedef descriptor< Dimensions
                      , matlab_index_
                      , stack_(column_major_)
                      >                                       descriptor_type;
    typedef boost::array<std::size_t,Dimensions::dimensions>  data_type;
    typedef containers::container
            < typename boost::proto::nullary_expr < tag::extent_
                                                  , data_type
                                                  >::type
            , tag::extent_
            , descriptor_type
            >                                                 type;
  };
} }

#endif
