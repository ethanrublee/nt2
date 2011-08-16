//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - fast_hypot/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// 
#include <nt2/toolbox/arithmetic/include/fast_hypot.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/arithmetic/include/hypot.hpp>

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
#include <nt2/include/constants/real.hpp>


NT2_TEST_CASE_TPL ( fast_hypot_real__2_0,  NT2_REAL_TYPES)
{
  
  using nt2::fast_hypot;
  using nt2::tag::fast_hypot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<fast_hypot_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T,T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Inf<T>(), nt2::Inf<T>()), nt2::Inf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Minf<T>(), nt2::Minf<T>()), nt2::Inf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Mone<T>(), nt2::Mone<T>()), nt2::Sqrt_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Nan<T>(), nt2::Nan<T>()), nt2::Nan<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::One<T>(), nt2::One<T>()), nt2::Sqrt_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Three<T>(),nt2::Four <r_t>()), nt2::Five <r_t>(), 0);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for real_

NT2_TEST_CASE_TPL ( fast_hypot_unsigned_int__2_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::fast_hypot;
  using nt2::tag::fast_hypot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<fast_hypot_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T,T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::One<T>(), nt2::One<T>()), nt2::Sqrt_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Three<T>(),nt2::Four <r_t>()), nt2::Five <r_t>(), 0);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( fast_hypot_signed_int__2_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::fast_hypot;
  using nt2::tag::fast_hypot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<fast_hypot_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T,T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Mone<T>(), nt2::Mone<T>()), nt2::Sqrt_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::One<T>(), nt2::One<T>()), nt2::Sqrt_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Three<T>(),nt2::Four <r_t>()), nt2::Five <r_t>(), 0);
  NT2_TEST_ULP_EQUAL(fast_hypot(nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
} // end of test for signed_int_
