//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTIONS_SCALAR_KNUTH_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTIONS_SCALAR_KNUTH_EQUAL_HPP_INCLUDED

#include <nt2/include/functions/fast_ldexp.hpp>
#include <nt2/include/functions/exponent.hpp>
#include <nt2/include/functions/maxnummag.hpp>
#include <nt2/include/functions/abs.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::knuth_equal_, tag::cpu_
                            , (A0)
                            , (scalar_< real_<A0> >)(scalar_< real_<A0> >)(scalar_< real_<A0> >)
                            )
  {
    typedef bool result_type;
    NT2_FUNCTOR_CALL_REPEAT(3)
    {
      return nt2::abs(a0-a1) <= fast_ldexp(a2, exponent(maxnummag(a0, a1)));
    }
  };
} }


#endif
