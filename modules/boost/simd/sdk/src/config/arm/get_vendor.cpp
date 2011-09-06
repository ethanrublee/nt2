//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/sdk/config/arch/arm.hpp>

#ifdef BOOST_SIMD_ARCH_ARM
#include <boost/simd/sdk/config/details/get_vendor.hpp>

namespace boost { namespace simd { namespace config { namespace details
{
    int get_vendor()
    {
        return -1; // TODO
    }
} } } }

#endif
