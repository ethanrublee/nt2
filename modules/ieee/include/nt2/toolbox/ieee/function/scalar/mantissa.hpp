//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_MANTISSA_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_MANTISSA_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_invalid.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::mantissa_, tag::cpu_
                            , (A0)
                            , (scalar_< fundamental_<A0> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
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
} }


#endif
