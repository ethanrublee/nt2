//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_IMPL_SIZE_SCALAR_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_SIZE_SCALAR_HPP_INCLUDED

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is fundamental
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::size_, tag::cpu_
                            , (A0), (unspecified_<A0>) 
                            )
  {
    typedef containers::extent<_0D> result_type;

    NT2_FUNCTOR_CALL(1)
    {
      result_type that;
      return that;
    }
  };
} }

#endif
