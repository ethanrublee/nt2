//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - logical_xor/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// 
#include <nt2/toolbox/arithmetic/include/logical_xor.hpp>
#include <nt2/include/functions/ulpdist.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>


NT2_TEST_CASE_TPL ( logical_xor_real__2_0,  NT2_REAL_TYPES)
{
  using nt2::logical_xor;
  using nt2::tag::logical_xor_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<logical_xor_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<logical_xor_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::splat<vT>(0),nt2::splat<vT>(1))[0]!=0, true, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::splat<vT>(3),nt2::splat<vT>(0))[0]!=0, true, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::Inf<vT>(), nt2::Inf<vT>())[0]!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::Minf<vT>(), nt2::Minf<vT>())[0]!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::Mone<vT>(), nt2::Mone<vT>())[0]!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::Nan<vT>(), nt2::Nan<vT>())[0]!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::One<vT>(), nt2::One<vT>())[0]!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(nt2::Zero<vT>(), nt2::Zero<vT>())[0]!=0, false, 0);
} // end of test for real_
