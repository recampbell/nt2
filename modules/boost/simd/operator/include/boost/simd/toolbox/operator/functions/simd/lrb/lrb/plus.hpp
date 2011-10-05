//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_PLUS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_PLUS_HPP_INCLUDED
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// operator binary plus
////////////////////////////////////////////////////////////////////////////////
#include <boost/dispatch/meta/strip.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>

/////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      std::cout << "plus" << std::endl; 
      A0 that = { _mm512_add_pd(a0,a1) };
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { _mm512_add_ps(a0,a1) };
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<ints32_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<ints32_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { _mm512_add_pi(a0,a1) };
      return that;
    }
  };
  
//   BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_, boost::simd::tag::lrb_
//                             , (A0)
//                             , ((simd_<ints64_<A0>,boost::simd::tag::lrb_>))
//                               ((simd_<ints64_<A0>,boost::simd::tag::lrb_>))
//                             )
//   {
//     typedef A0 result_type;

//     BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
//     {
//       A0 that = { _mm512_add_pq(a0,a1) };//Do not exist
//       return that;
//     }
//   };
  
} } }


#endif
