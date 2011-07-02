//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_SWAR_FUNCTION_SIMD_SSE_SSE2_SPLIT_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTION_SIMD_SSE_SSE2_SPLIT_HPP_INCLUDED

#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/templatize.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/constants/digits.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::split_, tag::cpu_, (A0)
                            , ((simd_<arithmetic_<A0>,tag::sse_>))
                            )
  {
    typedef typename meta::scalar_of<A0>::type                            stype;
    typedef typename meta::upgrade<stype>::type                           utype;
    typedef simd::native<utype,tag::sse_>                                 ttype;
    typedef meta::is_floating_point<stype>                                 rtag;
    typedef simd::native<typename  meta::double__<A0>::type,tag::sse_>    dtype;

    typedef typename boost::mpl::if_c<rtag::value,dtype,ttype>::type      rtype;
    typedef boost::fusion::tuple<rtype,rtype>                       result_type;

    NT2_FUNCTOR_CALL(1)
    {
      result_type res;

      eval( a0
          , boost::fusion::at_c<0>(res)
          , boost::fusion::at_c<1>(res)
          , rtype()
          );
      return res;
    }

    private:
    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::int16_t_<A0>::type,tag::sse_>&)const
    {
      typedef simd::native<typename  meta::int16_t_<A0>::type,tag::sse_> rtype;
      r1 = simd::native_cast<rtype>(_mm_unpackhi_epi8(a0, is_ltz(a0)));
      r0 = simd::native_cast<rtype>(_mm_unpacklo_epi8(a0, is_ltz(a0)));
    }
    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::uint16_t_<A0>::type,tag::sse_ > &)const
    {
      typedef simd::native<typename  meta::uint16_t_<A0>::type,tag::sse_> rtype;
      r1 = simd::native_cast<rtype>(_mm_unpackhi_epi8(a0, Zero<A0>()));
      r0 = simd::native_cast<rtype>(_mm_unpacklo_epi8(a0, Zero<A0>()));
    }
    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::int32_t_<A0>::type,tag::sse_ > &)const
    {
      typedef simd::native<typename  meta::int32_t_<A0>::type,tag::sse_> rtype;
      r1 = simd::native_cast<rtype>(_mm_unpackhi_epi16(a0, is_ltz(a0)));
      r0 = simd::native_cast<rtype>(_mm_unpacklo_epi16(a0, is_ltz(a0)));
    }
    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::uint32_t_<A0>::type,tag::sse_ > &)const
    {
      typedef simd::native<typename  meta::uint32_t_<A0>::type,tag::sse_> rtype;
      r1 = simd::native_cast<rtype>(_mm_unpackhi_epi16(a0, Zero<A0>()));
      r0 = simd::native_cast<rtype>(_mm_unpacklo_epi16(a0, Zero<A0>()));
    }
    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::int64_t_<A0>::type,tag::sse_ > &)const
    {
      typedef simd::native<typename  meta::int64_t_<A0>::type,tag::sse_> rtype;
      r1 = simd::native_cast<rtype>(_mm_unpackhi_epi32(a0, is_ltz(a0)));
      r0 = simd::native_cast<rtype>(_mm_unpacklo_epi32(a0, is_ltz(a0)));
    }
    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::uint64_t_<A0>::type,tag::sse_ > &)const
    {
      typedef simd::native<typename  meta::uint64_t_<A0>::type,tag::sse_> rtype;
      r1 = simd::native_cast<rtype>(_mm_unpackhi_epi32(a0, Zero<A0>()));
      r0 = simd::native_cast<rtype>(_mm_unpacklo_epi32(a0, Zero<A0>()));
    }

    template<class R0,class R1> inline void
    eval(A0 const& a0, R0& r0, R1& r1, const simd::native<typename  meta::double__<A0>::type,tag::sse_> &)const
    {
      typedef simd::native<typename meta::int32_t_<A0>::type,tag::sse_> itype;
      r1 = simd::native_cast<R1>(_mm_cvtps_pd(simd::native_cast<A0>(_mm_srli_si128( simd::native_cast<itype>(a0), 8))));
      r0 = simd::native_cast<R0>(_mm_cvtps_pd(a0));
    }
  };
} }

#endif
