//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SIMD_COMMON_ATAN_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SIMD_COMMON_ATAN_HPP_INCLUDED

#include <nt2/toolbox/trigonometric/functions/atan.hpp>
#include <nt2/toolbox/trigonometric/functions/simd/common/impl/invtrig.hpp>

#include <nt2/include/functions/tofloat.hpp>
#include <nt2/sdk/meta/as_real.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::atan_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename meta::as_real<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      const result_type r = { impl::invtrig_base<result_type,radian_tag, tag::simd_type>::atan(tofloat(a0)) }; 
      return r;
    }
  };
} }


#endif
