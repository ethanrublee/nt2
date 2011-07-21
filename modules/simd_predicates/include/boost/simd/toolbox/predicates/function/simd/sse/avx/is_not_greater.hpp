//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_AVX_IS_NOT_GREATER_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_AVX_IS_NOT_GREATER_HPP_INCLUDED
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/details/simd/sse/sse4_1/is_not_greater.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::is_not_greater_, tag::cpu_,
                         (A0),
                         ((simd_<arithmetic_<A0>,tag::avx_>))
                         ((simd_<arithmetic_<A0>,tag::avx_>))
                        )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      return ~boost::simd::is_gt(a0, a1);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::is_not_greater_, tag::cpu_,
                         (A0),
                         ((simd_<double_<A0>,tag::avx_>))
                         ((simd_<double_<A0>,tag::avx_>))
                        )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = {_mm256_cmp_pd(a0,a1, _CMP_NGT_UQ)};
      return that;
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////


  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::is_not_greater_, tag::cpu_,
                         (A0),
                         ((simd_<float_<A0>,tag::avx_>))
                         ((simd_<float_<A0>,tag::avx_>))
                        )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = {_mm256_cmp_ps(a0,a1, _CMP_NGT_UQ)};
      return that;
    }
  };
} } }
#endif
