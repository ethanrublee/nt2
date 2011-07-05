//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_MODF_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_MODF_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/ieee/include.hpp>

namespace nt2 { namespace tag
  {         
    struct modf_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::modf_, modf, 1)
  NT2_FUNCTION_IMPLEMENTATION_TPL(tag::modf_, modf,(A0 const&)(A1&)(A2&),3)
  NT2_FUNCTION_IMPLEMENTATION_TPL(tag::modf_, modf,(A0 const&)(A1&),2) 

}
 
#include <nt2/toolbox/operator.hpp>
#include <nt2/toolbox/ieee/function/scalar/modf.hpp>
#include <nt2/toolbox/ieee/function/simd/all/modf.hpp> 

 
#endif

// modified by jt the 25/12/2010
