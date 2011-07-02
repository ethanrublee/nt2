//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_IDIVFLOOR_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_IDIVFLOOR_HPP_INCLUDED

#include <nt2/include/functions/idivceil.hpp>
#include <nt2/include/functions/rdivide.hpp>
#include <nt2/include/functions/ifloor.hpp>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is signed_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::idivfloor_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< signed_<A0> >)(scalar_< signed_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::arithmetic(A0,A1)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      if(a1)
        return -idivceil(-a0,a1);
      else
      {
        typedef result_type type;
        return (a0) ? ((a0>0) ? Valmax<type>() : Valmin<type>()) : Zero<type>();
      }

    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::idivfloor_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::arithmetic(A0,A1)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
       return rdivide(a0,a1);
    }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is real_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(tag::idivfloor_, tag::cpu_,
			     (A0)(A1),
			     (scalar_< real_<A0> > )(scalar_< real_<A1> > )
			     )
  {
    typedef typename meta::as_integer < typename meta::result_of<meta::arithmetic(A0,A1)>::type >::type result_type;
    NT2_FUNCTOR_CALL(2)
      {
	return nt2::ifloor(a0/a1);
      }
  };
} }

#endif
