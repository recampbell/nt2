//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_UNALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_UNALIGNED_STORE_HPP_INCLUDED

#include <boost/simd/toolbox/memory/functions/unaligned_store.hpp>
#include <boost/simd/toolbox/memory/functions/scalar/store.hpp>
#include <boost/simd/sdk/functor/preprocessor/dispatch.hpp>

namespace boost { namespace simd { namespace ext
{
  /// INTERNAL ONLY - Scalar store and unaligned_store are equivalent
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (unspecified_<A0>)
                                      (iterator_< unspecified_<A1> >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    BOOST_DISPATCH_RETURNS( 3
                          , (A0 const& a0, A1 a1, A2 a2)
                          , boost::simd::store(a0,a1,a2)
                          );
  };

  /// INTERNAL ONLY - Scalar store and unaligned_store are equivalent
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_
                                    , (A0)(A1)
                                    , (unspecified_<A0>)
                                      (iterator_< unspecified_<A1> >)
                                    )
  {
    BOOST_DISPATCH_RETURNS( 2
                          , (A0 const& a0, A1 a1)
                          , boost::simd::store(a0,a1)
                          );
  };

  /// INTERNAL ONLY - Fusion sequence store with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (fusion_sequence_<A0>)
                                      (fusion_sequence_<A1>)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    BOOST_DISPATCH_RETURNS( 3
                          , (A0 const& a0, A1 const& a1, A2 a2)
                          , boost::simd::store(a0,a1)
                          );
  };

  /// INTERNAL ONLY - Scalar store and unaligned_store are equivalent
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_
                                    , (A0)(A1)
                                    , (fusion_sequence_<A0>)
                                      (fusion_sequence_<A1>)
                                    )
  {
    BOOST_DISPATCH_RETURNS( 2
                          , (A0 const& a0, A1 const& a1)
                          , boost::simd::store(a0,a1)
                          );
  };
} } }

#endif
