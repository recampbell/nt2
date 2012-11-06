//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_STREAM_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_STREAM_HPP_INCLUDED

#include <boost/simd/toolbox/memory/functions/stream.hpp>
#include <boost/simd/toolbox/memory/functions/scalar/store.hpp>
#include <boost/simd/toolbox/memory/functions/details/store.hpp>
#include <boost/simd/sdk/functor/preprocessor/dispatch.hpp>
#include <boost/simd/memory/iterator_category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>

namespace boost { namespace simd { namespace ext
{
#if defined(BOOST_SIMD_HAS_SSE2_SUPPORT)
  /// INTERNAL ONLY - Integer stream with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::stream_, tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (scalar_< ints32_<A0> >)
                                      (iterator_< scalar_< unspecified_<A1> > >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 a0, A1 a1, A2 a2) const
    {
      _mm_stream_si32(reinterpret_cast<int*>(a1+a2), static_cast<int>(a0));
      return a0;
    }
  };

  /// INTERNAL ONLY - Integer stream without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::stream_, tag::cpu_
                                    , (A0)(A1)
                                    , (scalar_< ints32_<A0> >)
                                      (iterator_< scalar_< unspecified_<A1> > >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 a0, A1 a1) const
    {
      _mm_stream_si32(reinterpret_cast<int*>(a1), static_cast<int>(a0));
      return a0;
    }
  };
#endif

  /// INTERNAL ONLY - Scalar stream and store are equivalent
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::stream_
                                    , tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (unspecified_<A0>)
                                      (iterator_< scalar_< unspecified_<A1> > >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    BOOST_DISPATCH_RETURNS( 3
                          , (A0 const& a0, A1 a1, A2 a2)
                          , boost::simd::store(a0,a1,a2)
                          );
  };

  /// INTERNAL ONLY - Scalar stream and store are equivalent
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::stream_
                                    , tag::cpu_
                                    , (A0)(A1)
                                    , (unspecified_<A0>)
                                      (iterator_< scalar_< unspecified_<A1> > >)
                                    )
  {
    BOOST_DISPATCH_RETURNS( 2
                          , (A0 const& a0, A1 a1)
                          , boost::simd::store(a0,a1)
                          );
  };

  /// INTERNAL ONLY - Fusion sequence stream with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::stream_, tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (fusion_sequence_<A0>)
                                      (fusion_sequence_<A1>)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, A1 const& a1, A2 a2) const
    {
      meta::iterate < fusion::result_of::size<A1>::type::value>
                    ( details::storer < boost::simd::
                                        tag::stream_(A0, A1, A2)
                                      >(a0, a1, a2)
                    );
      return a0;
    }
  };

  /// INTERNAL ONLY - Fusion sequence stream without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::stream_, tag::cpu_
                                    , (A0)(A1)
                                    , (fusion_sequence_<A0>)
                                      (fusion_sequence_<A1>)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, A1 const& a1) const
    {
      meta::iterate < fusion::result_of::size<A1>::type::value>
                    ( details::storer < boost::simd::
                                        tag::stream_(A0, A1)
                                      >(a0, a1)
                    );
      return a0;
    }
  };
} } }

#endif
