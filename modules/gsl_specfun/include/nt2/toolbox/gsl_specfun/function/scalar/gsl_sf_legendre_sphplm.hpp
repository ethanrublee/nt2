//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_SCALAR_GSL_SF_LEGENDRE_SPHPLM_HPP_INCLUDED
#define NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_SCALAR_GSL_SF_LEGENDRE_SPHPLM_HPP_INCLUDED

  extern "C"{
    double gsl_sf_legendre_sphPlm(int, int, double); 
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( gsl_specfun::tag::gsl_sf_legendre_sphplm_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< integer_<A0> >)(scalar_< integer_<A1> >)(scalar_< arithmetic_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    {
      return nt2::gsl_specfun::gsl_sf_legendre_sphplm(result_type(a0), result_type(a1), result_type(a2));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( gsl_specfun::tag::gsl_sf_legendre_sphplm_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< integer_<A0> >)(scalar_< integer_<A1> >)(scalar_< double_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    { return gsl_sf_legendre_sphPlm(a0, a1, a2); }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is float
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( gsl_specfun::tag::gsl_sf_legendre_sphplm_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< integer_<A0> >)(scalar_< integer_<A1> >)(scalar_< float_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    { return gsl_sf_legendre_sphPlm(a0, a1, a2); }
  };
} }


#endif
