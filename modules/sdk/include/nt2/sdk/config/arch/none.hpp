/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_ARCH_NONE_HPP_INCLUDED
#define NT2_SDK_CONFIG_ARCH_NONE_HPP_INCLUDED

#include <nt2/sdk/error/warning.hpp>

#if !defined(NT2_ARCH)
  NT2_WARNING(Unknown target architecture)
  #define NT2_ARCH_UNKNOWN
  #define NT2_ARCH "unknown"
  #define NT2_ARCH_ALIGNMENT sizeof(void*)
#endif

#endif
