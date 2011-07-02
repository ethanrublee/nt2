//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTION_SIMD_COMMON_DEFINITELY_NOT_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTION_SIMD_COMMON_DEFINITELY_NOT_EQUAL_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_ord.hpp>
#include <nt2/include/functions/successor.hpp>
#include <nt2/include/functions/dist.hpp>
#include <nt2/include/functions/is_finite.hpp>
#include <nt2/include/functions/predecessor.hpp>
#include <nt2/include/functions/abs.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION_IF(tag::definitely_not_equal_, tag::cpu_,
			 (A0)(A1)(X),
			 (boost::mpl::equal_to<boost::mpl::sizeof_<A0>,boost::mpl::sizeof_<A1> >),
			 (tag::definitely_not_equal_(simd_<integer_<A0>,X>,
					     simd_<integer_<A0>,X>, 
			  		     simd_<integer_<A1>,X>)), 
			 ((simd_<integer_<A0>,X>))
			 ((simd_<integer_<A0>,X>))
			 ((simd_<integer_<A1>,X>))
                        )
  {
    typedef A0 result_type;
    inline result_type operator()( A0 const& a0, A0 const& a1, A1 const& a2) const
    {
      return gt(dist(a0, a1), nt2::abs(a2));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION_IF(tag::definitely_not_equal_, tag::cpu_,
			 (A0)(A1)(X),
			 (boost::mpl::equal_to<boost::mpl::sizeof_<A0>,boost::mpl::sizeof_<A1> >),
			 (tag::definitely_not_equal_(simd_<real_<A0>,X>,
					     simd_<real_<A0>,X>, 
			  		     simd_<integer_<A1>,X>)), 
			 ((simd_<real_<A0>,X>))
			 ((simd_<real_<A0>,X>))
			 ((simd_<integer_<A1>,X>))
                       )
  {
    typedef A0 result_type;
    inline result_type operator()( A0 const& a0, A0 const& a1, A1 const& a2) const
    {
      A1 aa2 =  nt2::abs(a2); 
      return b_and(
               is_ord(a0, a1),
               b_and(
                   b_and(
                         is_finite(a0+a1),
                         b_or(
                            gt(a0, successor(a1, aa2)),
                            lt(a0, predecessor(a1,aa2))
                            )
                         ),
                   neq(a0, a1)
                   )
               );
    }
  };
} }
#endif
