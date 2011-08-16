//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTIONS_SCALAR_LOG2_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTIONS_SCALAR_LOG2_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>
  extern "C"{
    extern double log2_rn ( double );
    extern double log2_rd ( double );
    extern double log2_rz ( double );
    extern double log2_ru ( double );
  };
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::crlibm::tag::log2_<Rounding>, tag::cpu_,
                      (A0)(Rounding),
                      (scalar_<arithmetic_<A0> > )
                     )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      typedef result_type   base;
      typedef typename meta::upgrade<base>::type  type;
      return nt2::crlibm::log2<Rounding>(type(a0));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(nt2::crlibm::tag::log2_<Rounding>, tag::cpu_,
                      (A0)(Rounding),
                      (scalar_<double_<A0> > )
                     )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    template<class A, class R> struct inner_log2;
    NT2_CRLIBM_INNER_STRUCT(rn, log2, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, log2, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, log2, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, log2, rd)
    NT2_FUNCTOR_CALL(1)
      {return inner_log2<A0,Rounding>::eval(a0, Rounding()); }
  };
} }
#endif
