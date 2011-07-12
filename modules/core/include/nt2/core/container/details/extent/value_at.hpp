//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_VALUE_AT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_VALUE_AT_HPP_INCLUDED

#include <nt2/sdk/dsl/compute.hpp>
#include <boost/fusion/include/front.hpp>
#include <nt2/core/functions/value_at.hpp>

//==============================================================================
// Implementation when type A0 is an extent expression and A1 a sequence
//==============================================================================
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::value_at_, tag::cpu_
                            , (A0)(D0)(Sema)(Tag)(A1)
                            , ((expr_ < A0
                                      , domain_ < containers::domain< tag::extent_
                                                                    , D0
                                                                    > 
                                                >
                                      , Tag, Sema
                                      >
                              ))
                              (fusion_sequence_<A1>)
                            )
  {
    template<class Sig> struct result;

    template<class This,class X,class Y>
    struct  result<This(X,Y)>
    {
      typedef typename 
              boost::result_of
              < meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> >
                (X,meta::as_<typename A0::data_type>,int)
              >::type                                         type;
    };
          
    inline typename result<implement(A0 const&,A1 const&)>::type
    operator()(A0 const& a0, A1 const& a1) const
    {
      meta::as_<typename A0::data_type>                         target;
      meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> >  callee;

      typedef boost::mpl::size<A1> sz_;
      int idx = boost::fusion::at_c<(sz_::value < 2 ? 0 : 1)>(a1) - 1;
      return callee(a0,target,idx);
    }
  };

  //============================================================================
  // terminal case
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( tag::value_at_, tag::cpu_
                            , (A0)(D0)(Sema)(A1)
                            , ((expr_ < A0
                                      , domain_ < containers::domain< tag::extent_
                                                                    , D0
                                                                    > 
                                                >
                                      , tag::extent_, Sema
                                      >
                              ))
                              (fusion_sequence_<A1>)
                            )
  {
    template<class Sig> struct result;

    template<class This,class X,class Y>
    struct  result<This(X,Y)>
    {
      typedef typename boost::remove_reference<X>::type  base;
      typedef typename meta::strip<X>::type              raw;
      typedef typename boost::mpl::if_< boost::is_const<base>
                                      , typename raw::const_reference
                                      , typename raw::reference
                                      >::type type;
    };

    inline typename result<implement(A0&,A1 const&)>::type
    operator()(A0& a0, A1 const& a1) const
    {
      typedef boost::mpl::size<A1> sz_;
      std::size_t idx = boost::fusion::at_c<(sz_::value < 2 ? 0 : 1)>(a1) - 1;
      return boost::proto::value(a0)[ idx ];
    }

    inline typename result<implement(A0 const&,A1 const&)>::type
    operator()(A0 const& a0, A1 const& a1) const
    {
      typedef boost::mpl::size<A1> sz_;
      std::size_t idx = boost::fusion::at_c<(sz_::value < 2 ? 0 : 1)>(a1) - 1;
      return boost::proto::value(a0)[ idx ];
    }
  };

  //============================================================================
  // terminal case for _0D
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( tag::value_at_, tag::cpu_
                            , (A0)(B)(SK)(Sema)(A1)
                            , ((expr_ < A0
                                      , domain_ < containers::
                                                  domain< tag::extent_
                                                        , descriptor<_0D,B,SK>
                                                        > 
                                                >
                                      , tag::extent_, Sema
                                      >
                              ))
                              (fusion_sequence_<A1>)
                            )
  {
    typedef std::size_t result_type;

    inline result_type operator()(A0&, A1 const&)       const { return 1; }
    inline result_type operator()(A0 const&, A1 const&) const { return 1; }
  };
} }

#endif
