//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_REDUCTION_FUNCTION_SIMD_SSE_SSSE3_SUM_HPP_INCLUDED
#define NT2_TOOLBOX_REDUCTION_FUNCTION_SIMD_SSE_SSSE3_SUM_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/first.hpp>
#include <nt2/include/functions/second.hpp>
#include <boost/fusion/include/fold.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int16_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::sum_, tag::cpu_,
                      (A0),
                      ((simd_<ints16_<A0>,tag::sse_>))
                     )
  {
      typedef typename meta::scalar_of<A0>::type                 base;
      typedef typename meta::result_of<meta::arithmetic(base)>::type  result_type;
    
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      A0 tmp = {_mm_hadd_epi16(a0, a0)};
      A0 tmp1 = {_mm_hadd_epi16(tmp, tmp)};
      return  first(simd::native_cast<A0>(_mm_hadd_epi16(tmp1, tmp1)));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::sum_, tag::cpu_,
                      (A0),
                      ((simd_<double_<A0>,tag::sse_>))
                     )
  {
      typedef typename meta::scalar_of<A0>::type                 base;
      typedef typename meta::result_of<meta::arithmetic(base)>::type  result_type;
    
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      return first(simd::native_cast<A0>(_mm_hadd_pd( a0, Zero<A0>())));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int64_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::sum_, tag::cpu_,
                      (A0),
                      ((simd_<ints64_<A0>,tag::sse_>))
                     )
  {
      typedef typename meta::scalar_of<A0>::type                 base;
      typedef typename meta::result_of<meta::arithmetic(base)>::type  result_type;
    
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      return first(a0)+second(a0);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::sum_, tag::cpu_,
                      (A0),
                      ((simd_<float_<A0>,tag::sse_>))
                     )
  {
      typedef typename meta::scalar_of<A0>::type                 base;
      typedef typename meta::result_of<meta::arithmetic(base)>::type  result_type;
    
    NT2_FUNCTOR_CALL(1)
    {
      A0 tmp = {_mm_hadd_ps(a0, Zero<A0>())};
      return  first(simd::native_cast<A0>(_mm_hadd_ps(tmp, Zero<A0>())));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int8_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::sum_, tag::cpu_,
                      (A0),
                      ((simd_<ints8_<A0>,tag::sse_>))
                     )
  {
      typedef typename meta::scalar_of<A0>::type                 base;
      typedef typename meta::result_of<meta::arithmetic(base)>::type  result_type;
    
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      return boost::fusion::fold(a0,0,functor<tag::plus_>());
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int32_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::sum_, tag::cpu_,
                      (A0),
                      ((simd_<ints32_<A0>,tag::sse_>))
                     )
  {
      typedef typename meta::scalar_of<A0>::type                 base;
      typedef typename meta::result_of<meta::arithmetic(base)>::type  result_type;
    
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      A0 tmp = {_mm_hadd_epi32(a0, a0)};
      return  first(simd::native_cast<A0>(_mm_hadd_epi32(tmp, tmp)));
    }
  };
} }
#endif
