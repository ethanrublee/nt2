//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 swar toolbox - cumsum/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of swar components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/swar/include/cumsum.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<cumsum_> from swar
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::cumsum_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,T(-100),T(100))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,T(-100),T(100))))
}
namespace n3 {
  typedef nt2::int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n4 {
  typedef nt2::int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n5 {
  typedef nt2::int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n6 {
  typedef nt2::int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n7 {
  typedef nt2::uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n8 {
  typedef nt2::uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n9 {
  typedef nt2::uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n10 {
  typedef nt2::uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cumsum_,(RS(vT,nt2::Valmin<T>(),nt2::Valmax<T>())))
}

#undef RS
