//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_DESCRIPTOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_DESCRIPTOR_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the descriptor class
 */

namespace nt2
{
  //============================================================================
  /*! descriptor is an extendable template class that gather informations about
   * container settings that has to be matched during the expression generation
   * process. Two expression with different descriptor usually can't be mixed.
   *
   * \tparam Dims    Dimensions of current expression
   * \tparam Bases   Base indexes of current expression
   * \tparam Storage Storage order of current expression
   *
   */
  //============================================================================
  template<class Dims, class Bases, class Storage> struct descriptor
  {
    typedef Dims    dimensions_type;
    typedef Bases   bases_type;
    typedef Storage storage_type;
  };
}

#endif
