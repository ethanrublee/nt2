//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_IEEE_FUNCTION_SCALAR_MANTISSA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_IEEE_FUNCTION_SCALAR_MANTISSA_HPP_INCLUDED
#include <boost/dispatch/meta/adapted_traits.hpp>
#include <boost/simd/include/constants/properties.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/is_invalid.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::mantissa_, tag::cpu_
                            , (A0)
                            , (scalar_< fundamental_<A0> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      using namespace boost::simd;
      //TO DO incorrect
      if(!a0) return a0;
      if(is_invalid(a0)) return a0; 
      typedef typename meta::as_integer<A0, unsigned>::type int_type;
      static const int_type n1 = (((Maxexponent<A0>()<<1)+1)<< Nbmantissabits<A0>());
      static const int_type n2 = (sizeof(int_type)-2);
      static const int_type mask0 = ((n1<<2)>>2);
      static const int_type mask1 = ((~n1)|n2);
      return b_or(b_and(a0, mask1),mask0);
    }
  };
} } }


#endif
