//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EULER_FUNCTION_SIMD_COMMON_SIGNGAM_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTION_SIMD_COMMON_SIGNGAM_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_lez.hpp>
#include <nt2/include/functions/is_flint.hpp>
#include <nt2/include/functions/selsub.hpp>
#include <nt2/include/functions/sb2b.hpp>
#include <nt2/include/functions/floor.hpp>
#include <nt2/include/functions/is_odd.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<signgam_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      meta::is_floating_point<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute signgam(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<signgam_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    : meta::strip<A0>{};//
    
    NT2_FUNCTOR_CALL(1)
    {
      A0 leza0 =  is_lez(a0);
      return b_or(b_and(leza0,isflint(a0)),
		  selsub(leza0,One<A0>(),
			 sb2b(isodd(floor(a0)))*Two<A0>()
			 )
		  ); 
    }
  };
} }

      
#endif