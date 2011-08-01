////////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
////////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_SIZE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_SIZE_HPP_INCLUDED

#include <nt2/sdk/meta/fusion.hpp>
#include <nt2/core/functions/size.hpp>
#include <nt2/core/settings/storage_kind.hpp>
#include <nt2/core/container/details/block/category.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is a block value
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::size_, tag::cpu_
                            , (A0)(Storage)
                            , ((block_< scalar_< arithmetic_<A0> >,Storage>))
                            )
  {
    typedef typename A0::sizes_type result_type;
    NT2_FUNCTOR_CALL(1) { return a0.sizes(); }
  };
} }

#endif
