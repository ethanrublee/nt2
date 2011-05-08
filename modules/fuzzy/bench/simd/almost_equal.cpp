//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 fuzzy toolbox - almost_equal/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of fuzzy components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/fuzzy/include/almost_equal.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<almost_equal_> from fuzzy
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::almost_equal_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n3 {
  typedef int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n4 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n5 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n6 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n7 {
  typedef uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n8 {
  typedef uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n9 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}
namespace n10 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(almost_equal_,(RS(vT,T(-10),T(10)))(RS(vT,T(-10),T(10)))(RS(viT,iT(0),iT(10))))
}

#undef RS
