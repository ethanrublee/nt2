//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_RDIVIDE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_RDIVIDE_HPP_INCLUDED
#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/simd/include/constants/digits.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/is_eqz.hpp>
#include <boost/simd/include/functions/group.hpp>
#include <boost/simd/include/functions/split.hpp>
#include <boost/simd/include/functions/toint.hpp>
#include <boost/simd/include/functions/tofloat.hpp>
#include <boost/simd/include/functions/select.hpp>

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::rdivide_, tag::cpu_, (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                              ((simd_<arithmetic_<A0>,X>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      using boost::simd::One;

      const A0 iseqza1 = is_eqz(a1);
      return (a0-(iseqza1&a0))/(a1+(iseqza1&One<A0>()));
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::rdivide_, tag::cpu_, (A0)(X)
                            , ((simd_<int8_<A0>,X>))
                              ((simd_<int8_<A0>,X>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename meta::scalar_of<A0>::type  stype;
      typedef typename meta::upgrade<stype>::type itype;
      typedef simd::native<itype, X>              ivtype;
      ivtype a0l, a0h, a1l, a1h;

      boost::fusion::tie(a0l, a0h) = split(a0);
      boost::fusion::tie(a1l, a1h) = split(a1);
      return simd::native_cast<A0>(group( boost::simd::rdivide(a0l, a1l)
                                        , boost::simd::rdivide(a0h, a1h) ));
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::rdivide_, tag::cpu_, (A0)(X)
                            , ((simd_<int16_<A0>,X>))
                              ((simd_<int16_<A0>,X>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      using namespace boost::simd;

      typedef typename meta::scalar_of<A0>::type    stype;
      typedef typename meta::upgrade<stype>::type   itype;
      typedef simd::native<itype,X>                 ivtype;
      ivtype a0l, a0h, a1l, a1h;

      boost::fusion::tie(a0l, a0h) = split(a0);
      boost::fusion::tie(a1l, a1h) = split(a1);

      return sel( is_eqz(a1),
                  Zero<A0>(),
                  simd::native_cast<A0>( group( toint(tofloat(a0l)/tofloat(a1l))
                                              , toint(tofloat(a0h)/tofloat(a1h))
                                              )
                                       )
                );
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::rdivide_, tag::cpu_, (A0)(X)
                            , ((simd_<real_<A0>,X>))
                              ((simd_<real_<A0>,X>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      return b_or(b_and(is_eqz(a0), is_eqz(a1)), a0/a1);
    }
  };
} } }

#endif
