//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_SHIFT_RIGHT_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_SHIFT_RIGHT_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// operator binary shift right
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/sdk/meta/as_unsigned.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>
#include <nt2/sdk/simd/native_cast.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::shift_right_, tag::cpu_, (A0)(A1)
                            , ((simd_<integer_<A0>,tag::altivec_>))
                              ((simd_<integer_<A1>,tag::altivec_>))
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2)  
    { 
     typedef typename meta::as_unsigned<A1>::type type;
     type shift = simd::native_cast<type>(a1);
     A0 that = { vec_sr(a0(), shift()) }; 
     return that; 
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::shift_right_, tag::cpu_, (A0)(A1)
                            , ((simd_<float_<A0>,tag::altivec_>))
                              ((simd_<ints32_<A1>,tag::altivec_>))
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2) 
   { 
     typedef typename meta::as_unsigned<A1>::type type;
     type shift = simd::native_cast<type>(a1);
     type value = simd::native_cast<type>(a0);
     A0 that = simd::native_cast<A0>( vec_sr(value(), shift()) ); 
     return that;  
   }
  };
} }

#endif
