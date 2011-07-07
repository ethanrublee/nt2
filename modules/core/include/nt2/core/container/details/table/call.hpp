/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_CALL_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_CALL_HPP_INCLUDED

#include <nt2/sdk/meta/as.hpp>
#include <nt2/sdk/dsl/compute.hpp>
#include <nt2/sdk/meta/fusion.hpp>
#include <nt2/sdk/dsl/category.hpp>

namespace nt2 { namespace meta
{
  ////////////////////////////////////////////////////////////////////////////////
  // table_ terminals computes like terminals
  ////////////////////////////////////////////////////////////////////////////////
  template<class Target>
  struct  compute<tag::table_,Target>
        : boost::proto::
          call< functor < tag::extent_
                        , Target
                        > ( boost::proto::_value
                          , boost::proto::_state
                          , boost::proto::_data
                          )
              >
  {};
}}

////////////////////////////////////////////////////////////////////////////////
// Register terminal handlers for extent terminals - Same size
////////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH (  tag::table_,tag::cpu_
                      , (A0)(Storage)(A1)(A2)
                      , ((heap_<arithmetic_<A0>,Storage>))
                        ((target_<unspecified_<A1> >))
                        (fusion_sequence_<A2>)
                      )

namespace nt2 { namespace ext
{
  template<class Storage, class Dummy>
  struct call<tag::extent_( tag::heap_<tag::arithmetic_,Storage>
                          , tag::target_< tag::unspecified_ >
                          , tag::fusion_sequence_
                          ),tag::cpu_,Dummy>
  : callable
  {
    template<class Sig> struct result;

    template<class This, class Value, class State, class Data>
    struct result<This(Value,State,Data)>
    {
      typedef typename meta::strip<Value>::type::value_type  type;
    };

    template<class Value, class State, class Data> inline
    typename result<call(Value,State,Data)>::type
    operator()( Value& v, State& , Data& pos) const
    {
      return v(pos);
    }
  };
} }

#endif