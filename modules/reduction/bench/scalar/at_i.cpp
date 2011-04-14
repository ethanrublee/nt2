//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 reduction toolbox - at_i/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of reduction components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/reduction/include/at_i.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<at_i_> from reduction
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::at_i_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef int8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n2 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n3 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n4 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n5 {
  typedef uint8_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n6 {
  typedef uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n7 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}
namespace n8 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(at_i_,(RS(T,nt2::Valmin<T>(),nt2::Valmax<T>()))(RS(iT,0,0)))
}

#undef RS