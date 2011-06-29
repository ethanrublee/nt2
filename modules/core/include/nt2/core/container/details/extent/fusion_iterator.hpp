//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_FUSION_ITERATOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_FUSION_ITERATOR_HPP_INCLUDED

#include <boost/fusion/iterator/iterator_facade.hpp>

namespace nt2 { namespace containers
{
  template<typename Seq, int N>
  struct extent_iterator
      : boost::fusion::
              iterator_facade < extent_iterator<Seq, N>
                              , boost::fusion::random_access_traversal_tag
                              >
  {
    typedef boost::mpl::int_<N> index;
    typedef Seq sequence_type;

    extent_iterator(Seq& seq) : seq_(seq) {}

    Seq& seq_;

    template<typename T> struct value_of
    {
      typedef typename T::sequence_type::value_type  type;
    };

    template<typename T> struct deref
    {
      typedef typename
          boost::mpl::if_ < boost::is_const<T>
                          , typename T::sequence_type::const_reference
                          , typename T::sequence_type::reference
                          >::type                             type;

      static type call(T const& iter) { return iter.seq_(N+1); }
    };

    template<typename It> struct next
    {
      typedef extent_iterator < typename It::sequence_type
                              , It::index::value + 1
                              >                                type;

      static type call(It const& it) { return type(it.seq_); }
    };

    template<typename It> struct prior
    {
      typedef extent_iterator < typename It::sequence_type
                              , It::index::value - 1
                              >                                type;

      static type call(It const& it) { return type(it.seq_); }
    };

    template<typename It1, typename It2>
    struct distance
    {
      typedef typename
              boost::mpl::minus < typename It2::index
                                , typename It1::index>::type type;

      static type call(It1 const& it1, It2 const& it2) { return type(); }
    };

    template<typename It, typename M> struct advance
    {
      typedef extent_iterator < typename It::sequence_type
                              , It::index::value + M::value
                              >                                type;

      static type call(It const& it) { return type(it.seq_); }
    };
  };
} }

#endif
