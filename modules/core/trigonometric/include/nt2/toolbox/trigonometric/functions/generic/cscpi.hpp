//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_GENERIC_CSCPI_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_GENERIC_CSCPI_HPP_INCLUDED
#include <nt2/toolbox/trigonometric/functions/cscpi.hpp>
#include <nt2/include/constants/nan.hpp>
#include <nt2/include/constants/inf.hpp>
#include <nt2/include/functions/sinpi.hpp>
#include <nt2/include/functions/if_else_allbits.hpp>
#include <nt2/include/functions/if_allbits_else.hpp>
#include <nt2/include/functions/logical_andnot.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_flint.hpp>
#include <nt2/include/functions/rec.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::cscpi_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    inline result_type operator()(A0 const& a0)const
    {
      return nt2::if_else_nan(nt2::is_eqz(a0), nt2::Inf<result_type>());
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::cscpi_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return nt2::if_nan_else(nt2::logical_andnot(nt2::is_flint(a0),
                                                  nt2::is_eqz(a0)),
                              nt2::rec(nt2::sinpi(a0)));
    }
  };
} }


#endif
