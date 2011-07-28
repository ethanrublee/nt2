//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DETAILS_EPS_RELATED_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DETAILS_EPS_RELATED_HPP_INCLUDED

#include <boost/simd/sdk/meta/from_bits.hpp>
#include <boost/simd/include/functions/splat.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>

#define LOCAL_CONST(TAG, D, F, I)                                     \
BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( TAG,tag::cpu_,(A0)                        \
                          , (target_< scalar_< arithmetic_<A0> > > )  \
                          )                                           \
{                                                                     \
  typedef typename A0::type result_type;                              \
  BOOST_DISPATCH_FUNCTOR_CALL(1)                                                 \
  {                                                                   \
    ignore_unused(a0);                                                \
    return boost::simd::splat<result_type>(I);                                     \
  }                                                                   \
};                                                                    \
                                                                      \
BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( TAG,tag::cpu_,(A0)                        \
                          , (target_< scalar_< double_<A0> > > )      \
                          )                                           \
{                                                                     \
  typedef typename A0::type result_type;                              \
  BOOST_DISPATCH_FUNCTOR_CALL(1)                                                 \
  {                                                                   \
    typename boost::simd::meta::from_bits<result_type>::type const that = {D};     \
    return boost::simd::splat<result_type>(that.value);                            \
  }                                                                   \
};                                                                    \
                                                                      \
BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( TAG,tag::cpu_,(A0)                        \
                          , (target_< scalar_< float_<A0> > > )       \
                          )                                           \
{                                                                     \
  typedef typename A0::type result_type;                              \
  BOOST_DISPATCH_FUNCTOR_CALL(1)                                                 \
  {                                                                   \
    typename boost::simd::meta::from_bits<result_type>::type const that = {F};     \
    return boost::simd::splat<result_type>(that.value);                            \
  }                                                                   \
};                                                                    \
/**/

//==============================================================================
// Overloads for EPS related constants
//==============================================================================
namespace boost { namespace dispatch { namespace meta
{
  LOCAL_CONST(boost::simd::tag::eps__            ,0x3cb0000000000000LL,0X34000000,1);
  LOCAL_CONST(boost::simd::tag::half_eps__       ,0x3ca0000000000000ll,0x33800000,1);
  LOCAL_CONST(boost::simd::tag::_3_x_eps_        ,0x3CC8000000000000ll,0x34c00000,1);
  LOCAL_CONST(boost::simd::tag::sqrt_eps_        ,0x3e50000000000000ll,0x39b504f3,3);
  LOCAL_CONST(boost::simd::tag::forth_root_eps_  ,0x3f20000000000000ll,0x3c9837f0,1);
  LOCAL_CONST(boost::simd::tag::third_root_eps_  ,0x3ed965fea53d6e42ll,0x3ba14518,1);
  LOCAL_CONST(boost::simd::tag::mlog_eps_2_      ,0x403205966f2b4f13ll,0x40ff1402,0);
  LOCAL_CONST(boost::simd::tag::min_denormal_    ,0x1ll               ,0x1       ,1);
  LOCAL_CONST(boost::simd::tag::smallest_pos_val_,0x0010000000000000LL,0x00800000,1);
} } }

#undef LOCAL_CONST

#endif
