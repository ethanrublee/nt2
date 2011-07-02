//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_SCALAR_GSL_SF_LEGENDRE_QL_HPP_INCLUDED
#define NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_SCALAR_GSL_SF_LEGENDRE_QL_HPP_INCLUDED

  extern "C"{
    double gsl_sf_legendre_Ql(int, double); 
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( gsl_specfun::tag::gsl_sf_legendre_ql_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< integer_<A0> >)(scalar_< arithmetic_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A1)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::gsl_specfun::gsl_sf_legendre_ql(result_type(a0), result_type(a1));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( gsl_specfun::tag::gsl_sf_legendre_ql_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< integer_<A0> >)(scalar_< double_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A1)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    { return gsl_sf_legendre_Ql(a0, a1); }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is float
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( gsl_specfun::tag::gsl_sf_legendre_ql_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< integer_<A0> >)(scalar_< float_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A1)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    { return gsl_sf_legendre_Ql(a0, a1); }
  };
} }


#endif
