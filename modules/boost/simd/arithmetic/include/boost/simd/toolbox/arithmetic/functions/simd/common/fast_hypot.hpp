//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_COMMON_FAST_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_COMMON_FAST_HYPOT_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/fast_hypot.hpp>
#include <boost/simd/include/functions/simd/tofloat.hpp>
#include <boost/simd/include/functions/simd/abs.hpp>
#include <boost/simd/include/functions/simd/if_else.hpp>
#include <boost/simd/include/functions/simd/is_greater.hpp>
#include <boost/simd/include/functions/simd/is_greater_equal.hpp>
#include <boost/simd/include/functions/simd/sqrt.hpp>
#include <boost/simd/include/functions/simd/sqr.hpp>
#include <boost/simd/include/functions/simd/oneplus.hpp>
#include <boost/simd/include/functions/simd/plus.hpp>
#include <boost/simd/include/functions/simd/multiplies.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>
#include <boost/simd/include/functions/simd/correct_fma.hpp>
#include <boost/simd/include/constants/eps.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <iostream>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fast_hypot_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<arithmetic_<A0>,X>))
                                     ((simd_<arithmetic_<A0>,X>))
                                   )
  {
    typedef typename dispatch::meta::as_floating<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::fast_hypot(boost::simd::tofloat(a0),
                                     boost::simd::tofloat(a1));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fast_hypot_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<floating_<A0>,X>))
                                     ((simd_<floating_<A0>,X>))
                                   )
  {
    typedef typename dispatch::meta::as_floating<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
//      return boost::simd::sqrt(boost::simd::correct_fma(a0, a0, sqr(a1)));
      typedef typename meta::as_logical<A0>::type bA0;
      A0 x =  boost::simd::abs(a0);
      A0 y =  boost::simd::abs(a1);
      bA0 gtyx = boost::simd::gt(y,x);
      A0 xx = boost::simd::if_else(gtyx,y,x);
      A0 yy = boost::simd::if_else(gtyx,x,y);
      A0 r =  xx*boost::simd::sqrt(boost::simd::oneplus(boost::simd::sqr(yy/xx)));
      return boost::simd::if_else(boost::simd::ge(xx*boost::simd::Eps<A0>(), yy), xx, r);
    }
  };
} } }


#endif
