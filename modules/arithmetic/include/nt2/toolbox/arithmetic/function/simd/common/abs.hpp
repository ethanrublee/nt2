//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_ABS_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_ABS_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/bitwise_notand.hpp>
#include <nt2/include/functions/shri.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is signed_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<signed_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::as_integer<A0, signed>::type int_type;
      typedef typename meta::scalar_of<int_type>::type   sint_type;
      A0 const s = shri(a0, 8*sizeof(sint_type)-1);
      return (a0-s)^(-s);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename meta::as_integer<A0, unsigned>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return a0;
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::abs_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<real_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return b_notand(Mzero<A0>(),a0);
      //      return max(a0, Zero<A0>())-min(a0, Zero<A0>());
    }
  };
} }


#endif
