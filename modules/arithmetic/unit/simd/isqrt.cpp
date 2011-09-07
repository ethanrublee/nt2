//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - isqrt/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// 
#include <nt2/toolbox/arithmetic/include/functions/isqrt.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/floating.hpp>
#include <nt2/sdk/meta/arithmetic.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/toolbox/constant/constant.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( isqrt_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::isqrt;
  using nt2::tag::isqrt_;
  using nt2::load; 
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<isqrt_(vT)>::type r_t;
  typedef typename nt2::meta::call<isqrt_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Four<vT>())[0], boost::simd::Two<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Inf<vT>())[0], boost::simd::Inf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Minf<vT>())[0], boost::simd::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Mone<vT>())[0], boost::simd::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Nan<vT>())[0], boost::simd::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::One<vT>())[0], boost::simd::One<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Two<vT>())[0], boost::simd::One<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(isqrt(boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>(), 0);
} // end of test for real_