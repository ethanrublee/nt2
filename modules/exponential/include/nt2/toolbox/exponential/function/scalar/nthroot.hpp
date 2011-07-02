//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_NTHROOT_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_NTHROOT_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/functions/signnz.hpp>
#include <nt2/include/functions/pow.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/minusone.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/is_odd.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nthroot_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< integer_<A0> >)(scalar_< integer_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::nthroot(result_type(a0),a1);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nthroot_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< real_<A0> >)(scalar_< integer_<A1> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::result_of<meta::floating(A0)>::type type;
      if (!a1) return One<type>();
      if (!a0) return Zero<type>();
      bool is_ltza0 = is_ltz(a0); 
      if (!is_odd(a1) && is_ltza0) return Nan<type>(); 
      if (is_inf(a0)) return a0; 
      type aa1 = a1;
      type x = nt2::abs(a0); 
      type y = nt2::pow(x,rec(aa1));
      // Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
      // by one iteration of Newton's method
      if (y) y -= (nt2::pow(y, a1) - x) / (aa1* nt2::pow(y,minusone(a1)));
	  return (is_ltza0) ? -y : y;
    }
  };
} }


#endif
