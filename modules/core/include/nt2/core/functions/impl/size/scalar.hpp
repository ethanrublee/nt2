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
NT2_REGISTER_DISPATCH ( tag::size_, tag::cpu_, (A0), (unspecified_<A0>) )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::size_(tag::unspecified_),tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef containers::extent<_0D> type ;
    };

    NT2_FUNCTOR_CALL(1) { return typename NT2_RETURN_TYPE(1)::type(); }
  };
} }

#endif
