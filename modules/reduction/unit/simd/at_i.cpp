//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 reduction toolbox - at_i/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of reduction components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 24/02/2011
/// modified by jt the 19/03/2011
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
#include <nt2/toolbox/reduction/include/at_i.hpp>

NT2_TEST_CASE_TPL ( at_i_real__2_0,  NT2_REAL_TYPES)
{
  using nt2::at_i;
  using nt2::tag::at_i_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename nt2::meta::scalar_of<T>::type sT;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<at_i_(vT,iT)>::type r_t;
  typedef typename nt2::meta::call<at_i_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    typedef typename nt2::meta::scalar_of<T>::type sT;
    NT2_CREATE_BUF(tab_a0,T, NR, nt2::Valmin<T>(), nt2::Valmax<T>());
    NT2_CREATE_BUF(tab_a1,iT, NR, 0, 0);
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        iT a1 = tab_a1[j];
        T v = at_i(a0,a1);
        NT2_TEST_EQUAL( v,a0[a1]);
      }
    
  }
} // end of test for real_
