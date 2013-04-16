//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_SSE_SSE2_UNALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_SSE_SSE2_UNALIGNED_LOAD_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT

#include <boost/simd/toolbox/memory/functions/unaligned_load.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/simd/sdk/simd/category.hpp>
#include <boost/dispatch/attributes.hpp>

namespace boost { namespace simd { namespace ext
{
  /// INTERNAL ONLY - double unaligned_load with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_load_
                                    , boost::simd::tag::sse2_
                                    , (A0)(A1)(A2)
                                    , (iterator_< scalar_< double_<A0> > >)
                                      (scalar_< fundamental_<A1> >)
                                      ((target_< simd_< double_<A2>
                                                      , boost::simd::tag::sse_
                                                      >
                                                >
                                      ))
                                    )
  {
    typedef typename A2::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 a0, A1 a1, const A2&) const
    {
      return _mm_loadu_pd(a0+a1);
    }
  };

  /// INTERNAL ONLY - double unaligned_load without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_load_
                                    , boost::simd::tag::sse2_
                                    , (A0)(A1)
                                    , (iterator_< scalar_< double_<A0> > >)
                                      ((target_< simd_< double_<A1>
                                                      , boost::simd::tag::sse_
                                                      >
                                                >
                                      ))
                                    )
  {
    typedef typename A1::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 a0, const A1&) const
    {
      return _mm_loadu_pd(a0);
    }
  };

  /// INTERNAL ONLY - single unaligned_load with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_load_
                                    , boost::simd::tag::sse2_
                                    , (A0)(A1)(A2)
                                    , (iterator_< scalar_< single_<A0> > >)
                                      (scalar_< fundamental_<A1> >)
                                      ((target_< simd_< single_<A2>
                                                      , boost::simd::tag::sse_
                                                      >
                                                >
                                      ))
                                    )
  {
    typedef typename A2::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 a0, A1 a1, const A2&) const
    {
      return _mm_loadu_ps(a0+a1);
    }
  };

  /// INTERNAL ONLY - single unaligned_load without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_load_
                                    , boost::simd::tag::sse2_
                                    , (A0)(A1)
                                    , (iterator_< scalar_< single_<A0> > >)
                                      ((target_< simd_< single_<A1>
                                                      , boost::simd::tag::sse_
                                                      >
                                                >
                                      ))
                                    )
  {
    typedef typename A1::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 a0, const A1&) const
    {
      return _mm_loadu_ps(a0);
    }
  };

  /// INTERNAL ONLY - integers unaligned_load with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_load_
                                    , boost::simd::tag::sse2_
                                    , (A0)(A1)(A2)
                                    , (iterator_< scalar_< integer_<A0> > >)
                                      (scalar_< fundamental_<A1> >)
                                      ((target_< simd_< integer_<A2>
                                                      , boost::simd::tag::sse_
                                                      >
                                                >
                                      ))
                                    )
  {
    typedef typename A2::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 a0, A1 a1, const A2&) const
    {
      return _mm_loadu_si128(reinterpret_cast<__m128i const*>(a0+a1));
    }
  };

  /// INTERNAL ONLY - integers unaligned_load without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_load_
                                    , boost::simd::tag::sse2_
                                    , (A0)(A1)
                                    , (iterator_< scalar_< integer_<A0> > >)
                                      ((target_< simd_< integer_<A1>
                                                      , boost::simd::tag::sse_
                                                      >
                                                >
                                      ))
                                    )
  {
    typedef typename A1::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 a0, const A1&) const
    {
      return _mm_loadu_si128(reinterpret_cast<__m128i const*>(a0));
    }
  };
} } }

#endif
#endif
