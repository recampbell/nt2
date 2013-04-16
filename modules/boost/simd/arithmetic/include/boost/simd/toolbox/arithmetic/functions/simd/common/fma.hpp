//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_COMMON_FMA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_COMMON_FMA_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/fma.hpp>
#include <boost/simd/include/functions/simd/multiplies.hpp>
#include <boost/simd/include/functions/simd/plus.hpp>
#include <boost/simd/include/functions/simd/two_prod.hpp>
#include <boost/simd/include/functions/simd/two_add.hpp>
#include <boost/simd/include/functions/simd/split.hpp>
#include <boost/simd/include/functions/simd/group.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, tag::cpu_,
                      (A0)(X),
                      ((simd_<integer_<A0>,X>))
                      ((simd_<integer_<A0>,X>))
                      ((simd_<integer_<A0>,X>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      return a0*a1+a2;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fma_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<single_<A0>,X>))
                              ((simd_<single_<A0>,X>))
                              ((simd_<single_<A0>,X>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA) && (defined(BOOST_SIMD_DOUBLE_USE_CORRECT_FMA) || defined(BOOST_SIMD_ALWAYS_USE_CORRECT_FMA))
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h, a2l, a2h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      boost::simd::split(a2, a2l, a2h);
      return boost::simd::group( a0l*a1l+a2l, a0h*a1h+a2h);
#else
      return a0*a1+a2;
#endif
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fma_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<double_<A0>,X>))
                              ((simd_<double_<A0>,X>))
                              ((simd_<double_<A0>,X>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA) && (defined(BOOST_SIMD_DOUBLE_USE_CORRECT_FMA) || defined(BOOST_SIMD_ALWAYS_USE_CORRECT_FMA))
      A0 p, rp, s, rs;
      boost::simd::two_prod(a0, a1, p, rp);
      boost::simd::two_add(p, a2, s, rs);
      return s+(rp+rs);
#else
      return a0*a1+a2;
#endif
     }
  };


} } }
#endif
