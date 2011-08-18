//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 fdlibm toolbox - remainder/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of fdlibm components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/fdlibm/include/functions/remainder.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<remainder_> from fdlibm
//////////////////////////////////////////////////////////////////////////////
using nt2::fdlibm::tag::remainder_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(remainder_,(RS(T,T(-10),T(10)))(RS(T,T(-10),T(10))))
}

#undef RS
