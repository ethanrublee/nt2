//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 trigonometric toolbox - rem_pio2_medium/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/trigonometric/include/rem_pio2_medium.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<rem_pio2_medium_> from trigonometric
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::rem_pio2_medium_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(rem_pio2_medium_,(RS(T,nt2::Zero<T>(),64*nt2::Pi<T>())))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(rem_pio2_medium_,(RS(T,nt2::Zero<T>(),64*nt2::Pi<T>())))
}

#undef RS
