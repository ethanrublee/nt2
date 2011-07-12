/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_GENERATOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_GENERATOR_HPP_INCLUDED

namespace nt2 { namespace containers
{
  template<class Descriptor> struct generator<tag::extent_,Descriptor>
  {
    template<class Sig> struct result;
    template<class This, class Expr>
    struct result<This(Expr)>
    {
      typedef container<Expr,tag::extent_,Descriptor> type;
    };

    template<class Expr>
    typename result<generator(Expr)>::type const
    operator()(Expr const& xpr) const
    {
      typename result<generator(Expr)>::type const that(xpr);
      return that;
    }
  };
} }

#endif
