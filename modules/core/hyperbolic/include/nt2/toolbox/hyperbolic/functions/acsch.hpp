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
#ifndef NT2_TOOLBOX_HYPERBOLIC_FUNCTIONS_ACSCH_HPP_INCLUDED
#define NT2_TOOLBOX_HYPERBOLIC_FUNCTIONS_ACSCH_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup hyperbolic
 * \defgroup hyperbolic_acsch acsch
 *
 * \par Description
 * hyperbolic cosecant argument \f$\mathop{\textrm{asinh}}(1/a_0)\f$
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/acsch.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   template <class A0>
 *     meta::call<tag::acsch_(A0)>::type
 *     acsch(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of acsch
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace nt2 { namespace tag
  {
    /*!
     * \brief Define the tag acsch_ of functor acsch
     *        in namespace nt2::tag for toolbox hyperbolic
    **/
    struct acsch_ : ext::elementwise_<acsch_> { typedef ext::elementwise_<acsch_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::acsch_, acsch, 1)
}

#endif

// modified by jt the 25/12/2010
