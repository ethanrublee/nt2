//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 boost.simd.ieee toolbox - ldexp/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of boost.simd.ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <boost/simd/toolbox/ieee/include/functions/ldexp.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<ldexp_> from boost.simd.ieee
//////////////////////////////////////////////////////////////////////////////
using boost::simd::tag::ldexp_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  typedef boost::simd::native<iT,ext_t> viT;
  NT2_TIMING(ldexp_,(RS(vT,T(-10),T(10)))(RS(viT,iT(-10),iT(10))))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  typedef boost::simd::native<iT,ext_t> viT;
  NT2_TIMING(ldexp_,(RS(vT,T(-10),T(10)))(RS(viT,iT(-10),iT(10))))
}

#undef RS
