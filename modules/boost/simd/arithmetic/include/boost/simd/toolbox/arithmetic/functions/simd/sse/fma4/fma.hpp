//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_FMA4_FMA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_FMA4_FMA_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_FMA4_SUPPORT

#include <boost/simd/toolbox/arithmetic/functions/fma.hpp>
#include <boost/include/functions/simd/plus.hpp>
#include <boost/include/functions/simd/multiplies.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::fma4_,
                      (A0),
                      ((simd_<single_<A0>,boost::simd::tag::sse_>))
                      ((simd_<single_<A0>,boost::simd::tag::sse_>))
                      ((simd_<single_<A0>,boost::simd::tag::sse_>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA)
      return _mm_macc_ps(a0, a1, a2);
#else
      return a0*a1+a2;
#endif
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::fma4_,
                      (A0),
                      ((simd_<double_<A0>,boost::simd::tag::sse_>))
                      ((simd_<double_<A0>,boost::simd::tag::sse_>))
                      ((simd_<double_<A0>,boost::simd::tag::sse_>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA)
      return _mm_macc_pd(a0, a1, a2);
#else
      return a0*a1+a2;
#endif
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::fma4_,
                      (A0),
                      ((simd_<single_<A0>,boost::simd::tag::avx_>))
                      ((simd_<single_<A0>,boost::simd::tag::avx_>))
                      ((simd_<single_<A0>,boost::simd::tag::avx_>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA)
      return _mm256_macc_ps(a0, a1, a2);
#else
      return a0*a1+a2;
#endif
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::fma4_,
                      (A0),
                      ((simd_<double_<A0>,boost::simd::tag::avx_>))
                      ((simd_<double_<A0>,boost::simd::tag::avx_>))
                      ((simd_<double_<A0>,boost::simd::tag::avx_>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA)
      return _mm256_macc_pd(a0, a1, a2);
#else
      return a0*a1+a2;
#endif
    }
  };
} } }

#endif
#endif
