//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_LOAD_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_LOAD_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// load for SSE2 SIMD types
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/meta/mpl.hpp>
#include <nt2/sdk/simd/category.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>

//==============================================================================
// load vector of double
//==============================================================================
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::load_ , tag::cpu_
                            , (A0)(A1)(A2)(X)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< double_<A2>, X > >))
                            )
  {
    typedef typename A2::type result_type;

    NT2_FUNCTOR_CALL(3)
    {
      ignore_unused(a2);
      result_type
      that = { _mm_load_pd(a0+a1*meta::cardinal_of<result_type>::value) };
      return that;
    }
  };
} }

//==============================================================================
// load vector of float
//==============================================================================
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::load_ , tag::cpu_
                            , (A0)(A1)(A2)(X)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< float_<A2>, X > >))
                            )
  {
    typedef typename A2::type result_type;

    NT2_FUNCTOR_CALL(3)
    {
      ignore_unused(a2);
      result_type
      that = { _mm_load_ps(a0+a1*meta::cardinal_of<result_type>::value) };
      return that;
    }
  };
} }

//==============================================================================
// load vector of integer
//==============================================================================
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::load_ , tag::cpu_
                            , (A0)(A1)(A2)(X)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< integer_<A2>,X > >))
                            )
  {
    typedef typename A2::type result_type;

    NT2_FUNCTOR_CALL(3)
    {
      ignore_unused(a2);
      result_type
      that = { _mm_load_si128(reinterpret_cast<__m128i const*>(a0)+a1) };
      return that;
    }
  };
} }


#include <nt2/toolbox/operator/function/simd/sse/sse2/load_offset.hpp>

#endif
