//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_COMPARE_LESS_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_COMPARE_LESS_HPP_INCLUDED

#include <nt2/include/functions/is_less.hpp>
#include <nt2/include/functions/is_greater.hpp>
#include <nt2/include/functions/reversebits.hpp>


////////////////////////////////////////////////////////////////////////////////
// Local shared helper
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace details
{
  template<class T>
  inline bool compare_less_helper(T mask_lt, T mask_gt)
  {
    unsigned int mlt = nt2::reversebits(mask_lt);
    unsigned int mgt = nt2::reversebits(mask_gt);
    return (mlt > mgt) && mlt; 
  }
} }

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( tag::compare_less_, tag::cpu_
                            , (A0)
                            , ((simd_<double_<A0>,tag::sse_>))
                              ((simd_<double_<A0>,tag::sse_>))
                            )
  {
    typedef bool result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      unsigned int mask_a_lt_b =  _mm_movemask_pd(lt(a0,a1));
      unsigned int mask_a_gt_b =  _mm_movemask_pd(gt(a0,a1));
      return details::compare_less_helper(mask_a_lt_b,mask_a_gt_b);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::compare_less_, tag::cpu_
                            , (A0)
                            , ((simd_<float_<A0>,tag::sse_>))
                              ((simd_<float_<A0>,tag::sse_>))
                            )
  {
    typedef bool result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      unsigned int mask_a_lt_b =  _mm_movemask_ps(lt(a0,a1));
      unsigned int mask_a_gt_b =  _mm_movemask_ps(gt(a0,a1));
      return details::compare_less_helper(mask_a_lt_b,mask_a_gt_b);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( tag::compare_less_, tag::cpu_
                            , (A0)
                            , ((simd_<integer_<A0>,tag::sse_>))
                              ((simd_<integer_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      unsigned int mask_a_lt_b =  _mm_movemask_epi8(lt(a0,a1));
      unsigned int mask_a_gt_b =  _mm_movemask_epi8(gt(a0,a1));
      return details::compare_less_helper(mask_a_lt_b,mask_a_gt_b);
    }
  };
} }

#endif
