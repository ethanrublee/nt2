//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/fdlibm/include/ldexp.hpp>
#include <nt2/sdk/unit/benchmark.hpp>

//////////////////////////////////////////////////////////////////////////////
// Runtime benchmark for functor<ldexp_> from fdlibm
//////////////////////////////////////////////////////////////////////////////
using nt2::fdlibm::ldexp_;

//////////////////////////////////////////////////////////////////////////////
// bench/scalar
// E.G:
// NT2_TIMING( ldexp_ , ((nt2::uint32_t, -10, 10))
//                      ((nt2::uint32_t, -10, 10)) ) 
//           )
//////////////////////////////////////////////////////////////////////////////