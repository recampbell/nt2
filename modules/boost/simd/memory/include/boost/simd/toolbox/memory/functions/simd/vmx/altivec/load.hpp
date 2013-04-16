//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_LOAD_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_VMX_SUPPORT

#include <boost/simd/toolbox/memory/functions/load.hpp>
#include <boost/simd/toolbox/memory/functions/details/char_helper.hpp>
#include <boost/simd/toolbox/memory/functions/details/check_ptr.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>

namespace boost { namespace simd { namespace ext
{
  /// INTERNAL ONLY - SIMD load with offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::load_
                                    , boost::simd::tag::altivec_
                                    , (A0)(A1)(A2)
                                    , (iterator_< scalar_< arithmetic_<A0> > >)
                                      (scalar_< integer_<A1> >)
                                      ((target_
                                        < simd_ < arithmetic_<A2>
                                                , boost::simd::tag::altivec_
                                                >
                                        >
                                      ))
                            )
  {

    typedef typename A2::type result_type;

    BOOST_FORCEINLINE result_type operator()(A0 a0, A1 a1, const A2&) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a0 + a1, sizeof(result_type));
      return vec_ld(a1*sizeof(*a0), char_helper(a0));
    }
  };

  /// INTERNAL ONLY - SIMD load without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::load_
                                    , boost::simd::tag::altivec_
                                    , (A0)(A2)
                                    , (iterator_< scalar_< arithmetic_<A0> > >)
                                      ((target_
                                        < simd_ < arithmetic_<A2>
                                                , boost::simd::tag::altivec_
                                                >
                                        >
                                      ))
                            )
  {
    typedef typename A2::type result_type;

    BOOST_FORCEINLINE result_type operator()(A0 a0, const A2&) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a0, sizeof(result_type));
      return vec_ld(0, char_helper(a0));
    }
  };

  /// INTERNAL ONLY - Load with static misalignment without offset
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::load_
                                    , boost::simd::tag::altivec_
                                    , (A0)(A2)(A3)
                                    , (iterator_< scalar_< arithmetic_<A0> > >)
                                      ((target_
                                        < simd_ < arithmetic_<A2>
                                                , boost::simd::tag::altivec_
                                                >
                                        >
                                      ))
                                      (mpl_integral_< scalar_< integer_<A3> > >)
                                    )
  {
    typedef typename A2::type result_type;

    static const std::size_t cardinal = meta::cardinal_of<result_type>::value;
    static const typename A3::value_type unalignment = A3::value % cardinal;

    BOOST_FORCEINLINE result_type operator()(A0 a0, const A2&, const A3&) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a0-A3::value, sizeof(result_type));
      return eval( a0, boost::mpl::bool_<!unalignment>() );
    }

    // Periodic case - Just load as normal
    BOOST_FORCEINLINE result_type eval( A0 a0, boost::mpl::true_ const&) const
    {
      return boost::simd::load<result_type>(a0);
    }

    // Non-periodic case
    BOOST_FORCEINLINE result_type eval(A0 a0, boost::mpl::false_ const&) const
    {
      typedef typename meta::scalar_of<result_type>::type scalar_type;

      // Load aligned sources
      result_type a  = simd::load<result_type>(a0-unalignment);
      result_type b  = simd::load<result_type>(a0-unalignment,cardinal);

      // Shift everything in place
      return vec_sld( a() , b() ,sizeof(scalar_type) * unalignment );
    }
  };
} } }

#endif
#endif
