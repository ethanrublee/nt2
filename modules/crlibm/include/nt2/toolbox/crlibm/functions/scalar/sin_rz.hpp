//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTIONS_SCALAR_SIN_RZ_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTIONS_SCALAR_SIN_RZ_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

  extern "C"{
    extern double sin_rz ( double );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::crlibm::tag::sin_rz_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::upgrade<result_type>::type  type;
      return nt2::crlibm::sin_rz(type(a0));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::crlibm::tag::sin_rz_, tag::cpu_
                            , (A0)
                            , (scalar_< double_<A0> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(1)
    { return ::sin_rz(a0); }
  };
} }


#endif
