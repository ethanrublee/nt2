//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_FAST_LDEXP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_FAST_LDEXP_HPP_INCLUDED
#include <nt2/sdk/meta/size.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/bitwise_andnot.hpp>
#include <nt2/include/functions/shli.hpp>
//



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
 NT2_FUNCTOR_IMPLEMENTATION_IF ( tag::fast_ldexp_, tag::cpu_,(A0)(A1)(X)
                                , (boost::mpl::equal_to < boost::mpl::sizeof_<A0>
                                                        , boost::mpl::sizeof_<A1>
                                                        >
                                  )
                                , (tag::fast_ldexp_( simd_<arithmetic_<A0>,X>
                                              , simd_<integer_<A1>,X>
                                              )
                                  )
                                , ((simd_<arithmetic_<A0>,X>))
                                  ((simd_<integer_<A1>,X>))
                                )
  {
    typedef A0 result_type; 
    
    NT2_FUNCTOR_CALL_REPEAT(2)
      {
	return rshl(a0, a1);
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_ and A1 scalar
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION( tag::fast_ldexp_, tag::cpu_
			      , (A0)(A1)(X)
			      , ((simd_<arithmetic_<A0>,X>))(scalar_< integer_<A1> >)
			      )
  {

    typedef A0 result_type;
    
    NT2_FUNCTOR_CALL(2)
      {
	return rshl(a0, a1);
      }
  };
  
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is real_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION_IF(tag::fast_ldexp_, tag::cpu_,
				(A0)(A1)(X),
				(boost::mpl::equal_to<boost::mpl::sizeof_<A0>,
			  	                      boost::mpl::sizeof_<A1>
				                      >
				 ),
				(tag::fast_ldexp_(simd_<real_<A0>,X>,
						  simd_<integer_<A1>,X>)), 
				((simd_<real_<A0>,X>))
				((simd_<integer_<A1>,X>))
				)
  {
    typedef A0 result_type; 

    NT2_FUNCTOR_CALL(2)
      {
	// No denormal provision
	typedef typename meta::scalar_of<result_type>::type             s_type;
	typedef typename meta::as_integer<result_type, signed>::type  int_type;
	// clear exponent in x
	result_type const x = {b_andnot(a0, Ldexpmask<A0>())};
	// extract exponent and compute the new one
	int_type e = b_and(Ldexpmask<A0>(), a0);
	e += shli(a1, Nbmantissabits<s_type>());
	return b_or(x, e);
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is real_ and A1 is scalar
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION( tag::fast_ldexp_, tag::cpu_
			      , (A0)(A1)(X)
			      , ((simd_<real_<A0>,X>))(scalar_< integer_<A1> >)
			      )
  {
    
    typedef A0 result_type;
    
    NT2_FUNCTOR_CALL(2)
      {
	typedef typename meta::as_integer<A0>::type iA0; 
	return fast_ldexp(a0, splat<iA0>(a1)); 
      }
  };
} }


#endif
