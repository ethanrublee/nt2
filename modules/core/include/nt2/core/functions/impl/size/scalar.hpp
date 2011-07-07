//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_IMPL_SIZE_SCALAR_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_SIZE_SCALAR_HPP_INCLUDED

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::size_, tag::cpu_
                            , (A0), (scalar_< unspecified_<A0> >) 
                            )
  {
    template<class Sig> struct result;
    
    template<class This, class X> 
    struct result<This(X)>
    {
      typedef containers::extent<_0D> type;
    };
    
    template<class X> inline            
    typename result<implement( X const& )>::type                                              
    operator()( X const& ) const                                                           
    {
      typename result<implement( X const& )>::type that;
      return that;
    }
  };
} }

#endif
