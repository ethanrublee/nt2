//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_ULP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_ULP_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/predecessor.hpp>
#include <nt2/include/functions/successor.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::ulp_, tag::cpu_,
			     (A0)(X),
			     ((simd_<arithmetic_<A0>,X>))
			     )
  {
    typedef A0 result_type; 
    NT2_FUNCTOR_CALL(1)
      {
	ignore_unused(a0);
	return nt2::One<A0>();
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is real_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION( tag::ulp_, tag::cpu_
			      , (A0)(X)
			      , ((simd_<real_<A0>,X>))
			      )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
      {
	const A0 x = nt2::abs(a0);
	A0 xp = nt2::predecessor(x);
	A0 xs = nt2::successor(x); 
	return nt2::sel(nt2::is_equal(x, nt2::Inf<A0>()), x, nt2::min(x-xp, xs - x));
      }
  };
} }


#endif
