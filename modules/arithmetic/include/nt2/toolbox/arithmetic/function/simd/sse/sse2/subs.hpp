//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_SUBS_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_SUBS_HPP_INCLUDED

#include <nt2/toolbox/arithmetic/function/simd/common/subs.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is uint16_t
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::subs_, tag::cpu_,
                          (A0),
                          ((simd_<uint16_<A0>,tag::sse_>))
                          ((simd_<uint16_<A0>,tag::sse_>))
                         );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::subs_(tag::simd_<tag::uint16_, tag::sse_>,
                            tag::simd_<tag::uint16_, tag::sse_>),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> 
      : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return simd::native_cast<A0>(_mm_subs_epu16(a0, a1)); 
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int16_t
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::subs_, tag::cpu_,
                          (A0),
                          ((simd_<int16_<A0>,tag::sse_>))
                          ((simd_<int16_<A0>,tag::sse_>))
                         );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::subs_(tag::simd_<tag::int16_, tag::sse_>,
                            tag::simd_<tag::int16_, tag::sse_>),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> 
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
      return simd::native_cast<A0>(_mm_subs_epi16(a0, a1)); 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is uint8_t
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::subs_, tag::cpu_,
                          (A0),
                          ((simd_<uint8_<A0>,tag::sse_>))
                          ((simd_<uint8_<A0>,tag::sse_>))
                         );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::subs_(tag::simd_<tag::uint8_, tag::sse_>,
                            tag::simd_<tag::uint8_, tag::sse_>),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>  : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return simd::native_cast<A0>(_mm_subs_epu8(a0, a1)); 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int8_t
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::subs_, tag::cpu_,
                          (A0),
                          ((simd_<int8_<A0>,tag::sse_>))
                          ((simd_<int8_<A0>,tag::sse_>))
                         );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::subs_(tag::simd_<tag::int8_, tag::sse_>,
                            tag::simd_<tag::int8_, tag::sse_>),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>  : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return simd::native_cast<A0>(_mm_subs_epi8(a0, a1)); 
    }
  };
} }

#endif

