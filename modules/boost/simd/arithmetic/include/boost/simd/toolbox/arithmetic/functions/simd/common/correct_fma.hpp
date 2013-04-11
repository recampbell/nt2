//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_COMMON_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_COMMON_CORRECT_FMA_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/correct_fma.hpp>
#include <boost/simd/include/functions/simd/split.hpp>
#include <boost/simd/include/functions/simd/group.hpp>
#include <boost/simd/include/functions/simd/fma.hpp>

namespace boost { namespace simd { namespace ext
{

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::correct_fma_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<single_<A0>,X>))
                              ((simd_<single_<A0>,X>))
                              ((simd_<single_<A0>,X>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h, a2l, a2h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      boost::simd::split(a2, a2l, a2h);
      return group( boost::simd::fma(a0l, a1l, a2l)
                  , boost::simd::fma(a0h, a1h, a2h)
                  );
     }
  };
} } }


#endif
