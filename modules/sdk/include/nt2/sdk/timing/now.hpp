/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TIMING_NOW_HPP_INCLUDED
#define NT2_SDK_TIMING_NOW_HPP_INCLUDED

#include <nt2/sdk/config/types.hpp>

namespace nt2 { namespace details
{
  typedef nt2::uint64_t  cycles_t;
  double    now();
  inline cycles_t read_cycles();
} }

#include <nt2/sdk/timing/impl/cycles.hpp>

#endif
