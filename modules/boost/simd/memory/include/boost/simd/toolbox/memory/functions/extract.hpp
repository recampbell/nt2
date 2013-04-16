//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_EXTRACT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_EXTRACT_HPP_INCLUDED

/*!
  @file
  @brief Defines and implements the extract function
**/

#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/dispatch/meta/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
      @brief Extract generic tag

      Represents the extract function in generic contexts like functor creation.

      @par Models:
      @ref FormalHierarchy
    **/
    struct extract_ : tag::formal_
    {
      /// @brief Parent hierarchy
      typedef tag::formal_  parent;
    };
  }


/*!
 * \ingroup boost_simd_operator
 * \defgroup boost_simd_operator_extract extract
 *
 * \par Description
 * extract scalar from SIMD vector \c a0 at position \c a1
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/extract.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template<typename A0, typename A1> inline
 *   typename boost::dispatch::meta::call<tag::extract_(A0 const&, A1 const&)>::type
 *   extract(A0 const& a0, A1 const& a1);
 * }
 * \endcode
 *
 * \param a0 SIMD vector
 * \param a1 offset to extract at
 *
 * \return scalar
 *
**/
  template<typename A0,typename A1>
  BOOST_FORCEINLINE
  typename boost::dispatch::meta::call<tag::extract_(A0 const&, A1 const&)>::type
  extract(A0 const& a0,A1 const& a1)
  {
    return typename boost::dispatch::make_functor<tag::extract_, A0>::type()(a0,a1);
  }

  template<typename A0,typename A1>
  BOOST_FORCEINLINE
  typename boost::dispatch::meta::call<tag::extract_(A0&, A1 const&)>::type
  extract(A0& a0,A1 const& a1)
  {
    return typename boost::dispatch::make_functor<tag::extract_, A0>::type()(a0,a1);
  }
} }

#endif
