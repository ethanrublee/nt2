//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_IMPL_VALUE_AT_AST_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_VALUE_AT_AST_HPP_INCLUDED

#include <nt2/sdk/details/type_id.hpp>
#include <iostream>
#include <nt2/sdk/dsl/call.hpp>

//==============================================================================
// Implementation when type A0 is fundamental and the other are integral
//==============================================================================
#define M0(z,n,t) (BOOST_PP_CAT(A,n))
#define M1(z,n,t) (scalar_< integer_<BOOST_PP_CAT(A,n)> >)
#define M2(z,n,t)                                                         \
NT2_REGISTER_DISPATCH_TO( tag::value_at_, tag::cpu_                       \
                        , BOOST_PP_REPEAT(BOOST_PP_INC(n),M0,~)           \
                        , (tag::value_at_(ast_<A0>))                      \
                        , (ast_<A0>)                                      \
                          BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(n),M1,~) \
                        )                                                 \
/**/

namespace nt2 { namespace meta
{
  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M2,~)
  
  template<class S, class Dummy>
  struct implement<tag::value_at_(ast_<S>), tag::cpu_, Dummy >
  {
    template<class Sig> struct result;

    #define M3(z,n,t)                                                         \
    template<class This,BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)>        \
    struct result<This(BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),A))>              \
    {                                                                         \
      typedef boost::fusion::vector < BOOST_PP_ENUM_SHIFTED_PARAMS     \
                                      ( BOOST_PP_INC(n)                       \
                                      , A         \
                                      )                                       \
                                    >                           pos;          \
      typedef typename meta::call<tag::value_at_(A0,pos)>::type type;         \
    };                                                                        \
                                                                              \
    template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline            \
    typename result<implement( A0&                                            \
                        , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS                 \
                         ( BOOST_PP_INC(n), const A, & BOOST_PP_INTERCEPT )   \
                        )>::type                                              \
    operator()( A0& a0                                                        \
              , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS ( BOOST_PP_INC(n)         \
                                                    , const A                 \
                                                    , & a                     \
                                                    )                         \
            ) const                                                           \
    {                                                                         \
      boost::fusion::vector<BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS               \
                            (BOOST_PP_INC(n), const A, & BOOST_PP_INTERCEPT)  \
                            >                                                 \
      pos(BOOST_PP_ENUM_SHIFTED_PARAMS( BOOST_PP_INC(n), a ));                \
      return a0(pos);                                                         \
    }                                                                         \
                                                                              \
    template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline            \
    typename result<implement( A0 const&                                      \
                        , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS                 \
                          ( BOOST_PP_INC(n), const A, & BOOST_PP_INTERCEPT )  \
                        )>::type                                              \
    operator()( A0 const& a0                                                  \
              , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS ( BOOST_PP_INC(n)         \
                                                    , const A                 \
                                                    , & a                     \
                                                    )                         \
              ) const                                                         \
    {                                                                         \
      boost::fusion::vector<BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS               \
                            (BOOST_PP_INC(n), const A, & BOOST_PP_INTERCEPT)  \
                            >                                                 \
      pos(BOOST_PP_ENUM_SHIFTED_PARAMS( BOOST_PP_INC(n), a ));                \
      return a0(pos);                                                         \
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
