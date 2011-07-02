//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_COMPARE_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_COMPARE_EQUAL_HPP_INCLUDED

#include <nt2/include/functions/is_equal.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::compare_equal_, tag::cpu_
                            , (A0)
                            , ((simd_<double_<A0>,tag::sse_>))
                              ((simd_<double_<A0>,tag::sse_>))
                            )
  {
    typedef bool result_type;
    NT2_FUNCTOR_CALL_REPEAT(2) { return _mm_movemask_pd(eq(a0,a1)) == 0X03; }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::compare_equal_, tag::cpu_
                            , (A0)
                            , ((simd_<float_<A0>,tag::sse_>))
                              ((simd_<float_<A0>,tag::sse_>))
                            )
  {
    typedef bool result_type;
    NT2_FUNCTOR_CALL_REPEAT(2) { return _mm_movemask_ps(eq(a0,a1)) == 0X0F; }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::compare_equal_, tag::cpu_
                            , (A0)
                            , ((simd_<integer_<A0>,tag::sse_>))
                              ((simd_<integer_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm_movemask_epi8(eq(a0,a1)) == 0X0FFFF;
    }
  };
} }

#endif
