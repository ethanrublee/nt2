//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DSL_GRAMMAR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_GRAMMAR_HPP_INCLUDED

/*!
 * \file
 * \brief Implements grammar for containers expression matching
 */

#include <boost/simd/sdk/constant/category.hpp>
#include <nt2/sdk/meta/is_hierarchized.hpp>
#include <nt2/core/container/dsl/forward.hpp>
#include <nt2/core/container/meta/is_container.hpp>
#include <nt2/sdk/dsl/is_assignment_expression.hpp>

namespace nt2 { namespace containers
{
  //============================================================================
  // Anything goes in the grammar except for low level operators
  //============================================================================
  template<class Tag>
  struct  grammar
        : boost::proto
        ::or_ <
              //  Terminals are containers-tagged type and hierarchized values
                boost::proto::
                and_< boost::proto::nullary_expr<boost::proto::_,boost::proto::_>
                    , boost::proto::if_ < meta::
                                          is_container<boost::proto::_expr>()
                                       >
                   >
              , boost::proto::
                and_< boost::proto::terminal<boost::proto::_>
                    , boost::proto::if_ < meta::
                                          is_hierarchized<boost::proto::_value>()
                                        >
                    >
              //  Nodes are any non-low level or non assignment nodes
              , boost::proto::
                and_< boost::proto::
                      nary_expr < boost::proto::_
                                , boost::proto::vararg< grammar<Tag> >
                                >
                    , boost::proto::
                      not_< boost::proto::or_ < boost::proto::
                                                address_of< grammar<Tag> >
                                              , boost::proto::
                                                dereference< grammar<Tag> >
                                              , meta::assignment_operators
                                              >
                          >
                    >
              > {};
} }

#endif
