//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_ACOS_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_ACOS_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>
  extern "C"{
    extern double acos_rn ( double );
    extern double acos_rd ( double );
    extern double acos_rz ( double );
    extern double acos_ru ( double );
  };
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(crlibm::tag::acos_<Rounding>, tag::cpu_,
                      (A0)(Rounding),
                      (scalar_<arithmetic_<A0> > )
                     )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      typedef result_type   base;
      typedef typename meta::upgrade<base>::type  type;
      return nt2::crlibm::acos<Rounding>(type(a0));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(crlibm::tag::acos_<Rounding>, tag::cpu_,
                      (A0)(Rounding),
                      (scalar_<double_<A0> > )
                     )
  {
    typedef typename meta::result_of < meta::floating(A0)>::type result_type;
    template<class A, class R> struct inner_acos;
    NT2_CRLIBM_INNER_STRUCT(rn, acos, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, acos, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, acos, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, acos, rd)
    NT2_FUNCTOR_CALL(1)
      {return inner_acos<A0,Rounding>::eval(a0, Rounding()); }
  };
} }
#endif
