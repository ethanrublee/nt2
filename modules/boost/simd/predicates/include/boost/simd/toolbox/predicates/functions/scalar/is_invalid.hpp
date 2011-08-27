//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SCALAR_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SCALAR_IS_INVALID_HPP_INCLUDED
#include <boost/dispatch/details/ignore_unused.hpp>
#include <boost/simd/include/functions/is_nan.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_invalid_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      return boost::simd::False<A0>();
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_invalid_, tag::cpu_
                            , (A0)
                            , (scalar_< real_<A0> >)
                            )
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
       return boost::simd::is_nan(a0-a0);
    }
  };
} } }


#endif
