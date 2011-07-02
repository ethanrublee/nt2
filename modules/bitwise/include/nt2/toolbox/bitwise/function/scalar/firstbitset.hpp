//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_FIRSTBITSET_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_FIRSTBITSET_HPP_INCLUDED

#include <nt2/sdk/meta/as_bits.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/functions/firstbitunset.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::firstbitset_, tag::cpu_, (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef typename meta::as_integer<A0, unsigned>::type result_type;
    NT2_FUNCTOR_CALL(1) { return a0 & (~a0+One<A0>()); }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::firstbitset_, tag::cpu_, (A0)
                            , (scalar_< real_<A0> >)
                            )
  {
    typedef typename meta::as_integer<A0, unsigned>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::as_bits<A0, signed>::type type;
      type that = {a0};
      return firstbitset(that.bits);
    }
  };
} }

#endif
