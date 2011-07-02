//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_NEGIF_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_NEGIF_HPP_INCLUDED

#include <nt2/include/functions/is_true.hpp>

#ifdef BOOST_MSVC
  #pragma warning(push)
  #pragma warning(disable: 4146) // unary minus applied to unsigned
#endif

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::negif_, tag::cpu_, (A0)(A1)
                            , (scalar_< fundamental_<A0> >)
                              (scalar_< fundamental_<A1> >)
                            )
  {
    typedef typename meta::result_of<meta::arithmetic(A1)>::type result_type;
    NT2_FUNCTOR_CALL(2) { return is_true(a0)?-a1:a1; }
  };
} }

#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif

#endif
