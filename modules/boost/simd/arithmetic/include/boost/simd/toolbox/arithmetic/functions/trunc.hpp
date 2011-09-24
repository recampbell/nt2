//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_TRUNC_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_TRUNC_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>


/*!
 * \internal functor \endinternal
 * \ingroup boost_simd_arithmetic
 * \defgroup trunc trunc function
 *
 * \par Description
 * TODO Put description here
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/trunc.hpp>
 * \endcode
 * 
 * \par Alias 
 * \arg fix
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::trunc_(A0)>::type
 *     trunc(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 is the unique parameter of trunc
 * 
 * \return a value of the same type as the parameter
 *  
 * \internal end_functor \endinternal
**/
 
 
 
 
 
 
 
 
 
 
 
 
 
 
namespace boost { namespace simd { namespace tag
  {         
    /*!
     * \internal tag \endinternal
     * \file
     * \brief Define the tag trunc_ of functor trunc 
     *        in namespace boost::simd::tag
     * \internal end_tag \endinternal
    **/
    struct trunc_ {};
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::trunc_, trunc, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::trunc_, fix, 1)
} }
 
#endif

// modified by jt the 25/12/2010
