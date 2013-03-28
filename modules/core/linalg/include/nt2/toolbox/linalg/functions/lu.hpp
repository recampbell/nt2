//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_LU_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_LU_HPP_INCLUDED

#include <nt2/include/functor.hpp>
#include <nt2/sdk/meta/size_as.hpp>
#include <nt2/sdk/meta/value_as.hpp>
#include <nt2/core/container/dsl/size.hpp>
#include <nt2/sdk/meta/tieable_hierarchy.hpp>
#include <nt2/core/container/dsl/value_type.hpp>

namespace nt2
{
  namespace tag
  {
    struct lu_ : ext::tieable_<lu_>
    {
      typedef ext::tieable_<lu_>  parent;
    };
  }

  /**
   * @brief Perform Lu factorization
   *
   * For any given matrix expression, performs a Lu factorization of
   * said matrix using the specified output layout for the Lu method.
   *
   * Contrary to the nt2::factorization::lu function which performs a partial evaluation of
   * said decomposition, nt2::lu returns a result similar to the Matlab interface,
   * making it useful for Matlab like usage.
   *
   * @param  xpr  Matrix expression to factorize
   *
   * @return A tuple-like type containing the factorized matrix and an indicator
   * of the success of the factorization
   **/
  NT2_FUNCTION_IMPLEMENTATION(tag::lu_, lu, 1)
  NT2_FUNCTION_IMPLEMENTATION(tag::lu_, lu, 2)
}

namespace nt2 { namespace ext
{
  template<class Domain, int N, class Expr>
  struct  size_of<tag::lu_,Domain,N,Expr>
        : meta::size_as<Expr,0>
  {};

  template<class Domain, int N, class Expr>
  struct  value_type<tag::lu_,Domain,N,Expr>
        : meta::value_as<Expr,0>
  {};
} }

#endif
