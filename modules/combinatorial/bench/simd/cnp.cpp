//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 combinatorial toolbox - cnp/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of combinatorial components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/combinatorial/include/cnp.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<cnp_> from combinatorial
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::cnp_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,T(0),T(10)))(RS(vT,T(0),T(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,T(0),T(10)))(RS(vT,T(0),T(10))))
}
namespace n3 {
  typedef uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,0,100))(RS(vT,0,100)))
}
namespace n4 {
  typedef uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,0,100))(RS(vT,0,100)))
}
namespace n5 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,0,100))(RS(vT,0,100)))
}
namespace n6 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,0,100))(RS(vT,0,100)))
}
namespace n7 {
  typedef int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,00,100))(RS(vT,00,100)))
}
namespace n8 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,00,100))(RS(vT,00,100)))
}
namespace n9 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,00,100))(RS(vT,00,100)))
}
namespace n10 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(cnp_,(RS(vT,00,100))(RS(vT,00,100)))
}

#undef RS
