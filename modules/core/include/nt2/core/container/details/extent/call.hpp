//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_CALL_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_CALL_HPP_INCLUDED

#include <nt2/sdk/meta/as.hpp>
#include <nt2/sdk/dsl/compute.hpp>
#include <nt2/sdk/dsl/category.hpp>

namespace nt2 { namespace meta
{
  //============================================================================
  // extent terminals computes like terminals
  //============================================================================
  template<class Target>
  struct  compute<tag::extent_,Target>
        : boost::proto::
          call< functor < tag::extent_
                        , Target
                        > ( boost::proto::_value
                          , boost::proto::_state
                          , boost::proto::_data
                          )
              >
  {};

  //============================================================================
  // Register terminal handlers for extent terminals
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION_TPL( tag::extent_,tag::cpu_
                                , (class A0)(class A1)(class A2)(std::size_t N)
                                , ((array_<scalar_< arithmetic_<A0> >,N>))
                                  (target_< unspecified_<A1> >)
                                  (scalar_< integer_<A2> >)
                                )
  {
    typedef typename A0::value_type result_type;
    
    inline result_type operator()( A0& v, A1&, A2& pos) const
    {
      return v[pos];
    }
  };
  
  //============================================================================
  // Register terminal handlers for extent terminals - _0D cases
  //============================================================================
  template<class A0, class A1, class A2, class Dummy>
  struct implement< tag::extent_
                    ( array_<scalar_< arithmetic_<A0> >,0>
                    , target_< unspecified_<A1> >
                    , scalar_< integer_<A2> >
                    )
                  , tag::cpu_,Dummy
                  >
  {
    typedef typename A0::value_type result_type;
    
    template<class Target>
    inline result_type operator()( A0&, Target&, A2&) const
    {
      return 1;
    }
  };
} }

#endif
