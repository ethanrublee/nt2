//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_IMPL_DIVIDES_FLOAT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_IMPL_DIVIDES_FLOAT_HPP_INCLUDED

#include <boost/simd/include/constants/digits.hpp>

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::divides_, tag::cpu_, (A0)
                            , ((simd_<float_<A0>,tag::altivec_>))
                              ((simd_<float_<A0>,tag::altivec_>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      result_type erb   = { vec_re(a1()) };
      result_type rec_b = { vec_madd( vec_nmsub(erb(), a1(), One<result_type>()())
                                    , erb()
                                    , erb()
                                    )
                          };
      result_type that  = { vec_madd(a0(),rec_b(),Zero<result_type>()()) };
      return that;
    }
  };
} } }

#endif
