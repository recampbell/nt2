//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE3_IS_EQZ_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE3_IS_EQZ_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for is_eqz


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is int64_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<is_eqz_,tag::simd_(tag::arithmetic_),int64_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(1)
    {
      typedef simd::native<int32_t, tag::sse_> itype;
      typedef simd::native<float, tag::sse_>   ftype;
      ftype tmp1 = simd::native_cast<ftype>(eq(simd::native_cast<itype>(a0),Zero<itype>()));
      A0  l = simd::native_cast<A0>(_mm_moveldup_ps(tmp1));
      A0  h = simd::native_cast<A0>(_mm_movehdup_ps(tmp1));
      return b_and(l,h);
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<is_eqz_,tag::simd_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(1)
    {
      return eq(a0,Zero<A0>());
    }
  };

} }

#endif
/// Revised by jt the 15/11/2010
