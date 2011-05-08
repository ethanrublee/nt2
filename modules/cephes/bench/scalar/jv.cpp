//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 cephes toolbox - jv/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of cephes components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/cephes/include/jv.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<jv_> from cephes
//////////////////////////////////////////////////////////////////////////////
using nt2::cephes::tag::jv_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(jv_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(jv_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100))))
}

#undef RS
