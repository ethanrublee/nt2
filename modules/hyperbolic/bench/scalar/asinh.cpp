//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 hyperbolic toolbox - asinh/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of hyperbolic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/hyperbolic/include/asinh.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<asinh_> from hyperbolic
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::asinh_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n3 {
  typedef nt2::uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n4 {
  typedef nt2::uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n5 {
  typedef nt2::uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n6 {
  typedef nt2::uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n7 {
  typedef nt2::int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n8 {
  typedef nt2::int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n9 {
  typedef nt2::int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}
namespace n10 {
  typedef nt2::int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(asinh_,(RS(T,T(-10),T(10))))
}

#undef RS
