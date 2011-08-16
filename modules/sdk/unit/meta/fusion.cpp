/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::meta::hierarchy_of for fusion types"

#include <boost/array.hpp>
#include <boost/fusion/adapted/array.hpp>

   #include <nt2/sdk/meta/as.hpp>
   #include <nt2/sdk/meta/fusion.hpp>
#include <nt2/sdk/meta/hierarchy_of.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>

#define M0(z,n,t) ::parent
#define UP(T,N) T BOOST_PP_REPEAT(N,M0,~)

////////////////////////////////////////////////////////////////////////////////
// Test that hierarchy_of is correct for ref, value and const ref
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(hierarchy_of_ref_cref, NT2_TYPES)
{
  using boost::array;
  using boost::is_same;
  using nt2::meta::hierarchy_of;
  using namespace nt2::ext;

  typedef array<T,7> base;
  typedef typename hierarchy_of<base>::type        hvalue;
  typedef typename hierarchy_of<base&>::type       rvalue;
  typedef typename hierarchy_of<base const&>::type crvalue;

  NT2_TEST( (is_same<hvalue, rvalue>::value) );
  NT2_TEST( (is_same<hvalue, crvalue>::value) );
}

////////////////////////////////////////////////////////////////////////////////
// Test that hierarchy_of is correct for array
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(hierarchy_of_array)
{
  using boost::array;
  using boost::is_same;
  using nt2::meta::hierarchy_of;
  using namespace nt2::ext;

  typedef hierarchy_of< array<double,7> >::type base;

  NT2_TEST( (is_same<array_<scalar_<double_< array<double,7> > >, 7  >      , base >::value) );
  NT2_TEST( (is_same<array_<scalar_<type64_< array<double,7> > >, 7  >      , UP(base,1) >::value) );
  NT2_TEST( (is_same<array_<scalar_<real_sized_< array<double,7> > >, 7  >  , UP(base,2) >::value) );
  NT2_TEST( (is_same<array_<scalar_<real_< array<double,7> > >, 7  >        , UP(base,3) >::value) );
  NT2_TEST( (is_same<array_<scalar_<signed_< array<double,7> > >, 7  >      , UP(base,4) >::value) );
  NT2_TEST( (is_same<array_<scalar_<arithmetic_< array<double,7> > >, 7  >  , UP(base,5) >::value) );
  NT2_TEST( (is_same<array_<scalar_<fundamental_< array<double,7> > >, 7  > , UP(base,6) >::value) );
  NT2_TEST( (is_same<array_<scalar_<unspecified_< array<double,7> > >, 7  > , UP(base,7) >::value) );

  NT2_TEST( (is_same<array_<generic_<double_< array<double,7> > >, 7  >      , UP(base,8) >::value) );
  NT2_TEST( (is_same<array_<generic_<type64_< array<double,7> > >, 7  >      , UP(base,9) >::value) );
  NT2_TEST( (is_same<array_<generic_<real_sized_< array<double,7> > >, 7  >  , UP(base,10) >::value) );
  NT2_TEST( (is_same<array_<generic_<real_< array<double,7> > >, 7  >        , UP(base,11) >::value) );
  NT2_TEST( (is_same<array_<generic_<signed_< array<double,7> > >, 7  >      , UP(base,12) >::value) );
  NT2_TEST( (is_same<array_<generic_<arithmetic_< array<double,7> > >, 7  >  , UP(base,13) >::value) );
  NT2_TEST( (is_same<array_<generic_<fundamental_< array<double,7> > >, 7  > , UP(base,14) >::value) );
  NT2_TEST( (is_same<array_<generic_<unspecified_< array<double,7> > >, 7  > , UP(base,15) >::value) );
  NT2_TEST( (is_same<array_<unspecified_< array<double,7> >, 7  >            , UP(base,16) >::value) );
  NT2_TEST( (is_same<fusion_sequence_< array<double,7> >                     , UP(base,17) >::value) );
  NT2_TEST( (is_same<unspecified_< array<double,7> >                         , UP(base,18) >::value) );
}

////////////////////////////////////////////////////////////////////////////////
// Test that hierarchy_of is correct for array
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(hierarchy_of_target_array)
{
  using boost::array;
  using boost::is_same;
  using namespace nt2::meta;

  typedef as_< array<double,7> > raw;
  typedef hierarchy_of< raw >::type base;

  NT2_TEST( (is_same<target_<array_<scalar_<double_< raw > >, 7  > >      , base >::value) );
  NT2_TEST( (is_same<target_<array_<scalar_<type64_< raw > >, 7  > >      , UP(base,1) >::value) );
  NT2_TEST( (is_same<target_<array_<scalar_<real_< raw > >, 7  >   >      , UP(base,2) >::value) );
  NT2_TEST( (is_same<target_<array_<scalar_<signed_< raw > >, 7  >  >     , UP(base,3) >::value) );
  NT2_TEST( (is_same<target_<array_<scalar_<arithmetic_< raw > >, 7  >  > , UP(base,4) >::value) );
  NT2_TEST( (is_same<target_<array_<scalar_<fundamental_< raw > >, 7  > > , UP(base,5) >::value) );
  NT2_TEST( (is_same<target_<array_<scalar_<unspecified_< raw > >, 7  > > , UP(base,6) >::value) );

  NT2_TEST( (is_same<target_<array_<generic_<double_< raw > >, 7  >   >    , UP(base,7) >::value) );
  NT2_TEST( (is_same<target_<array_<generic_<type64_< raw > >, 7  >  >     , UP(base,8) >::value) );
  NT2_TEST( (is_same<target_<array_<generic_<real_< raw > >, 7  >    >     , UP(base,9) >::value) );
  NT2_TEST( (is_same<target_<array_<generic_<signed_< raw > >, 7  >   >    , UP(base,10) >::value) );
  NT2_TEST( (is_same<target_<array_<generic_<arithmetic_< raw > >, 7  > >  , UP(base,11) >::value) );
  NT2_TEST( (is_same<target_<array_<generic_<fundamental_< raw > >, 7  > > , UP(base,12) >::value) );
  NT2_TEST( (is_same<target_<array_<generic_<unspecified_< raw > >, 7  > > , UP(base,13) >::value) );
  NT2_TEST( (is_same<target_<array_<unspecified_< raw >, 7  >     >        , UP(base,14) >::value) );
  NT2_TEST( (is_same<target_<fusion_sequence_< raw >       >               , UP(base,15) >::value) );
  NT2_TEST( (is_same<target_<unspecified_< raw >    >                      , UP(base,16) >::value) );
}


