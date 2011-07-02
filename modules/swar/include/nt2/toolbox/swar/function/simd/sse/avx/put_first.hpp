//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_SWAR_FUNCTION_SIMD_SSE_AVX_PUT_FIRST_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTION_SIMD_SSE_AVX_PUT_FIRST_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/templatize.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/details/simd/sse/sse4_1/put_first.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::put_first_, tag::cpu_,
                            (A0),
                            ((simd_<arithmetic_<A0>,tag::avx_>))
                            ((simd_<arithmetic_<A0>,tag::avx_>))
                           )
  {
typedef A0 result_type; 
    NT2_FUNCTOR_CALL_REPEAT(2){return a0; }
  };
} }
#endif
