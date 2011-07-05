//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_FAST_FREXP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_FAST_FREXP_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shri.hpp>
#include <nt2/include/functions/bitwise_andnot.hpp>
#include <boost/fusion/include/vector.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION_IF( tag::fast_frexp_, tag::cpu_, (A0)(A1)(X)
				  ,( 
				     boost::is_same<typename meta::as_integer<A0>::type, A1>
				  )
                                , ( tag::fast_frexp_
				    ( simd_<real_<A0>,X> 
				    , simd_<real_<A0>,X>
				    , simd_<integer_<A1>,X>  
				    )
				  )
			    , ((simd_< real_<A0>, X>))
			      ((simd_< real_<A0>, X>))    
			      ((simd_< integer_<A1>, X>))
                            )
  {
    typedef int result_type;
    inline int operator()(A0 const& a0,A0 & r0,A1 & r1) const
    {
      typedef typename meta::as_integer<A0, signed>::type      int_type;
      typedef typename meta::scalar_of<int_type>::type        sint_type;
      typedef typename meta::scalar_of<A0>::type                 s_type;
      static const sint_type me = Maxexponent<s_type>()-1;
      static const sint_type nmb= Nbmantissabits<s_type>();
      static const int_type vn1 = nt2::splat<int_type>((2*me+3)<<nmb);
      static const sint_type n2 = me<<nmb;
      r1 = b_and(vn1, a0);                                 //extract exponent
      A0 x = b_andnot(a0, vn1);                            //clear exponent in a0
      r1 = shri(r1,nmb) - splat<int_type>(me);             //compute exponent
      r0 = b_or(x,splat<int_type>(n2));                    //insert expon+1 in x
      return 0;
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION_IF( tag::fast_frexp_, tag::cpu_, (A0)(A1)(X)
				 , ( boost::is_same<typename meta::as_integer<A0>::type, A1>)
                                 , ( tag::fast_frexp_
				     ( simd_<real_<A0>,X> 
				     , simd_<integer_<A1>,X>  
				     )
				   )
				 , ((simd_< real_<A0>, X>))
			   	   ((simd_< integer_<A1>, X>))
                            )
  {
    typedef A0 result_type;    
    inline A0 operator()(A0 const& a0,A1 & a2) const
    {
      A0 a1; 
      nt2::fast_frexp(a0, a1, a2);
      return a1; 
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION(tag::fast_frexp_, tag::cpu_,
                             (A0)(X),
                             ((simd_<arithmetic_<A0>,X>))
                            )
  {
    typedef typename meta::as_integer<A0, signed>::type  exponent;
    typedef boost::fusion::vector<A0,exponent>        result_type;
     
    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      result_type res;
      nt2::fast_frexp( a0
          , boost::fusion::at_c<0>(res)
          , boost::fusion::at_c<1>(res)
          );
      return res;
    }
  };
} }
#endif
