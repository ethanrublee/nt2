//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_DETAILS_OF_SIZE_META_HPP_INCLUDED
#define NT2_CORE_SETTINGS_DETAILS_OF_SIZE_META_HPP_INCLUDED

#include <boost/simd/sdk/details/at_iterator.hpp>
#include <nt2/core/settings/size.hpp>
#include <boost/fusion/sequence/intrinsic.hpp>
#include <boost/fusion/support.hpp>
#include <boost/mpl/size_t.hpp>

namespace boost { namespace fusion { namespace extension
{
  //============================================================================
  // Register of_size_ expression as fusion random access sequence
  //============================================================================
  template<> struct is_sequence_impl<nt2::tag::of_size_>
  {
    template<typename T> struct apply : mpl::true_ {};
  };

  template<> struct is_view_impl<nt2::tag::of_size_>
  {
    template<typename Seq> struct apply : mpl::false_ {};
  };

  template<> struct category_of_impl<nt2::tag::of_size_>
  {
    typedef random_access_traversal_tag type;
  };

  //============================================================================
  // Size of of_size_ is given by its static_size member
  //============================================================================
  template<> struct size_impl<nt2::tag::of_size_>
  {
    template<typename Sequence>
    struct  apply
          : mpl::size_t<Sequence::static_size>
    {};
  };

  //============================================================================
  // at_c value of of_size_ is given by its static size or dynamic size if -1
  //============================================================================
  template<> struct at_impl<nt2::tag::of_size_>
  {
    template<class Sequence, class Index, std::ptrdiff_t N>
    struct apply_impl;
      
    template<class Sequence, class Index>
    struct apply
     : apply_impl< Sequence
                 , Index
                 , mpl::
                   at< typename Sequence::values_type
                     , Index
                     >::type::value
                 >
    {
    };
    
    template<class Sequence, class Index>
    struct apply_impl<Sequence, Index, -1>
    {
        typedef typename mpl::
        if_< is_const<Sequence>
           , std::size_t const&
           , std::size_t&
           >::type                    type;
           
        static type call(Sequence& seq) { return seq[Index::value]; }
    };
    
    template<class Sequence, class Index, std::ptrdiff_t N>
    struct apply_impl
    {
      typedef mpl::size_t<N> type;
      static type call(Sequence& seq) { return type(); }
    };
  };

  //==========================================================================
  // begin returns the inner data_type begin as it is itself a Fusion Sequence
  //==========================================================================
  template<> struct begin_impl<nt2::tag::of_size_>
  {
    template<typename Sequence> struct apply
    {
      typedef boost::simd::at_iterator<Sequence, 0> type;
      static type call(Sequence& seq) { return type(seq); }
    };
  };

  //==========================================================================
  // end returns the inner data_type end as it is itself a Fusion Sequence
  //==========================================================================
  template<> struct end_impl<nt2::tag::of_size_>
  {
    template<typename Sequence>
    struct apply
    {
      typedef boost::simd::at_iterator<Sequence, Sequence::static_size> type;
      static type call(Sequence& seq) { return type(seq); }
    };
  };
} } }

#endif
