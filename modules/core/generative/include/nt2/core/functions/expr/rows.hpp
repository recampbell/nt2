//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_EXPR_ROWS_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_EXPR_ROWS_HPP_INCLUDED

#include <nt2/core/functions/rows.hpp>
#include <nt2/core/include/functions/as_size.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::rows_, tag::cpu_
                            , (A0)(T)
                            , ((ast_<A0, nt2::container::domain>))
                              (scalar_< arithmetic_<T> >)
                            )
  {
    BOOST_DISPATCH_RETURNS( 2, ( const A0& a0, T const& s )
                          , (nt2::rows(nt2::as_size(a0),s) )
                          )
  };
} }

#endif
