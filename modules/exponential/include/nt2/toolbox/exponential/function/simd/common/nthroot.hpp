//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SIMD_COMMON_NTHROOT_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SIMD_COMMON_NTHROOT_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/size.hpp>
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/pow.hpp>
#include <nt2/include/functions/seladd.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/bitofsign.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nthroot_, tag::cpu_
                            , (A0)(A1)(X)
                            , ((simd_<integer_<A0>,X>))((simd_<integer_<A1>,X>))
                            )
  {

    typedef typename meta::as_real<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::nthroot(tofloat(a0), a1);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::nthroot_, tag::cpu_
                            , (A0)(A1)(X)
                            , ((simd_<real_<A0>,X>))((simd_<integer_<A1>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      A0 x =  nt2::abs(a0);
      A0 aa1 = tofloat(a1);
      A0 y =nt2::pow(x,rec(aa1));
      A1 nul_a1 = is_eqz(a1);
      A0 a11 = tofloat(a1-nul_a1); 
//       std::cout << "icitte " << std::endl;
//       std::cout << "aa1 " << aa1 << std::endl;
//       std::cout << "y " << y << std::endl;
//       std::cout << "pow(y, aa1) " << nt2::pow(y, aa1) << std::endl;
//       std::cout << "sub(a11, One<A1>()) " << sub(a11, One<A0>()) << std::endl;
//       std::cout << "nul_a1 " << nul_a1 << std::endl;
//       std::cout << "is_nez(y) " << is_nez(y) << std::endl;
//       std::cout << "pow(y, sub(a11, One<A0>())) " << pow(y, sub(a11, One<A0>())) << std::endl;
// 	std::cout << "pow(y, sub(a1, One<A1>())) " << pow(y, sub(a11, One<A1>())) << std::endl;
      y = seladd(b_or(is_nez(y), nul_a1), y, - (pow(y, aa1) - x)/(aa1* pow(y, sub(a11, One<A0>()))));
//      std::cout << "ybis " << y << std::endl;
      // Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
      // by one iteration of Newton's method
      A0 invalid = b_and(is_ltz(a0), is_even(a1)); 
//      std::cout << "invalid " << invalid << std::endl;
      return  b_and(is_nez(a0),
		    b_or(invalid, 
			 sel(is_eqz(aa1), One<A0>(),  
			     sel(b_or(eq(a1, One<A1>()), is_inf(a0)),
				 a0,
				 b_or(y, bitofsign(a0))
				 )
			     )
			 )
		    );
    }
  };
} }


#endif
