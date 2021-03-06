//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_DSL_FUNCTIONS_RUN_HPP_INCLUDED
#define BOOST_SIMD_DSL_FUNCTIONS_RUN_HPP_INCLUDED

#include <boost/dispatch/functor/preprocessor/function.hpp>

namespace boost { namespace simd
{
  namespace tag { struct run_ {}; }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0 const&), 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0&), 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0 const&)(A1&), 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0&)(A1&), 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0 const&)(A1 const&), 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0&)(A1 const&), 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0 const&)(A1&)(A2 const&), 3)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0&)(A1&)(A2 const&), 3)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0 const&)(A1 const&)(A2 const&), 3)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL(tag::run_, run, (A0&)(A1 const&)(A2 const&), 3)
} }

#endif
