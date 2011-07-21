//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_LOAD_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// load for no SIMD types
////////////////////////////////////////////////////////////////////////////////
#include <boost/dispatch/meta/mpl.hpp>
#include <boost/simd/sdk/simd/category.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <cstring>

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::load_, tag::cpu_
                            , (A0)(A1)(A2)(X)
                            , (iterator_<scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< fundamental_<A2>, X > >))
                            )
  {
    typedef typename A2::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL(3)
    {
      result_type that;
      std::memcpy ( &that
                  , reinterpret_cast<result_type const*>(a0) + a1
                  , sizeof that
                  );
      return that;
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::load_, tag::cpu_
                            , (A0)(A1)(A2)(A3)(X)
                            , (iterator_<scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< fundamental_<A2>, X > >))
                              (mpl_integral_< scalar_< integer_<A3> > >)
                            )
  {
    typedef typename A2::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL(4)
    {
      result_type that;
      std::memcpy ( &that
                  , reinterpret_cast<result_type const*>(a0 + A3::value) + a1
                  , sizeof that
                  );
      return that;
    }
  };
} } }

#endif
