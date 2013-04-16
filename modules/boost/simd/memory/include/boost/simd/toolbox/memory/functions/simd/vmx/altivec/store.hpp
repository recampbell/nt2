//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_STORE_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_VMX_SUPPORT

#include <boost/simd/toolbox/memory/functions/store.hpp>
#include <boost/simd/toolbox/memory/functions/details/char_helper.hpp>
#include <boost/simd/toolbox/memory/functions/details/check_ptr.hpp>
#include <boost/simd/memory/iterator_category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/dispatch/attributes.hpp>

namespace boost { namespace simd { namespace ext
{
  /// INTERNAL ONLY - SIMD store with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::store_
                                    , boost::simd::tag::altivec_
                                    , (A0)(A1)(A2)
                                    , ((simd_ < arithmetic_<A0>
                                              , boost::simd::tag::altivec_
                                              >
                                      ))
                                      (iterator_< scalar_< arithmetic_<A1> > >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type operator()(const A0& a0, A1 a1, A2 a2) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a1 + a2, sizeof(result_type));
      vec_st(a0(), a2*sizeof(*a1), char_helper(a1));
      return a0;
    }
  };

  /// INTERNAL ONLY - SIMD store without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::store_
                                    , boost::simd::tag::altivec_
                                    , (A0)(A1)
                                    , ((simd_ < arithmetic_<A0>
                                              , boost::simd::tag::altivec_
                                              >
                                      ))
                                      (iterator_< scalar_< arithmetic_<A1> > >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type operator()(const A0& a0, A1 a1) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a1, sizeof(result_type));
      vec_st(a0(), 0, char_helper(a1));
      return a0;
    }
  };
} } }

#endif
#endif
