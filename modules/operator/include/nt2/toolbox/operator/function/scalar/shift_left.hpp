//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SCALAR_SHIFT_LEFT_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SCALAR_SHIFT_LEFT_HPP_INCLUDED

#include <nt2/sdk/meta/strip.hpp>
#include <nt2/sdk/meta/as_bits.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::shift_left_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< real_<A0> >)(scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(2)
    {
      typename meta::as_bits<A0>::type t0 = {a0};
      t0.bits = t0.bits << a1;
      return t0.value;
    }
  };
} }

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::shift_left_ , tag::cpu_
                            , (A0)(A1)
                            , (scalar_< integer_<A0> >)(scalar_< integer_<A1> >)
                            )
  {
    static A0& a0; static A1& a1;
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested,a0 << a1)
    typedef typename nested::type result_type;
    NT2_FUNCTOR_CALL(2) { return a0 << a1; }
  };
} }

#endif
