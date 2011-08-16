//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTIONS_ASIN_RD_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTIONS_ASIN_RD_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/crlibm/include.hpp>

namespace nt2 { namespace crlibm { namespace tag
  {         
    struct asin_rd_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(crlibm::tag::asin_rd_, asin_rd, 1)
  } }
 
#include <nt2/toolbox/crlibm/functions/scalar/asin_rd.hpp>
// #include <nt2/toolbox/crlibm/functions/simd/all/asin_rd.hpp> 

 
#endif

// modified by jt the 29/12/2010