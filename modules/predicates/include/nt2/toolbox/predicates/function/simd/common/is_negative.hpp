//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_NEGATIVE_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_NEGATIVE_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/shrai.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::is_negative_, tag::cpu_,
                              (A0)(X),
                              ((simd_<arithmetic_<A0>,X>))
                             )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      return is_ltz(a0);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::is_negative_, tag::cpu_,
                              (A0)(X),
                              ((simd_<unsigned_<A0>,X>))
                             )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      ignore_unused(a0);
      return False<A0>();
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::is_negative_, tag::cpu_,
                              (A0)(X),
                              ((simd_<real_<A0>,X>))
                             )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      typedef typename meta::as_integer<A0, signed>::type type;
      const int32_t nb =  sizeof(typename meta::scalar_of <A0>::type)*8-1;
      return simd::native_cast<A0>(shrai(simd::native_cast<type>(a0), nb));
      //     return simd::native_cast<A0>(is_nez(simd::native_cast<type>(b_and(a0, Signmask<A0>()))));
    }
  };
} }
#endif
