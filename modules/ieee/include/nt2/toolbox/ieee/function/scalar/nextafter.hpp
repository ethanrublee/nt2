//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_NEXTAFTER_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_NEXTAFTER_HPP_INCLUDED

#include <nt2/include/functions/sign.hpp>
#include <nt2/include/constants/digits.hpp>

#include <nt2/toolbox/ieee/details/math.hpp>
#include <boost/math/special_functions/next.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nextafter_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return a0+sign(a1-a0);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nextafter_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< double_<A0> >)(scalar_< double_<A1> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
    #ifdef NT2_TOOLBOX_IEEE_HAS_NEXTAFTER
      return ::nextafter(a0, a1);
    #elif defined(NT2_TOOLBOX_IEEE_HAS__NEXTAFTER)
      return ::_nextafter(a0, a1);
    #else
      return boost::math::nextafter(a0, a1);
    #endif
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nextafter_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< float_<A0> >)(scalar_< float_<A1> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
    #ifdef NT2_TOOLBOX_IEEE_HAS_NEXTAFTERF
      return ::nextafterf(a0, a1);
    #elif defined(NT2_TOOLBOX_IEEE_HAS__NEXTAFTERF)
      return ::_nextafterf(a0, a1);
    #else
      return boost::math::nextafter(a0, a1);
    #endif
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nextafter_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< unsigned_<A0> >)(scalar_< unsigned_<A1> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return (a1 == a0) ? a0 : (a1 > a0) ? a0+One<A0>() : a0-One<A0>();
    }
  };
} }


#endif
