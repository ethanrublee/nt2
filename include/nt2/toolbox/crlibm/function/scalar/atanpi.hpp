//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_ATANPI_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_ATANPI_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern double atanpi_rn ( double );
    extern double atanpi_rd ( double );
    extern double atanpi_rz ( double );
    extern double atanpi_ru ( double );
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute atanpi(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Rounding, class Info>
  struct call<crlibm::atanpi_<Rounding>,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH( 1, A0, (2, (double,arithmetic_)) )
    template<class A0, class R> struct inner_atanpi;
    NT2_CRLIBM_INNER_STRUCT(rn, atanpi, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, atanpi, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, atanpi, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, atanpi, rz)
    NT2_FUNCTOR_CALL_EVAL_IF(1, double)
      {return inner_atanpi<A0,Rounding>::eval(a0, Rounding()); }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      return nt2::crlibm::atanpi<Rounding>(double(a0));
    }
  };
} }


      
#endif