//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_BITWISE_SELECT_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_BITWISE_SELECT_HPP_INCLUDED

#include <nt2/include/functions/bitwise_andnot.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::bitwise_select_, tag::cpu_, (A0)(A1)(A2)
                            , (scalar_< fundamental_<A0> >)
                              (scalar_< fundamental_<A1> >)
                              (scalar_< fundamental_<A2> >)
                               )
  {
    typedef A1 result_type;
    NT2_FUNCTOR_CALL(3) { return b_or(b_and(a1, a0), b_andnot(a2, a0)); }
  };
} }

#endif
