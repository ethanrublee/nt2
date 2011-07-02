//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EULER_FUNCTION_SCALAR_GAMMALN_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTION_SCALAR_GAMMALN_HPP_INCLUDED

#include <nt2/toolbox/euler/details/math.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_invalid.hpp>
#include <boost/math/special_functions/gamma.hpp>

#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/functions/signnz.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type is double_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::gammaln_, tag::cpu_
                            , (A0)
                            , (scalar_< real_<A0> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      if ((a0 == Inf<A0>()) | is_eqz(a0) ) return Inf<A0>(); 
      if ((a0 < Zero<A0>()) | is_invalid(a0)) return Nan<A0>();
    #ifdef NT2_TOOLBOX_EULER_HAS_LGAMMA
      return ::lgamma(a0);
    #else
      return boost::math::lgamma(a0);
    #endif
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type is float_
/////////////////////////////////////////////////////////////////////////////
#ifdef NT2_TOOLBOX_EULER_HAS_LGAMMAF
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::gammaln_, tag::cpu_
                            , (A0)
                            , (scalar_< float_<A0> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      if ((a0 == Inf<A0>()) | is_eqz(a0) ) return Inf<A0>(); 
      if ((a0 < Zero<A0>()) | is_invalid(a0)) return Nan<A0>();
      return ::lgammaf(a0);
    }
  };
} }

#endif

/////////////////////////////////////////////////////////////////////////////
// Implementation when type is integer_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::gammaln_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::gammaln(result_type(a0)); 
    }
  };
} }


#endif
