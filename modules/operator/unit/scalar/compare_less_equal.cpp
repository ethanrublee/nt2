//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 operator toolbox - compare_less_equal/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
/// 
#include <nt2/toolbox/operator/include/functions/compare_less_equal.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/all.hpp>

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


NT2_TEST_CASE_TPL ( compare_less_equal_real__2_0,  NT2_REAL_TYPES)
{
  
  using nt2::compare_less_equal;
  using nt2::tag::compare_less_equal_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<compare_less_equal_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef bool wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(compare_less_equal(nt2::Inf<T>(), nt2::Inf<T>()), true);
  NT2_TEST_EQUAL(compare_less_equal(nt2::Minf<T>(), nt2::Minf<T>()), true);
  NT2_TEST_EQUAL(compare_less_equal(nt2::Nan<T>(), nt2::Nan<T>()), true);
  NT2_TEST_EQUAL(compare_less_equal(nt2::One<T>(),nt2::Zero<T>()), false);
  NT2_TEST_EQUAL(compare_less_equal(nt2::Zero<T>(), nt2::Zero<T>()), true);
} // end of test for real_

NT2_TEST_CASE_TPL ( compare_less_equal_signed_int__2_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::compare_less_equal;
  using nt2::tag::compare_less_equal_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<compare_less_equal_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef bool wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(compare_less_equal(nt2::Mone<T>(),nt2::Zero<T>()), true);
  NT2_TEST_EQUAL(compare_less_equal(nt2::One<T>(), nt2::One<T>()), true);
  NT2_TEST_EQUAL(compare_less_equal(nt2::One<T>(),nt2::Zero<T>()), false);
  NT2_TEST_EQUAL(compare_less_equal(nt2::Zero<T>(), nt2::Zero<T>()), true);
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( compare_less_equal_unsigned_int__2_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::compare_less_equal;
  using nt2::tag::compare_less_equal_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<compare_less_equal_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef bool wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(compare_less_equal(nt2::One<T>(), nt2::One<T>()), true);
  NT2_TEST_EQUAL(compare_less_equal(nt2::One<T>(),nt2::Zero<T>()), false);
  NT2_TEST_EQUAL(compare_less_equal(nt2::Zero<T>(), nt2::Zero<T>()), true);
} // end of test for unsigned_int_
