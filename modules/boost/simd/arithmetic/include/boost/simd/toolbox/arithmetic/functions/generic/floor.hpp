//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_GENERIC_FLOOR_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_GENERIC_FLOOR_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/floor.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/functions/simd/is_gtz.hpp>
#include <boost/simd/include/functions/simd/toint.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::floor_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return a0;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::floor_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return boost::simd::if_else(boost::simd::is_gtz(a0),
                                  boost::simd::toint(a0),
                                  -boost::simd::toint(-a0));
    }
  };
} } }


#endif
