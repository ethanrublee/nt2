//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_SSE_SSE2_SHRAI_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_SSE_SSE2_SHRAI_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_gtz.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/group.hpp>
#include <nt2/include/functions/split.hpp>
#include <nt2/include/functions/make.hpp>

#include <nt2/toolbox/bitwise/function/simd/common/shrai.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::shrai_, tag::cpu_
                            , (A0)(A1)
                            , ((simd_<int32_<A0>,tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_integer<A0,signed>::type sint;
      sint const that = {_mm_srai_epi32(simd::native_cast<sint>(a0), a1)};
      return simd::native_cast<A0>(that);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::shrai_, tag::cpu_
                            , (A0)(A1)
                            , ((simd_<int16_<A0>,tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_integer<A0,signed>::type sint;
      sint const that =  {_mm_srai_epi16(simd::native_cast<sint>(a0), a1)};
      return simd::native_cast<A0>(that);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::shrai_, tag::cpu_
                            , (A0)(A1)
                            , ((simd_<int8_<A0>,tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typedef simd::native<typename meta::int16_t_<A0>::type,tag::sse_> gen_type;
      gen_type a0h, a0l;
      boost::fusion::tie(a0l, a0h) = split(a0);
      return simd::native_cast<A0>(group(shrai(a0l, a1),shrai(a0h, a1)));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::shrai_, tag::cpu_
                            , (A0)(A1)
                            , ((simd_<int64_<A0>,tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return make<A0>(shrai(a0[0], a1), shrai(a0[1], a1));
    }
  };
} }

#endif
