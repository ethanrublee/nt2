//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 boost.simd.predicates toolbox - majority/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of boost.simd.predicates components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <boost/simd/toolbox/predicates/include/functions/majority.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<majority_> from boost.simd.predicates
//////////////////////////////////////////////////////////////////////////////
using boost::simd::tag::majority_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n3 {
  typedef boost::simd::int8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n4 {
  typedef boost::simd::int16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n5 {
  typedef boost::simd::int32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n6 {
  typedef boost::simd::int64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n7 {
  typedef boost::simd::uint8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n8 {
  typedef boost::simd::uint16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n9 {
  typedef boost::simd::uint32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}
namespace n10 {
  typedef boost::simd::uint64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(majority_,(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000)))(RS(T,T(-10000),T(10000))))
}

#undef RS
