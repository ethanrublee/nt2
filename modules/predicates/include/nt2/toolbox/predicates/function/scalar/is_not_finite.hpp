//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NOT_FINITE_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NOT_FINITE_HPP_INCLUDED
#include <nt2/include/functions/boolean.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>

#include <nt2/include/functions/is_nan.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::is_not_finite_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      return False<A0>();
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::is_not_finite_, tag::cpu_
                            , (A0)
                            , (scalar_< real_<A0> >)
                            )
  {

    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::is_nan(a0-a0);
    }
  };
} }


#endif
