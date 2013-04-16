//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_FMA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_FMA_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
/*
  a true hard wired fma functor conform to the "one rounding" definition of fused multiply-add
  is not available on every system.
  All the way, it can always be emulated, but at a cost (at least 2 times slower than a*b+c)
  which is not always acceptable: fma must be both accurate and fast.
  The functor correct_fma of NT2 (which is never called in NT2 by any other functor)
  always computes the correct fma result by emulation or by using  processor intrinsics
  (if they exist).


  fma call depends of four defines:

  BOOST_SIMD_SINGLE_USE_CORRECT_FMA
  BOOST_SIMD_DOUBLE_USE_CORRECT_FMA
  BOOST_SIMD_ALWAYS_USE_CORRECT_FMA
  BOOST_SIMD_NEVER_USE_CORRECT_FMA

  By default none is defined and fma merely computes a0*a1+a2, except in simd
  if the corresponding intrinsics exist.

  The rationale of the default is: "use the speediest way",  and if occurs that if the
  simd intrinsics exist precision and speed are simultaneously better.

  if BOOST_SIMD_SINGLE_USE_CORRECT_FMA is defined, computations in float use correct_fma

  if BOOST_SIMD_DOUBLE_USE_CORRECT_FMA is defined, computations in double use correct_fma

  if BOOST_SIMD_ALWAYS_USE_CORRECT_FMA is defined, all computations use correct_fma

  if BOOST_SIMD_NEVER_USE_CORRECT_FMA is defined no computations use correct fma (except
  correct_fma itself!) but always a0*a1+a2, as the extra precision in rare cases has to
  be avoided. This define has precedence over the other ones.

  Note that the optimization process made by NT2 implies that expressions of
  the form a*b+c are automagically trnsformed to fma(a, b, c).
  If you do not want this to happen do:
  z =  a*b;
  z += c;
 */
/*!
 * \ingroup boost_simd_arithmetic
 * \defgroup boost_simd_arithmetic_fma fma
 *
 * \par Description
 * computes \c a0*a1+a2, but the computation with only one rounding operation
 * is only done on architectures possessing this hard wired capability
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/fma.hpp>
 * \endcode
 *
 * \par Aliases
 * \arg madd
 * \arg fam
 * \arg amul
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::fma_(A0,A0,A0)>::type
 *     fma(const A0 & a0,const A0 & a1,const A0 & a2);
 * }
 * \endcode
 *
 * \param a0 the first parameter of fma
 * \param a1 the second parameter of fma
 * \param a2 the third parameter of fma
 *
 * \return a value of the common type of the parameters
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag fma_ of functor fma
     *        in namespace boost::simd::tag for toolbox boost.simd.arithmetic
    **/
    struct fma_ : ext::elementwise_<fma_> { typedef ext::elementwise_<fma_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::fma_, fma, 3)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::fma_, madd, 3)

  BOOST_DISPATCH_FUNCTION_INTERFACE(tag::fma_, fam, 3)
  {
    typename boost::dispatch::make_functor<tag::fma_, A0>::type callee;
    return callee(a1, a2, a0);
  }

  BOOST_DISPATCH_FUNCTION_INTERFACE(tag::fma_, amul, 3)
  {
    typename boost::dispatch::make_functor<tag::fma_, A0>::type callee;
    return callee(a1, a2, a0);
  }

} }

#endif
