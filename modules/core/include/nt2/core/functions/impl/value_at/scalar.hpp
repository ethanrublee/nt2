//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_IMPL_VALUE_AT_SCALAR_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_VALUE_AT_SCALAR_HPP_INCLUDED

//==============================================================================
// Implementation when type A0 is fundamental and A1 is a fusion_sequence
//==============================================================================
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::value_at_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< fundamental_<A0> >)
                              (fusion_sequence_<A1>)
                            )
  {
    template<class Sig> struct result;
   
    template<class This, class Value, class Seq>
    struct result<This(Value,Seq)>
    {
      typedef Value type;
    };
   
    inline A0&       operator()( A0& a0      , A1 const& ) const { return a0; }
    inline A0 const& operator()( A0 const& a0, A1 const& ) const { return a0; }                                                                        
  };                    
} }

//==============================================================================
// Implementation when type A0 is fundamental and the other are anything
//==============================================================================
#define M0(z,n,t) (BOOST_PP_CAT(A,n))
#define M1(z,n,t) (generic_< unspecified_<BOOST_PP_CAT(A,n)> >)
#define M2(z,n,t)                                                         \
NT2_REGISTER_DISPATCH_TO( tag::value_at_, tag::cpu_                       \
                        , BOOST_PP_REPEAT(BOOST_PP_INC(n),M0,~)           \
                        , (tag::value_at_(scalar_< fundamental_<A0> >))   \
                        , (generic_< fundamental_<A0> >)                  \
                          BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(n),M1,~) \
                        )                                                 \
/**/

namespace nt2 { namespace meta
{
  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M2,~)
  
  template<class S, class Dummy>
  struct implement<tag::value_at_(scalar_<fundamental_<S> >), tag::cpu_, Dummy >
  {
    template<class Sig> struct result;

    #define M3(z,n,t)                                                         \
    template<class This,BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)>        \
    struct result<This(BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),A))>              \
    { typedef A0 type; };                                                     \
                                                                              \
    template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline A0&        \
    operator()( A0& a0                                                        \
              , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS ( BOOST_PP_INC(n)         \
                                                    , const A                 \
                                                    , & BOOST_PP_INTERCEPT    \
                                                    )                         \
              ) const                                                         \
    {                                                                         \
      return a0;                                                              \
    }                                                                         \
                                                                              \
    template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline A0 const&  \
    operator()( A0 const& a0                                                  \
              , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS ( BOOST_PP_INC(n)         \
                                                    , const A                 \
                                                    , & BOOST_PP_INTERCEPT    \
                                                    )                         \
              ) const                                                         \
    {                                                                         \
      return a0;                                                              \
    }                                                                         \
  /**/

  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M3,~)

  #undef M3
  #undef M2
  #undef M1
  #undef M0
  };
} }

#endif
