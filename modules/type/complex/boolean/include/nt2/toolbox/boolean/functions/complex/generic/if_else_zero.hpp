//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BOOLEAN_FUNCTIONS_COMPLEX_GENERIC_IF_ELSE_ZERO_HPP_INCLUDED
#define NT2_TOOLBOX_BOOLEAN_FUNCTIONS_COMPLEX_GENERIC_IF_ELSE_ZERO_HPP_INCLUDED
#include <nt2/toolbox/boolean/functions/if_else_zero.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/functions/bitwise_and.hpp>
#include <nt2/sdk/simd/logical.hpp>
#include <nt2/sdk/meta/enable_if_type.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>
#include <boost/simd/sdk/meta/is_bitwise_logical.hpp>
#include <nt2/sdk/complex/hierarchy.hpp>
#include <nt2/include/functions/is_nez.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_zero_, tag::cpu_, (A0)(A1)
                              , (generic_< logical_<A0> >)
                              (generic_< complex_<floating_<A1> > >)
                              )
  {
    typedef A1 result_type;
    result_type  operator()(A0 const& a0, A1 const& a1) const
    {
      return result_type(if_else_zero(a0, real(a1)), if_else_zero(a0, imag(a1))); 
    }
  };
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_zero_, tag::cpu_, (A0)(A1)
                              , (generic_< complex_<floating_<A0> > >)
                                (generic_< complex_<floating_<A1> > >)
                              )
  {
    typedef A1 result_type;
    result_type  operator()(A0 const& a0, A1 const& a1) const
    {      
      return result_type(if_else_zero(is_nez(a0), real(a1)), if_else_zero(is_nez(a0), imag(a1))); 
    }
  };
 
} } 

#endif
