//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 bitwise toolbox - unit/scalar Mode"

#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/toolbox/bitwise/include/bitwise_select.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>

//////////////////////////////////////////////////////////////////////////////
// Test behavior of bitwise components using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( bitwise_select,  (nt2::uint64_t)(nt2::int64_t) 
                (nt2::uint32_t)(nt2::int32_t)  
                (nt2::uint16_t)(nt2::int16_t)         
                (nt2::uint8_t)(nt2::int8_t)
                )
{
  using nt2::bitwise_select;
  using nt2::tag::bitwise_select_;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<bitwise_select_(T, T, T)>::type
           , T
              >::value)
           );
NT2_TEST_EQUAL(  bitwise_select( T(0), T(1), T(2)), T(2) );
NT2_TEST_EQUAL(  bitwise_select( T(-1), T(1), T(2)), T(1) );
}

NT2_TEST_CASE_TPL ( real_bitwise_select,  (double) 
                (float)
                )
{
  using nt2::bitwise_select;
  using nt2::tag::bitwise_select_;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<bitwise_select_(T, T, T)>::type
           , T
              >::value)
           );
NT2_TEST_EQUAL(  bitwise_select( T(0), T(1), T(2)), T(2) );
 NT2_TEST_EQUAL(  bitwise_select( nt2::Nan<T>(), T(1), T(2)), T(1) );
}
           



