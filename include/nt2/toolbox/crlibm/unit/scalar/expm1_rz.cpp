//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 crlibm toolbox - unit/scalar Mode"

#include <nt2/sdk/functor/meta/call.hpp> 
#include <boost/type_traits/is_same.hpp>
#include <nt2/toolbox/crlibm/include/expm1_rz.hpp> 
#include <nt2/sdk/unit/tests.hpp> 
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/constant/eps_related.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/log2.hpp>

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( expm1_rz, (double) 
                (float) 
                )
{
  using nt2::crlibm::expm1_rz; 
  using nt2::crlibm::tag::expm1_rz_;
  const int N = 2; 
   NT2_TEST( (boost::is_same < typename nt2::meta::call<expm1_rz_(T)>::type
            , T
            >::value)
           );
   typedef typename boost::result_of<nt2::meta::floating(T)>::type r_t; 
   NT2_TEST_LESSER_EQUAL(  nt2::ulpdist(nt2::crlibm::expm1_rz( T(0) )  , 0 ), 1);
   NT2_TEST_LESSER_EQUAL(  nt2::ulpdist(nt2::crlibm::expm1_rz( T(1) )  , T(nt2::Exp_1<T>()-1) ), 1);
   NT2_TEST_LESSER_EQUAL(  nt2::ulpdist(nt2::crlibm::expm1_rz(nt2::Minf<T>() ), T(-1)), 1);
   NT2_TEST_LESSER_EQUAL(  nt2::ulpdist(nt2::crlibm::expm1_rz(nt2::Eps <T>() ), nt2::Eps<T>()), 1); 

}
