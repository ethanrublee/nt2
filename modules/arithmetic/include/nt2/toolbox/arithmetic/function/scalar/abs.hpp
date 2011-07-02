//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_ABS_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_ABS_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is signed_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)
                            , (scalar_< signed_<A0> >)
                            )
  {

    typedef typename meta::strip <A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return (a0 > 0)?a0:-a0;
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef typename meta::strip <A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return std::abs(a0);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is int32_t
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)
                            , (scalar_< int32_<A0> >)
                            )
  {

    typedef typename meta::strip <A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      A0 mask = a0 >> (sizeof(int32_t)*8 - 1);
      return (a0 + mask) ^ mask;
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)
                            , (scalar_< float_<A0> >)
                            )
  {

    typedef typename meta::strip <A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
       return ::fabs(a0);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)
                            , (scalar_< unsigned_<A0> >)
                            )
  {

    typedef typename meta::strip <A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return a0;
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is bool_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)
                            , (bool_<A0>)
                            )
  {

    typedef typename meta::strip <A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return a0;
    }
  };
} }


#endif
