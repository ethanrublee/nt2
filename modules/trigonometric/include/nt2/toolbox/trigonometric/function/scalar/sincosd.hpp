//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_SINCOSD_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_SINCOSD_HPP_INCLUDED
#include <boost/fusion/tuple.hpp>
#include <nt2/toolbox/trigonometric/function/scalar/impl/trigo.hpp>
/////////////////////////////////////////////////////////////////////////////
// reference based Implementation
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::sincosd_, tag::cpu_,
			     (A0)(A1),
			     (scalar_ < arithmetic_<A0> >)
			     (scalar_ < real_<A1> >)
			     (scalar_ < real_<A1> >)
			     )
  {
    typedef void result_type;    
    inline void operator()(A0 const& a0,A1 & a1,A1 & a2) const
    {
      impl::trig_base <A1,degree_tag,trig_tag,
	               tag::not_simd_type>::sincosa(A1(a0),a1,a2); 
    }
  };

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type  is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(tag::sincosd_, tag::cpu_,
                         (A0),
                         (scalar_ < arithmetic_<A0> > )
                        )
  {
      typedef typename meta::result_of<meta::floating(A0)>::type etype;
      typedef boost::fusion::tuple<etype, etype>                   result_type;
    
    NT2_FUNCTOR_CALL(1)
    {
      return sincosd(etype(a0));
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is real_
/////////////////////////////////////////////////////////////////////////////


  NT2_FUNCTOR_IMPLEMENTATION(tag::sincosd_, tag::cpu_,
                         (A0),
                         (scalar_ < real_<A0> >)
                        )
  {
      typedef typename meta::strip<A0>::type           etype;
      typedef boost::fusion::tuple<etype, etype> result_type;
    
    NT2_FUNCTOR_CALL(1)
    {
      result_type res; 
      impl::trig_base < A0,degree_tag
                      , trig_tag,tag::not_simd_type
                      >::sincosa( a0
                                , boost::fusion::at_c<0>(res)
                                , boost::fusion::at_c<1>(res)
                                );
      return res;
    }
  };
} }
#endif
