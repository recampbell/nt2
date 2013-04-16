//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_COMMON_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_COMMON_STORE_HPP_INCLUDED

#include <boost/simd/toolbox/memory/functions/store.hpp>
#include <boost/simd/toolbox/memory/functions/details/store.hpp>
#include <boost/simd/toolbox/memory/functions/details/check_ptr.hpp>
#include <boost/simd/include/functions/simd/unaligned_store.hpp>
#include <boost/simd/memory/iterator_category.hpp>
#include <boost/simd/sdk/functor/preprocessor/call.hpp>
#include <boost/simd/sdk/functor/hierarchy.hpp>
#include <boost/simd/sdk/meta/iterate.hpp>
#include <boost/dispatch/attributes.hpp>
#include <boost/dispatch/meta/mpl.hpp>
#include <boost/mpl/equal_to.hpp>

namespace boost { namespace simd { namespace ext
{
  /// INTERNAL ONLY - Regular SIMD store
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::store_
                                    , tag::cpu_
                                    , (A0)(A1)(A2)(X)
                                    , ((simd_< unspecified_<A0>, X >))
                                      (iterator_< unspecified_<A1> >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0 const& a0, A1 a1, A2 a2) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a1 + a2, BOOST_SIMD_CONFIG_ALIGNMENT);
      return boost::simd::unaligned_store(a0, a1, a2);
    }
  };

  /// INTERNAL ONLY - Regular SIMD store
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::store_
                                    , tag::cpu_
                                    , (A0)(A1)(X)
                                    , ((simd_< unspecified_<A0>, X >))
                                      (iterator_< unspecified_<A1> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0 const& a0, A1 a1) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a1, BOOST_SIMD_CONFIG_ALIGNMENT);
      return boost::simd::unaligned_store(a0, a1);
    }
  };

  /// INTERNAL ONLY - Scatter SIMD store
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF( boost::simd::tag::store_, tag::cpu_
                                      , (A0)(A1)(A2)(X)(Y)
                                      , (mpl::equal_to
                                          < boost::simd::meta::cardinal_of<A0>
                                          , boost::simd::meta::cardinal_of<A2>
                                          >
                                        )
                                      , ((simd_< unspecified_<A0>, X >))
                                        (iterator_< unspecified_<A1>  >)
                                        ((simd_< integer_<A2>, Y >))
                                      )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0 const& a0, A1 a1, A2 const& a2) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a1, BOOST_SIMD_CONFIG_ALIGNMENT);
      return boost::simd::unaligned_store(a0, a1, a2);
    }
  };

  /// INTERNAL ONLY - SIMD Fusion sequence store
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::store_, tag::cpu_
                                   , (A0)(A1)(A2)(X)
                                   , ((simd_< fusion_sequence_<A0>, X >))
                                     (fusion_sequence_<A1>)
                                     (generic_< integer_<A2> >)
                                   )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0 const& a0, A1 const& a1, A2 const& a2) const
    {
      static const int N = fusion::result_of::size<A1>::type::value;
      meta::iterate<N>( details::storer< boost::simd::
                                         tag::store_(A0, A1, A2)
                                       >(a0, a1, a2)
                      );
      return a0;
    }
  };
} } }

#endif
