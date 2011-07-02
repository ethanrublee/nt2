//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_COMMON_COMMA_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_COMMON_COMMA_HPP_INCLUDED

#include <nt2/sdk/details/type_id.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>
#include <iostream>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::comma_,tag::cpu_ , (A0)(A1)
                            , (generic_<fundamental_<A0> >)
                              (generic_<fundamental_<A1> >)
                            )
  {
    typedef A1 result_type;
    NT2_FUNCTOR_CALL(2) { ignore_unused(a0); return a1;}
  };
} }

#endif
