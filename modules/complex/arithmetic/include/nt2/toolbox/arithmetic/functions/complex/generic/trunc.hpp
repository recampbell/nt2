//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTIONS_COMPLEX_GENERIC_TRUNC_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTIONS_COMPLEX_GENERIC_TRUNC_HPP_INCLUDED
#include <nt2/toolbox/arithmetic/functions/trunc.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/include/functions/hypot.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::trunc_, tag::cpu_, (A0)
                            , (generic_< complex_< arithmetic_<A0> > >)
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return result_type(trunc(real(a0)),trunc(imag(a0))); 
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::trunc_, tag::cpu_, (A0)
                            , (generic_< imaginary_< arithmetic_<A0> > >)
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return result_type(nt2::trunc(imag(a0))); 
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::trunc_, tag::cpu_, (A0)
                            , (generic_< dry_< arithmetic_<A0> > >)
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return result_type(nt2::trunc(real(a0))); 
    }
  };
  
} }

#endif
