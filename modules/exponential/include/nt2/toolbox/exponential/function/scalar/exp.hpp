//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_EXP_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_EXP_HPP_INCLUDED

#include <nt2/toolbox/exponential/function/scalar/impl/expo.hpp>
//  MIGRATION WARNING you have to provide the file for the previous include from
//  nt2/core/numeric/function/details/scalar/impl/expo.hpp
//  of the old nt2


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::exp_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::exp(result_type(a0));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::exp_, tag::cpu_
                            , (A0)
                            , (scalar_< real_<A0> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
       return impl::exponential<A0,natural_tag, tag::not_simd_type, accu_tag>::expa(a0);
    }
  };
} }


#endif
