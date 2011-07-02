//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_HYPERBOLIC_FUNCTION_SCALAR_ACOSH_HPP_INCLUDED
#define NT2_TOOLBOX_HYPERBOLIC_FUNCTION_SCALAR_ACOSH_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/constants/real.hpp>

#include <nt2/include/functions/minusone.hpp>
#include <nt2/include/functions/log1p.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/oneminus.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::acosh_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::acosh(result_type(a0));
    }
  };
  
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is real_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(tag::acosh_, tag::cpu_,
			     (A0),
			     (scalar_< real_<A0> > )
			     )
  {
    typedef A0 result_type; 
    
    NT2_FUNCTOR_CALL(1)
      {
	if (a0 < One<A0>()) return Nan<A0>();
	if (a0 == Inf<A0>()) return a0;
	A0 t = minusone(a0);
	if (t < 16*Sqrteps<A0>()) return sqrt(Two<A0>()*t)*(oneplus(t/12+3*sqr(t)/160));
	return nt2::log1p(t+nt2::sqrt((t+t)+sqr(t)));
      }
  };
} }

#endif
