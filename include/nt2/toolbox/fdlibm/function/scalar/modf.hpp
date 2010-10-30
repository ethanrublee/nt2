//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_FDLIBM_FUNCTION_SCALAR_MODF_HPP_INCLUDED
#define NT2_TOOLBOX_FDLIBM_FUNCTION_SCALAR_MODF_HPP_INCLUDED
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/vector.hpp>
#include <nt2/sdk/meta/strip.hpp>

namespace nt2 { namespace functors
{
  extern "C"{
    extern double fd_modf ( double,double* );
  }
  /////////////////////////////////////////////////////////////////////////////
  // Compute modf(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<fdlibm::modf_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef boost::fusion::vector<double, double>        type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_CALL_RETURN_TYPE(1)::type res;
      boost::fusion::at_c<0>(res) = fd_modf(a0, &boost::fusion::at_c<1>(res));
      return res;
    }

  };
} }


      
#endif