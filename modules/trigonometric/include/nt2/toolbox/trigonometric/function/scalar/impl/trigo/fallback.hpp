//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_IMPL_TRIGO_FALLBACK_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_IMPL_TRIGO_FALLBACK_HPP_INCLUDED
#include <cmath>



namespace nt2
{
  namespace details
  {
    namespace internal
    {
      
      class standard_tag{}; 
      template <class tag > struct fallback
      {
	template < class T > static inline T cos(T x){return std::cos(x); }
	template < class T > static inline T sin(T x){return std::sin(x); }
	template < class T > static inline T tan(T x){return std::tan(x); }
	//     functor<standard::cospi_> _cospi;
	//     functor<standard::sinpi_> _sinpi;
	//     functor<standard::tanpi_> _tanpi;
      }; 

#ifndef FALLBACK_TAG      
#define FALLBACK_TAG standard_tag 
#endif
      
    }
  }
}


#endif
