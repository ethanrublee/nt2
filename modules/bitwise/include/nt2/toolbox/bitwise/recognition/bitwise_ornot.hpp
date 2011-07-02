/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_BITWISE_RECOGNITION_BITWISE_ORNOT_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_RECOGNITION_BITWISE_ORNOT_HPP_INCLUDED

#include <nt2/sdk/dsl/category.hpp>
#include <nt2/sdk/dsl/recognition.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/toolbox/bitwise/function/bitwise_ornot.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::bitwise_or_ , tag::recognition_
                            , (A0)(A1)(Dom)(Sema)
                            , (unspecified_<A0>)
                              ((expr_<A1,Dom,tag::complement_,Sema>))
                            )
  {
    typedef typename
            meta::call< tag::bitwise_ornot_ ( A0
                                            , typename boost::proto::result_of::
                                                      child_c<A1, 0>::type
                                            )
                      >::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return bitwise_ornot(a0, boost::proto::child_c<0>(a1));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION(tag::bitwise_or_ , tag::recognition_
                            , (A0)(A1)(Dom)(Sema)
                            , ((expr_<A0,Dom,tag::complement_,Sema>))
                              (unspecified_<A1>)
                            )
  {
    typedef typename
            meta::call< tag::bitwise_ornot_ ( A1
                                            , typename boost::proto::result_of::
                                                      child_c<A0, 0>::type
                                            )
                      >::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return bitwise_ornot(a1, boost::proto::child_c<0>(a0));
    }
  };
} }

#endif
