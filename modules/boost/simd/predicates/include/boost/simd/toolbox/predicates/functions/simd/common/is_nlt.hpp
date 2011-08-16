//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_COMMON_IS_NLT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_COMMON_IS_NLT_HPP_INCLUDED
#include <boost/dispatch/meta/strip.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_nlt_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return b_not(lt(a0,a1));
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is integer_
/////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH(boost::simd::tag::is_nlt_, tag::cpu_,
                         (A0)(X),
                         ((simd_<integer_<A0>,X>))
                         ((simd_<integer_<A0>,X>))
                        );

namespace boost { namespace simd { namespace ext
{
  template<class X, class Dummy>
  struct call<boost::simd::tag::is_nlt_(tag::simd_<tag::integer_, X> ,
                           boost::simd::tag::simd_<tag::integer_, X> ),
              boost::simd::tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0, A0)> : meta::strip<A0>{};//

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return ge(a0,a1);
    }
  };
} } }

#endif
