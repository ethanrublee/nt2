//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_UNIT_MODULE_HPP_INCLUDED
#define NT2_SDK_UNIT_MODULE_HPP_INCLUDED

/*!
 * \file
 * \brief Define macro for building a Unit Test source file
 */

/*!
 * \ingroup units
 * \defgroup umodules Unit Test Case Generation
 * Define macro for building a Unit Test source file
 */

#include <boost/preprocessor/cat.hpp>
#include <nt2/sdk/details/type_id.hpp>
#include <nt2/sdk/unit/details/suite.hpp>
#include <nt2/sdk/unit/details/stats.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/dispatch/preprocessor/strip.hpp>
#include <boost/utility/enable_if.hpp>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>

#if defined(DOXYGEN_ONLY)
//==============================================================================
/*!
 * \ingroup umodules
 * This macro has to be declared to notify the system that current translation
 * unit is a \nt2 Unit Tests.
 */
//==============================================================================
#define NT2_UNIT_MODULE

//==============================================================================
/*!
 * \ingroup umodules
 * This macro can be declared to give an alternative name to the 'main' function
 * generated by \nt2 Unit Tests.
 */
//==============================================================================
#define NT2_UNIT_MAIN
#endif

#ifndef NT2_UNIT_MAIN
#define NT2_UNIT_MAIN main
#endif

#define NT2_UNIT_PREFIX BOOST_PP_CAT(test_, NT2_UNIT_MAIN)

//==============================================================================
// Embedded main for testing purpose
//==============================================================================
#ifndef BOOST_NO_EXCEPTIONS
extern "C" int NT2_UNIT_MAIN(int, char**)
{
  try
  {
    nt2::details::main_suite.process();
    return nt2::details::error_count() ? -1: 0;
  }
  catch(std::exception const& e)
  {
    std::cerr << "uncaught exception: " << e.what() << std::endl;
    return 1;
  }
  catch(...)
  {
    std::cerr << "uncaught exception" << std::endl;
    return 1;
  }
}
#else
extern "C" int NT2_UNIT_MAIN(int, char**)
{
  nt2::details::main_suite.process();
  return nt2::details::error_count() ? -1: 0;
}

namespace boost
{
  extern inline void throw_exception(std::exception const& e)
  {
    std::cerr << "uncaught exception: " << e.what() << std::endl;
    std::exit(1);
  }
}
#endif

//==============================================================================
/*!
 * \ingroup umodules
 * This macro declares a new test case function containing user-defined tests
 * sequences.
 *
 * \param Name Name of the Test Case to generate
 */
//==============================================================================
#define NT2_TEST_CASE(Name)                                                              \
void BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)();                                               \
nt2::details::test const                                                                 \
BOOST_PP_CAT(Name,NT2_UNIT_PREFIX) = { BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)                \
                                     , BOOST_PP_STRINGIZE(BOOST_PP_CAT(Name,_test))      \
                                     , nt2::details                                      \
                               ::main_suite.link(&BOOST_PP_CAT(Name,NT2_UNIT_PREFIX)) }; \
void BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)()                                                \
/**/

//==============================================================================
// Helper for template tets cases generation
//==============================================================================
#define NT2_PP_TPL_CASES(r,name,type)                                                    \
printf("With T = [%s]\n",nt2::type_id<BOOST_DISPATCH_PP_STRIP(type)>().c_str());         \
BOOST_PP_CAT(tpl_, BOOST_PP_CAT(NT2_UNIT_PREFIX,name))<BOOST_DISPATCH_PP_STRIP(type)>(); \
/**/

//==============================================================================
/*!
 * \ingroup umodules
 * This macro declares a new set of test case functions containing user-defined
 * test sequences working on a list of type passed as template parameters to the
 * test function.
 *
 * \param Name Name of the Test Case to generate
 * \param Types a Preprocessor sequences of type to be used for generating the
 * Test Cases.
 */
//==============================================================================
#define NT2_TEST_CASE_TPL(Name, Types)                                                   \
template<class T> void BOOST_PP_CAT(tpl_, BOOST_PP_CAT(NT2_UNIT_PREFIX,Name))();         \
void BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)();                                               \
nt2::details::test const                                                                 \
BOOST_PP_CAT(Name,NT2_UNIT_PREFIX) = { BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)                \
                                     , BOOST_PP_STRINGIZE(BOOST_PP_CAT(Name,_test))      \
                                     , nt2::details                                      \
                               ::main_suite.link(&BOOST_PP_CAT(Name,NT2_UNIT_PREFIX)) }; \
void BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)()                                                \
{                                                                                        \
  BOOST_PP_SEQ_FOR_EACH(NT2_PP_TPL_CASES,Name,Types);                                    \
}                                                                                        \
template<class T> void BOOST_PP_CAT(tpl_, BOOST_PP_CAT(NT2_UNIT_PREFIX,Name))()          \
/**/

//==============================================================================
/*!
 * \ingroup umodules
 * This macro declares a new set of test case functions containing user-defined
 * test sequences working on a list of type passed as template parameters to the
 * test function, and only enables those tests if a compile-time condition is veried
 *
 * \param Name Name of the Test Case to generate
 * \param Types a Preprocessor sequences of type to be used for generating the
 * Test Cases.
 * \param Cond Meta-function on \c T that must be true for the test to be enabled
 */
//==============================================================================
#define NT2_TEST_CASE_TPL_IF(Name, Types, Cond)                                          \
template<class T>                                                                        \
typename boost::enable_if<BOOST_DISPATCH_PP_STRIP(Cond)>::type                           \
BOOST_PP_CAT(tpl_, BOOST_PP_CAT(NT2_UNIT_PREFIX,Name))();                                \
                                                                                         \
template<class T>                                                                        \
typename boost::disable_if<BOOST_DISPATCH_PP_STRIP(Cond)>::type                          \
BOOST_PP_CAT(tpl_, BOOST_PP_CAT(NT2_UNIT_PREFIX,Name))() {}                              \
                                                                                         \
void BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)();                                               \
nt2::details::test const                                                                 \
BOOST_PP_CAT(Name,NT2_UNIT_PREFIX) = { BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)                \
                                     , BOOST_PP_STRINGIZE(BOOST_PP_CAT(Name,_test))      \
                                     , nt2::details                                      \
                               ::main_suite.link(&BOOST_PP_CAT(Name,NT2_UNIT_PREFIX)) }; \
void BOOST_PP_CAT(NT2_UNIT_PREFIX,Name)()                                                \
{                                                                                        \
  BOOST_PP_SEQ_FOR_EACH(NT2_PP_TPL_CASES,Name,Types);                                    \
}                                                                                        \
                                                                                         \
template<class T>                                                                        \
typename boost::enable_if<BOOST_DISPATCH_PP_STRIP(Cond)>::type                           \
BOOST_PP_CAT(tpl_, BOOST_PP_CAT(NT2_UNIT_PREFIX,Name))()                                 \
/**/

#endif
