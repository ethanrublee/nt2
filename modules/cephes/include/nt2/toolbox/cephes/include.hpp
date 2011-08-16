//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_INCLUDE_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_INCLUDE_HPP_INCLUDED
#include <boost/dispatch/details/preprocessor.hpp>

#define NT2_CEPHES_BASE() nt2/toolbox/cephes/functions/scalar/
#define NT2_CEPHES_RELATIVE() nt2/toolbox/cephes/functions/

#define NT2_CEPHES_INCLUDE(F) NT2_SIMD_RELATIVE_INCLUDE(NT2_CEPHES_RELATIVE, F)

#endif
