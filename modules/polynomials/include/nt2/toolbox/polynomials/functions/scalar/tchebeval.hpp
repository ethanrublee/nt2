//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_POLYNOMIALS_FUNCTIONS_SCALAR_TCHEBEVAL_HPP_INCLUDED
#define NT2_TOOLBOX_POLYNOMIALS_FUNCTIONS_SCALAR_TCHEBEVAL_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/functions/average.hpp>
#include <nt2/toolbox/polynomials/category.hpp>
#include <nt2/sdk/meta/fusion.hpp>
#include <boost/fusion/adapted/array.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::tchebeval_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< arithmetic_<A0> >)(fusion_sequence_<A1>)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return tchebeval(result_type(a0), a1);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::tchebeval_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< real_<A0> >)(fusion_sequence_<A1>)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typename A1::const_iterator p = a1.begin();
      A0 b0 = *p++;
      A0 b1 =  Zero<A0>();
      A0 b2;
      while (p != a1.end())
      {
        b2 = -b1;
        b1 = b0;
        b0 = fma(a0, b1, b2)  + *p++;
      }
      return average(b0, b2);
    }
  };
} }


#endif
