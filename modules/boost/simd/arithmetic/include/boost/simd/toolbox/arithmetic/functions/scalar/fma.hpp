//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SCALAR_FMA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SCALAR_FMA_HPP_INCLUDED

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fma_, tag::cpu_
                                   , (A0)
                                   , (scalar_< arithmetic_<A0> >)
                                     (scalar_< arithmetic_<A0> >)
                                     (scalar_< arithmetic_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      return a0*a1+a2;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fma_, tag::cpu_
                                   , (A0)
                                   , (scalar_< double_<A0> >)
                                     (scalar_< double_<A0> >)
                                     (scalar_< double_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA) && (defined(BOOST_SIMD_DOUBLE_USE_CORRECT_FMA) || defined(BOOST_SIMD_ALWAYS_USE_CORRECT_FMA))
      //      fma is incorrect this is Bugzilla Bug 3268 for glibc
      A0 p, rp, s, rs;
      two_prod(a0, a1, p, rp);
      two_add(p, a2, s, rs);
      return s+(rp+rs);
#else
      return a0*a1+a2;
#endif
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fma_, tag::cpu_
                                   , (A0)
                                   , (scalar_< single_<A0> >)
                                     (scalar_< single_<A0> >)
                                     (scalar_< single_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
#if !defined(BOOST_SIMD_NEVER_USE_CORRECT_FMA) && (defined(BOOST_SIMD_SINGLE_USE_CORRECT_FMA) || defined(BOOST_SIMD_ALWAYS_USE_CORRECT_FMA))
      return static_cast<float>(static_cast<double>(a0)*static_cast<double>(a1)+static_cast<double>(a2));
#else
      return a0*a1+a2;
#endif
    }
  };
} } }


#endif
