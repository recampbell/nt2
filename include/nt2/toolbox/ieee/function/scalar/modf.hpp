//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_MODF_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_MODF_HPP_INCLUDED
#include <boost/fusion/tuple.hpp>


namespace nt2 { namespace functors
{

  //  no special validate for modf

  /////////////////////////////////////////////////////////////////////////////
  // Compute modf(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<modf_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename boost::result_of<meta::floating(A0)>::type etype;
      typedef boost::fusion::tuple<etype, etype>                   type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_CALL_RETURN_TYPE(1)::type res;
      typedef typename boost::result_of<meta::floating(A0)>::type etype;
      boost::fusion::at_c<0>(res) = trunc(a0);
      boost::fusion::at_c<1>(res)= a0 - boost::fusion::at_c<0>(res);
      return res;
    }
  };
} }


      
#endif
