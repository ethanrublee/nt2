//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FREXP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FREXP_HPP_INCLUDED
#include <boost/mpl/vector.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/at.hpp>
#include <math.h>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::frexp_, tag::cpu_, (A0)(A1)(A2)
                            , (scalar_< double_<A0> >)
                              (scalar_< double_<A1> >)
			      (scalar_< int32_<A2> >)
                            )
  {
    typedef void result_type;
    inline void operator()(A0 const& a0,A1 & a1,A2 & a2) const
    {
      a1 = ::frexp(a0, &a2);
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( tag::frexp_, tag::cpu_, (A0)(A2)
                            , (scalar_< double_<A0> >)
			      (scalar_< int32_<A2> >)
                            )
  {
    typedef A0 result_type;    
    inline void operator()(A0 const& a0,A2 & a2) const
    {
      typedef typename meta::as_integer<A0, signed>::type      int_type;
      A0 a1; 
      nt2::frexp(a0, a1, a2);
      return a1; 
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( tag::frexp_, tag::cpu_, (A0)(A1)(A2)
                            , (scalar_< float_<A0> >)
                              (scalar_< float_<A1> >)
			      (scalar_< int32_<A2> >)
                            )
  {
    typedef void result_type;
    inline void operator()(A0 const& a0,A1 & a1,A2 & a2) const
    {
      a1 = ::frexpf(a0, &a2);
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( tag::frexp_, tag::cpu_, (A0)(A2)
                            , (scalar_< float_<A0> >)
			      (scalar_< int32_<A2> >)
                            )
  {
    typedef A0 result_type;    
    inline void operator()(A0 const& a0,A2 & a2) const
    {
      return ::frexpf(a0, &a2);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::frexp_, tag::cpu_, (A0)
                            , (scalar_< double_<A0> >)
                            )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type mantissa;
    typedef typename meta::as_integer<A0,signed>::type          exponent;
    typedef boost::fusion::vector<mantissa,exponent>            result_type;

    NT2_FUNCTOR_CALL(1)
    {
      result_type res;
      int r1t = 0;
      boost::fusion::at_c<0>(res) = ::frexp(a0, &r1t);
      boost::fusion::at_c<1>(res) = r1t;
      return res;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::frexp_, tag::cpu_, (A0)
                            , (scalar_< float_<A0> >)
                            )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type mantissa;
    typedef typename meta::as_integer<A0,signed>::type          exponent;
    typedef boost::fusion::vector<mantissa,exponent>            result_type;

    NT2_FUNCTOR_CALL(1)
    {
      result_type res;
      boost::fusion::at_c<0>(res) = ::frexpf(a0, &boost::fusion::at_c<1>(res));
      return res;
    }
  };
} }

#endif
