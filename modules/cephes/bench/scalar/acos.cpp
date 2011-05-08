//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 cephes toolbox - acos/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of cephes components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/cephes/include/acos.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<acos_> from cephes
//////////////////////////////////////////////////////////////////////////////
using nt2::cephes::tag::acos_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(acos_,(RS(T,T(-1),T(1))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(acos_,(RS(T,T(-1),T(1))))
}

#undef RS
