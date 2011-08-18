//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 boost_math toolbox - ellint3_3/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of boost_math components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/boost_math/include/functions/ellint3_3.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<ellint3_3_> from boost_math
//////////////////////////////////////////////////////////////////////////////
using nt2::boost_math::tag::ellint3_3_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(ellint3_3_,(RS(T,T(-1),T(1)))(RS(T,T(0),T(1)))(RS(T,T(0),nt2::Pi<T>()/2)))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(ellint3_3_,(RS(T,T(-1),T(1)))(RS(T,T(0),T(1)))(RS(T,T(0),nt2::Pi<T>()/2)))
}

#undef RS
