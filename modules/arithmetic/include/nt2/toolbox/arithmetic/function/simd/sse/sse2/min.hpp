//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_MIN_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_MIN_HPP_INCLUDED

#include <nt2/include/functions/seladd.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::min_, tag::cpu_, (A0)
                            , ((simd_<arithmetic_<A0>,tag::sse_>))
                              ((simd_<arithmetic_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
       return seladd(gt(a0,a1),a0,a1-a0);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::min_, tag::cpu_, (A0)
                            , ((simd_<double_<A0>,tag::sse_>))
                              ((simd_<double_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  {_mm_min_pd(a0,a1)}; return that;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::min_, tag::cpu_
                            , (A0)
                            , ((simd_<float_<A0>,tag::sse_>))((simd_<float_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  {_mm_min_ps(a0,a1)}; return that;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::min_, tag::cpu_
                            , (A0)
                            , ((simd_<int16_<A0>,tag::sse_>))((simd_<int16_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  { _mm_min_epi16(a0,a1)}; return that;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::min_, tag::cpu_
                            , (A0)
                            , ((simd_<uint8_<A0>,tag::sse_>))((simd_<uint8_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
         A0 that =  {_mm_min_epu8(a0,a1)}; return that;
    }
  };
} }

#endif
