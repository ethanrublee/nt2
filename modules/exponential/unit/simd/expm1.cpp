//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 exponential toolbox - expm1/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of exponential components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
/// modified by jt the 21/04/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/exponential/include/expm1.hpp>

NT2_TEST_CASE_TPL ( expm1_real__1_0,  NT2_REAL_TYPES)
{
  using nt2::expm1;
  using nt2::tag::expm1_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<expm1_(vT)>::type r_t;
  typedef typename nt2::meta::call<expm1_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(expm1(nt2::Inf<vT>())[0], nt2::Inf<sr_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expm1(nt2::Minf<vT>())[0], nt2::Mone<sr_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expm1(nt2::Mone<vT>())[0], nt2::One<sr_t>()/nt2::Exp_1<sr_t>()-nt2::One<sr_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expm1(nt2::Nan<vT>())[0], nt2::Nan<sr_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expm1(nt2::One<vT>())[0], nt2::Exp_1<sr_t>()-nt2::One<sr_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expm1(nt2::Zero<vT>())[0], nt2::Zero<sr_t>(), 1.0);
  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0.1), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t v = expm1(a0);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_ULP_EQUAL( v[i],ssr_t(nt2::expm1(tab_a0[k])), 1.0);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }
} // end of test for real_
