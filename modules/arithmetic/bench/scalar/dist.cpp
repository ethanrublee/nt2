//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 arithmetic toolbox - dist/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/arithmetic/include/dist.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<dist_> from arithmetic
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::dist_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,-10.0f,10.0f))(RS(T,-10.0f,10.0f)))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,-10.0,10.0))(RS(T,-10.0,10.0)))
}
namespace n3 {
  typedef int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n4 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n5 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n6 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n7 {
  typedef uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n8 {
  typedef uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n9 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}
namespace n10 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(dist_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>())))
}

#undef RS
