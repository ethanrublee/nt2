//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 predicates toolbox - is_nan/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of predicates components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
/// modified by jt the 15/04/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/predicates/include/is_nan.hpp>

NT2_TEST_CASE_TPL ( is_nan_real__1_0,  NT2_REAL_TYPES)
{
  using nt2::is_nan;
  using nt2::tag::is_nan_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<is_nan_(vT)>::type r_t;
  typedef typename nt2::meta::call<is_nan_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(is_nan(-nt2::Zero<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Half<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Inf<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Minf<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Mone<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Nan<vT>())[0]!=0, nt2::True<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::One<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Quarter<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Two<vT>())[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(is_nan(nt2::Zero<vT>())[0]!=0, nt2::False<sr_t>());
} // end of test for real_
