//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 fdlibm toolbox - __ieee754_fmod/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of fdlibm components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 03/03/2011
/// 
#include <nt2/toolbox/fdlibm/include/__ieee754_fmod.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/rem.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/idivfix.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>


NT2_TEST_CASE_TPL ( __ieee754_fmod_real__2_0,  NT2_REAL_TYPES)
{
  
  using nt2::fdlibm::__ieee754_fmod;
  using nt2::fdlibm::tag::__ieee754_fmod_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<__ieee754_fmod_(T,T)>::type r_t;
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
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10), T(10));
    NT2_CREATE_BUF(tab_a1,T, NR, T(-10), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    T a1;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << std::endl;
        T v1 = nt2::abs(nt2::fdlibm::__ieee754_fmod(a0,a1)+a1*(nt2::idivfix(a0, a1))-a0);
        T v2 = nt2::abs(nt2::rem(a0,a1)+a1*(nt2::idivfix(a0, a1))-a0);
        NT2_TEST_LESSER_EQUAL(v2, v1); 
     }
     
   }
} // end of test for real_
