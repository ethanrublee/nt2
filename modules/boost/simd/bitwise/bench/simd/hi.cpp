//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 boost.simd.bitwise toolbox - hi/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of boost.simd.bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <boost/simd/toolbox/bitwise/include/hi.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<hi_> from boost.simd.bitwise
//////////////////////////////////////////////////////////////////////////////
using boost::simd::tag::hi_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n3 {
  typedef boost::simd::int16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n4 {
  typedef boost::simd::int32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n5 {
  typedef boost::simd::int64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}

#undef RS
