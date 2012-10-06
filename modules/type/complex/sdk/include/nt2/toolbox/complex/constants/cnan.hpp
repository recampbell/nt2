//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_COMPLEX_CONSTANTS_CNAN_HPP_INCLUDED
#define NT2_TOOLBOX_COMPLEX_CONSTANTS_CNAN_HPP_INCLUDED

#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/sdk/complex/imaginary.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

/*!
 * \ingroup nt2_complex
 * \defgroup nt2_complex_Cnan Cnan
 *
 * \par Description
 * Constant Cnan : Imaginary mask.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/i.hpp>
 * \endcode
 *
 * \alias:
 *    J
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T>
 *     meta::call<tag::Cnan(as_<T>)>::type
 *     Cnan();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Cnan
 * 
 * \return type T value
 *  
 *  
**/

namespace nt2
{
  namespace tag
  {
    /*!
     * \brief Define the tag Cnan of functor Cnan 
     *        in namespace nt2::tag for toolbox complex
    **/
    struct Cnan : ext::constant_<Cnan>
    {
      typedef imaginary<double> default_type; 
    };
  }

  BOOST_SIMD_CONSTANT_IMPLEMENTATION(nt2::tag::Cnan, Cnan)

}

#endif
