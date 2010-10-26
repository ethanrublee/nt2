//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_INCBPS_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_INCBPS_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern float cephes_incbpsf ( float,float,float );
    extern double cephes_incbps ( double,double,double );
  }
  struct validate<cephes::incbps_,tag::scalar_(tag::arithmetic_),Info>
    {
      template<class Sig> struct result;
      template<class This,class A0, class A1, class A2>
      struct result<This(A0, A1, A2)> :
        boost::mpl::and_<
           meta::has_smaller_size<A0,long double>,
           meta::has_smaller_size<A1,long double>,
           meta::has_smaller_size<A2,long double>
        >{};
    };
  /////////////////////////////////////////////////////////////////////////////
  // Compute incbps(const A0& a0, const A1& a1, const A2& a2)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<cephes::incbps_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2>
    struct result<This(A0, A1, A2)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH( 3, A0, (3, (float,double,arithmetic_)) )
    NT2_FUNCTOR_CALL_EVAL_IF(3,  float){ return cephes_incbps(a0, a1, a2);}
    NT2_FUNCTOR_CALL_EVAL_IF(3,  double){ return cephes_incbps(a0, a1, a2);}
    NT2_FUNCTOR_CALL_EVAL_IF(3, arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(3)::type type;
      return nt2::cephes::incbps(type(a0), type(a1), type(a2));
    }
  };
} }


      
#endif