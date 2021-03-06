//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_SSSE3_ABS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_SSSE3_ABS_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSSE3_SUPPORT
#include <boost/simd/include/constants/real.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/include/constants/digits.hpp>
#include <boost/simd/include/constants/properties.hpp>
#include <boost/simd/include/functions/select.hpp>
#include <boost/simd/include/functions/is_lez.hpp>
#include <boost/simd/include/functions/bitwise_notand.hpp>
#include <boost/simd/include/functions/shri.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int32_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::abs_, boost::simd::tag::ssse3_
                            , (A0)
                            , ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    { A0 that = {_mm_abs_epi32(a0) }; return that; }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int8_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::abs_, boost::simd::tag::ssse3_
                            , (A0)
                            , ((simd_<int8_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    { A0 that = {_mm_abs_epi8(a0) }; return that; }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int16_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::abs_, boost::simd::tag::ssse3_
                            , (A0)
                            , ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    { A0 that = {_mm_abs_epi16(a0) };return that; }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is floating_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::abs_, boost::simd::tag::ssse3_
                            , (A0)
                            , ((simd_<floating_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    { return b_notand(boost::simd::Mzero<A0>(),a0); }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int64_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::abs_, boost::simd::tag::ssse3_
                            , (A0)
                            , ((simd_<int64_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
       typedef typename dispatch::meta::as_integer<A0, signed>::type int_type;
       typedef typename meta::scalar_of<int_type>::type   sint_type;
       A0 const s = shri(a0, 8*sizeof(sint_type)-1);
       return (a0-s)^(-s);
       //      return select(is_lez(a0),-a0,a0);
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::abs_, boost::simd::tag::ssse3_
                            , (A0)
                            , ((simd_<unsigned_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    { return a0; }
  };
} } }


#endif
#endif
