//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 predicates toolbox - unit/simd Mode"

#include <nt2/toolbox/predicates/include/is_negative.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/include/functions/random.hpp>
#include <nt2/include/functions/boolean.hpp>
#include <nt2/include/functions/shrai.hpp>
#include <nt2/sdk/constant/properties.hpp>

#include <iostream>
//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(is_negative, (double))//NT2_SIMD_TYPES )
{
 using nt2::is_negative;
 using nt2::tag::is_negative_; 
 using nt2::load;  
 using nt2::simd::native; 
 using nt2::meta::cardinal_of;

 typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
 typedef native<T,ext_t>             n_t;
 typedef typename nt2::meta::call<is_negative_(n_t)>::type call_type;

 NT2_TEST( (boost::is_same<call_type, n_t>::value) );  
 NT2_ALIGNED_TYPE(T) data[1*cardinal_of<n_t>::value];
 for(int j =  0;  j < 10; j++)
   {
     for(std::size_t i=0;i<1*cardinal_of<n_t>::value;++i){
       data[i] = nt2::random(-10000.0, 10000.0); // good value here for is_negative
     }
     n_t a0 = load<n_t>(&data[0],0); 
     n_t v  = is_negative(a0); 
     for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
       { 
       NT2_TEST_EQUAL(nt2::boolean(v[j]), is_negative(a0[j]));
       std::cout << a0[j] << "  " << nt2::boolean(v[j]) << "   " <<  is_negative(a0[j]) << std::endl; 
       }
   }
//  typedef typename nt2::meta::as_integer<T, signed>::type iT;
//  typedef native < iT, ext_t >  viT; 
//  std::cout << nt2::simd::native_cast < n_t>(nt2::shrai(nt2::Signmask<viT>(), 64)) << std::endl;
//  std::cout << nt2::shrai(nt2::Signmask<viT>(), 63) << std::endl;
//  std::cout << nt2::simd::native_cast <viT>(nt2::Signmask<viT>())                  << std::endl; 
//  std::cout << nt2::simd::native_cast <n_t>(nt2::Signmask<viT>())                  << std::endl;
//  std::cout << nt2::Signmask<iT>() << std::endl;
//  std::cout << nt2::shrai(nt2::Signmask<iT>(), 63) << std::endl;
} 
  
   
    
 
