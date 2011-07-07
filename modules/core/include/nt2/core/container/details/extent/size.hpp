//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_SIZE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_SIZE_HPP_INCLUDED

#include <nt2/sdk/meta/fusion.hpp>
#include <nt2/core/functions/size.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION_TPL( tag::size_, tag::cpu_
                                , (class A0)(std::size_t N)
                                , ((array_<scalar_< arithmetic_<A0> >,N>))
                                )
  {
    typedef containers::extent< of_size_<1,(N>=2 ? N : 2)> > result_type;

    NT2_FUNCTOR_CALL(1)
    {
      result_type that;
      return that;
    }
  };
} }

#endif
