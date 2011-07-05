//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_REMQUO_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_REMQUO_HPP_INCLUDED
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/round2even.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/toint.hpp>
#include <nt2/include/functions/is_gtz.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <boost/mpl/logical.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::remquo_, tag::cpu_,
			     (A0)(X),
			     ((simd_<arithmetic_<A0>,X>))
			     ((simd_<arithmetic_<A0>,X>))
			     )
  {
    typedef typename meta::as_real<A0>::type               stA0;
    typedef typename meta::as_integer<A0, signed>::type     iA0;             
    typedef boost::fusion::tuple<stA0,iA0>          result_type;
    
    NT2_FUNCTOR_CALL_REPEAT(2)
      {
	result_type res;
	nt2::remquo( tofloat(a0), tofloat(a1)
	      , boost::fusion::at_c<0>(res),  boost::fusion::at_c<1>(res)
	      );
	return res;
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // reference based Implementation
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION_IF(  tag::remquo_, tag::cpu_,(A0)(A1)(A2)(A3)(X)
				  ,( boost::mpl::and_ <
				     boost::mpl::equal_to < meta::cardinal_of<A0>, meta::cardinal_of<A1> >, 
				     boost::mpl::equal_to < meta::cardinal_of<A0>, meta::cardinal_of<A2> >,
				     boost::mpl::equal_to < meta::cardinal_of<A0>, meta::cardinal_of<A3> >
				     >
				  )
                                , ( tag::remquo_
				    ( simd_<arithmetic_<A0>,X> 
				      , simd_<arithmetic_<A1>,X>
				      , simd_<integer_<A2>,X>  
				      , simd_<real_<A3>,X>
				      )
				    ) 
                               , ((simd_<arithmetic_<A0>,X>))
				 ((simd_<arithmetic_<A1>,X>))
                                 ((simd_<real_<A2>,X>))
                                 ((simd_<integer_<A3>,X>))
			     )
  {
    typedef void result_type;    
    inline result_type operator()(A0 const& a0, A1 const& a1,
				  A2 & a2, A3 & a3) const
    {
      nt2::remquo(tofloat(a0), tofloat(a1), a2, a3); 
    }
  };

/////////////////////////////////////////////////////////////////////////////
  // reference based Implementation
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION_IF(  tag::remquo_, tag::cpu_,(A0)(A1)(X)
				  ,( boost::mpl::equal_to < meta::cardinal_of<A0>, meta::cardinal_of<A1> >)
				  , ( tag::remquo_
				      ( simd_<real_<A0>,X> 
					, simd_<real_<A0>,X>
					, simd_<real_<A0>,X>
					, simd_<integer_<A1>,X>  
					)
				      ) 
				  , ((simd_<real_<A0>,X>))
				  ((simd_<real_<A0>,X>))
				  ((simd_<real_<A0>,X>))
				  ((simd_<integer_<A1>,X>))
			     )
  {
    typedef void result_type;    
    inline result_type operator()(A0 const& a0, A0 const& a1,
				  A0 & a2, A1 & a3) const
    {
      a2 = round2even(a0/a1); 
      a3 = toint(a2);
      a2 = b_or(is_invalid(a0), b_or(is_eqz(a1), a0-a2*a1)); 
 
    }
  };
 
} }
#endif
