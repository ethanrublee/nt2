//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 operator toolbox - shift_left/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/operator/include/shift_left.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<shift_left_> from operator
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::shift_left_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef nt2::int8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n2 {
  typedef nt2::int16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n3 {
  typedef nt2::int32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n4 {
  typedef nt2::int64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n5 {
  typedef nt2::uint8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n6 {
  typedef nt2::uint16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n7 {
  typedef nt2::uint32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n8 {
  typedef nt2::uint64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n9 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}
namespace n10 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(shift_left_,(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(iT,0,sizeof(sT)*8-1)))
}

#undef RS