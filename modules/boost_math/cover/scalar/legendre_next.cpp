//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 boost_math toolbox - legendre_next/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of boost_math components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 07/03/2011
/// 
#include <nt2/toolbox/boost_math/include/functions/legendre_next.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/max.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
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


NT2_TEST_CASE_TPL ( legendre_next_real__5_0,  NT2_REAL_TYPES)
{
  
  using nt2::boost_math::legendre_next;
  using nt2::boost_math::tag::legendre_next_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<legendre_next_(iT,iT,T,T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,iT, NR, T(0), T(10));
    NT2_CREATE_BUF(tab_a1,iT, NR, T(0), T(10));
    NT2_CREATE_BUF(tab_a2,T, NR, T(-10), T(10));
    NT2_CREATE_BUF(tab_a3,T, NR, T(-10), T(10));
    NT2_CREATE_BUF(tab_a4,T, NR, T(-10), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    iT a0;
    iT a1;
    T a2;
    T a3;
    T a4;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << ", a2 = "<< u_t(a2 = tab_a2[j])
                  << ", a3 = "<< u_t(a3 = tab_a3[j])
                  << ", a4 = "<< u_t(a4 = tab_a4[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::boost_math::legendre_next(a0,a1,a2,a3,a4),nt2::boost_math::legendre_next(a0,a1,a2,a3,a4),1);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for floating_
