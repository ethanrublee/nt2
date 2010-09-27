//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ELLIPTIC_FUNCTION_SIMD_COMMON_ELLINT_1_HPP_INCLUDED
#define NT2_TOOLBOX_ELLIPTIC_FUNCTION_SIMD_COMMON_ELLINT_1_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/sdk/constant/eps_related.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/toolbox/polynomials/function/scalar/impl/horner.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<ellint_1_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      meta::is_real_convertible<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute ellint_1(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<ellint_1_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>:  meta::as_real<A0>{};


    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (3, (float,double,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,  float)
    {
      typedef typename meta::scalar_of<A0>::type sA0; 
      const A0 a = oneminus(sqr(a0)); 
      const A0 loga = log(a); 	
      A0 z1 = integral_constant<A0, 0x3fb17218 > () - Half<A0>()*loga;
      A0 z2 =	horner< NT2_HORNER_COEFF_T(sA0, 11,
					 (0x3910af7e, 
					  0x3b15705e, 
					  0x3c02a58c, 
					  0x3c218458, 
					  0x3be146d1, 
					  0x3bcacd2e, 
					  0x3c100737, 
					  0x3c74beb4, 
					  0x3cfd02d9, 
					  0x3dc5c860, 
					  0x3fb17218
					  ) ) > (a)
	    -loga*horner< NT2_HORNER_COEFF_T(sA0, 11,
					   (0x37f6b0fa, 
					    0x3a6fa5e6, 
					    0x3bc2a939, 
					    0x3c7db504, 
					    0x3cc3dcb9, 
					    0x3cf6bf35, 
					    0x3d191914, 
					    0x3d47ffe8, 
					    0x3d900000, 
					    0x3e000000, 
					    0x3f000000
					    ) ) > (a);
    
        return select(isgt(a, Eps<A0>()), z2, z1); 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, double)
    {
	A0 r; 
	map(functor<ellint_1_>(), a0, r);
	return r; 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,       arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      return nt2::ellint_1(tofloat(a0)); ;
    }
  };
} }

      
#endif