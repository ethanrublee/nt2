/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_META_IS_STATEMENT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_META_IS_STATEMENT_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Check if a given proto expression can be evaluated at once
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/dsl/is_assignment_expression.hpp>

namespace nt2 { namespace details
{
  struct statement_cases
  {
    template<class Tag> struct case_ : boost::proto::not_< boost::proto::_ > {};
  };

  template<>
  struct  statement_cases::case_< boost::proto::tag::comma >
        : boost::proto::_ {};
} }

namespace nt2 { namespace meta
{
  struct  statements
        : boost::proto::or_
          < boost::proto::switch_< details::assign_cases>
          , boost::proto::switch_< details::statement_cases>
          >
  {};

  template<class Expr>
  struct  is_statement
        : boost::proto::matches < Expr
                                , statements
                                >
  {};
} }

#endif
