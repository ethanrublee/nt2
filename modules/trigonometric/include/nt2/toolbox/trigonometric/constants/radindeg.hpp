//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II       
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI       
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_CONSTANTS_RADINDEG_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_CONSTANTS_RADINDEG_HPP_INCLUDED
/*!
 * \file
**/
#include <nt2/sdk/constant/constant.hpp>
/*!
 * \ingroup trigo_constant
 * \defgroup trigo_constant_radindeg Radindeg
 *
 * \par Description
 * Constant Radindeg : Degree in radian multiplier, \f$\frac{180}\pi\f$.
 * 
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/radindeg.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::_radindeg_(A0)>::type
 *     Radindeg();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Radindeg
 * 
 * \return type T value
 *  
 *  
**/
namespace nt2
{
  static const long double long_radindeg =  57.295779513082320876798154814105l; 
  NT2_MAKE_STD_CONSTANT( Radindeg  , 0x404ca5dc1a63c1f8ll, 0x42652ee1, 57)
}

#endif
