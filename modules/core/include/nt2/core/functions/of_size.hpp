#if !BOOST_PP_IS_ITERATING
//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_OF_SIZE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_OF_SIZE_HPP_INCLUDED

/*!
 * \file
 * \brief Defines and implements the of_size functions
 */

#include <nt2/core/container/extent.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

namespace nt2
{
  #if defined(DOXYGEN_ONLY)
  //============================================================================
  /*!
   * Builds a nD extent from a list of \c n dimension values.
   *
   * \param d Values to use as dimensions
   *
   * \usage
   *
   * \code
   * #include <iostream>
   * #include <nt2/core/functions/of_size.hpp>
   *
   * int main()
   * {
   *   std::cout << nt2::of_size(3,3,4) << "\n";
   * }
   * \endcode
   */
  //============================================================================
  template<class ...Dims> extent<_nD> of_size(Dims const& d...);
  #endif

  extent<_0D> of_size() { return extent<_0D>(); }

  #define   BOOST_PP_FILENAME_1 "nt2/core/functions/of_size.hpp"
  #define   BOOST_PP_ITERATION_LIMITS (1, NT2_MAX_DIMENSIONS)
  #include  BOOST_PP_ITERATE()
}

#endif

#else
#define N BOOST_PP_ITERATION()

  template<BOOST_PP_ENUM_PARAMS(N,class D)>
  extent<BOOST_PP_CAT(BOOST_PP_CAT(_,N),D)>
  of_size(BOOST_PP_ENUM_BINARY_PARAMS(N,const D, &d))
  {
    extent<BOOST_PP_CAT(BOOST_PP_CAT(_,N),D)> that(BOOST_PP_ENUM_PARAMS(N,d));
    return that;
  }

#undef N

#endif
