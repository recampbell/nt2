//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_SDK_SIMD_DETAILS_IMPL_SSE_SSE4_1_IS_EQUAL_TO_HPP_INCLUDED
#define NT2_SDK_SIMD_DETAILS_IMPL_SSE_SSE4_1_IS_EQUAL_TO_HPP_INCLUDED

#include <nt2/sdk/meta/strip.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/make_integer.hpp>

namespace nt2 { namespace functors
{
  template<class Info>
  struct  call<is_equal_,tag::simd_(tag::arithmetic_,tag::sse_),double,Info>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A> struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = { _mm_cmpeq_pd(a0,a1) };
      return that;
    }
  };

  template<class Info>
  struct  call<is_equal_,tag::simd_(tag::arithmetic_,tag::sse_),float,Info>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A> struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = { _mm_cmpeq_ps(a0,a1) };
      return that;
    }
  };

  template<class Info>
  struct  call<is_equal_,tag::simd_(tag::arithmetic_,tag::sse_),int8_,Info>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A> struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = { _mm_cmpeq_epi8(a0,a1)  };
      return that;
    }
  };

  template<class Info>
  struct  call<is_equal_,tag::simd_(tag::arithmetic_,tag::sse_),int16_,Info>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A> struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = { _mm_cmpeq_epi16(a0,a1) };
      return that;
    }
  };
  template<class Info>
  struct  call<is_equal_,tag::simd_(tag::arithmetic_,tag::sse_),int32_,Info>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A> struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = { _mm_cmpeq_epi32(a0,a1) };
      return that;
    }
  };

  template<class Info>
  struct  call<is_equal_,tag::simd_(tag::arithmetic_,tag::sse_),int64_,Info>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A> struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = { _mm_cmpeq_epi64(a0,a1) };
      return that;
    }
  };
} }

#endif
