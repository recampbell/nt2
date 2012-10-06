//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_POLYNOMIALS_FUNCTIONS_LAGUERRE_HPP_INCLUDED
#define NT2_TOOLBOX_POLYNOMIALS_FUNCTIONS_LAGUERRE_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

namespace nt2 { namespace tag
  {         
    struct laguerre_ : ext::elementwise_<laguerre_> { typedef ext::elementwise_<laguerre_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::laguerre_, laguerre, 2)
}
 
 
#endif

// modified by jt the 25/12/2010