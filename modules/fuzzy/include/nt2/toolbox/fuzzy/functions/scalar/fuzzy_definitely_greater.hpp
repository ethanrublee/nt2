//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTIONS_SCALAR_FUZZY_DEFINITELY_GREATER_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTIONS_SCALAR_FUZZY_DEFINITELY_GREATER_HPP_INCLUDED

#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/max.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::fuzzy_definitely_greater_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)(scalar_< arithmetic_<A2> >)
                            )
  {

    typedef bool result_type;

    NT2_FUNCTOR_CALL(3)
    {
       return a0 > a1+a2*nt2::max(nt2::abs(a0),nt2::abs(a1));
    }
  };
} }


#endif
