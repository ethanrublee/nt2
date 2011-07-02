//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_STORE_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_STORE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// store for SIMD types
// TODO : Documentation for simd store
// TODO : Make them work properly with ContiguousRandomAccessIterator
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/memory/details/category.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::store_, tag::cpu_, (A0)(A1)(A2)
                            , ((simd_< arithmetic_<A0>, tag::altivec_ >))
                              (iterator_< arithmetic_<A1> >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(3)
    {
      vec_st(a0.data_, a2*16, a1);
      return a0;
    }
  };
} }

#endif
