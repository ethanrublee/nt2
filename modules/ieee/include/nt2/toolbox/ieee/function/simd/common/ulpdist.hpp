//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_ULPDIST_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_ULPDIST_HPP_INCLUDED
#include <nt2/include/constants/eps_related.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/include/constants/digits.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/frexp.hpp>
#include <nt2/include/functions/ldexp.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/min.hpp>
#include <nt2/include/functions/is_nan.hpp>

///////////////////////////////////////////////////////////////////////////////
// It is often difficult to  answer to the following question:
//  - are these two floating computations results similar enough ?
//
// The ulpdist is a way to answer tuned for relative errors estimations
// and peculiarity of limited bits accuracy of floating point representation
// The method is the following:
//    Properly normalize the two numbers by the same factor in a way that 
//    the largest of the two numbers exponents will be brought to zero
//
//    Return this nt2::absolute difference of these normalized numbers
//    divided by the rounding error Eps
//
//    The roundind error is the ulp (unit in the last place) value, i.e. the
//    floating number, the exponent of which is 0 and the mantissa is all zeros
//    but a 1 in the last digit (it is not hard coded that way however).
//    Yhis means 2^-23 for floats and 2^-52 for double
//
//    For instance if two floating numbers (of same type) have an ulpdist of 
//    zero that means that their floating representation are identical.
//
//    Generally equality up to 0.5ulp is the best that one can wish beyond
//    strict equality.
//
//    Typically if a double is compared to the double representation of
//    its floating conversion (they are exceptions as for fully representable
//    reals) the ulpdist will be around 2^26.5 (~10^8)
//
//    The ulpdist is also roughly equivalent to the number of representable
//    floating points values between two given floating points values.
//
//     ulpdist( 1.0, 1+nt2::Eps<double>())   == 0.5
//     ulpdist( 1.0, 1+nt2::Eps<double>()/2) == 0.0
//     ulpdist( 1.0, 1-nt2::Eps<double>()/2) == 0.25
//     ulpdist( 1.0, 1-nt2::Eps<double>())   == 0.5 
//     ulpdist(double(nt2::Pi<float>()), nt2::Pi<double>()) == 9.84293e+07
///////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::ulpdist_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return (max(a0, a1)-min(a0,a1));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::ulpdist_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<real_<A0>,X>))((simd_<real_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_integer<A0>::type itype;
      itype e1, e2;
      A0 m1, m2;
      boost::fusion::tie(m1, e1) = nt2::frexp(a0);
      boost::fusion::tie(m2, e2) = nt2::frexp(a1);
      itype expo = -nt2::max(e1, e2);
      A0 e = sel(is_equal(e1, e2), nt2::abs(m1-m2), nt2::abs(nt2::ldexp(a0, expo)-nt2::ldexp(a1, expo)));
      return sel((is_nan(a0)&is_nan(a1))|is_equal(a0, a1),  Zero<A0>(), e/Eps<A0>());
    }
  };
} }


#endif
