//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FDLIBM_FUNCTION_SCALAR_FINITE_HPP_INCLUDED
#define NT2_TOOLBOX_FDLIBM_FUNCTION_SCALAR_FINITE_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

extern "C" { extern bool fd_finite ( double ); }

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( fdlibm::tag::finite_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    {
      typedef result_type base;
      typedef typename meta::upgrade<base>::type  type;
      return nt2::fdlibm::finite(type(a0));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( fdlibm::tag::finite_, tag::cpu_
                            , (A0)
                            , (scalar_< real_<A0> >)
                            )
  {

    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    { return ::fd_finite(a0); }
  };
} }


#endif
