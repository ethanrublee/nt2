//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE2_IS_GEZ_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE2_IS_GEZ_HPP_INCLUDED
#include <boost/simd/sdk/meta/templatize.hpp>
#include <boost/simd/include/functions/boolean.hpp>
#include <boost/simd/sdk/details/ignore_unused.hpp>
#include <boost/simd/include/constants/digits.hpp>
#include <boost/dispatch/meta/strip.hpp>

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::is_gez_, tag::cpu_, (A0)
                            , ((simd_<arithmetic_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(1) { return is_greater_equal(a0,Zero<A0>()); }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::is_gez_, tag::cpu_, (A0)
                            , ((simd_<unsigned_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      return True<A0>();
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::is_gez_, tag::cpu_,(A0)
                            , ((simd_<int64_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      typedef typename meta::int32_t_<A0>::type htype;
      typedef simd::native<htype,tag::sse_> type;
      const type tmp1 = is_gez(simd::native_cast<type>(a0));
      const type tmp = { _mm_shuffle_epi32(tmp1, _MM_SHUFFLE(3, 3, 1, 1))};
      return  simd::native_cast<A0>(tmp);
    }
  };
} } }

#endif
