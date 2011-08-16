//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SIMD_COMMON_MAXNUM_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SIMD_COMMON_MAXNUM_HPP_INCLUDED
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/max.hpp>
#include <boost/simd/include/functions/select.hpp>
#include <boost/simd/include/functions/is_nan.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::maxnum_, tag::cpu_,
                         (A0)(X),
                         ((simd_<arithmetic_<A0>,X>))
                         ((simd_<arithmetic_<A0>,X>))
                        )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::max(a0, a1);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////


  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::maxnum_, tag::cpu_,
                         (A0)(X),
                         ((simd_<real_<A0>,X>))
                         ((simd_<real_<A0>,X>))
                        )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      const A0 a = select(is_nan(a0),a1,a0);
      const A0 b = select(is_nan(a1),a0,a1);
      return boost::simd::max(a, b);
    }
  };
} } }
#endif
