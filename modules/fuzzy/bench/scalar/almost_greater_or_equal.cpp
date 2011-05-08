//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 fuzzy toolbox - almost_greater_or_equal/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of fuzzy components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/fuzzy/include/almost_greater_or_equal.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<almost_greater_or_equal_> from fuzzy
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::almost_greater_or_equal_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n3 {
  typedef int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n4 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n5 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n6 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n7 {
  typedef uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n8 {
  typedef uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n9 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}
namespace n10 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(almost_greater_or_equal_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10)))(RS(iT,iT(0),iT(10))))
}

#undef RS
