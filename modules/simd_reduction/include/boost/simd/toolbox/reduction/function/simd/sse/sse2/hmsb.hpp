//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTION_SIMD_SSE_SSE2_HMSB_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTION_SIMD_SSE_SSE2_HMSB_HPP_INCLUDED
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::hmsb_, tag::cpu_,
                       (A0),
                       ((simd_<arithmetic_<A0>,tag::sse_>))
                      )
  {
      typedef typename meta::as_integer<typename meta::scalar_of<A0>::type>::type result_type;
      
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(1)
    {
      return _mm_movemask_epi8(a0);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::hmsb_, tag::cpu_,
                       (A0),
                       ((simd_<double_<A0>,tag::sse_>))
                      )
  {
      typedef typename meta::as_integer<typename meta::scalar_of<A0>::type>::type result_type;
      
    BOOST_DISPATCH_FUNCTOR_CALL(1){ return _mm_movemask_pd(a0); }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////


  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::hmsb_, tag::cpu_,
                       (A0),
                       ((simd_<float_<A0>,tag::sse_>))
                      )
  {
      typedef typename meta::as_integer<typename meta::scalar_of<A0>::type>::type result_type;
      
    BOOST_DISPATCH_FUNCTOR_CALL(1){ return _mm_movemask_ps(a0); }
  };
} } }
#endif
