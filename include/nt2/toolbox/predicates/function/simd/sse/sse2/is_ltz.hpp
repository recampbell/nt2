//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE2_IS_LTZ_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE2_IS_LTZ_HPP_INCLUDED
#include <nt2/sdk/meta/templatize.hpp>
#include <nt2/sdk/constant/boolean.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/boolean.hpp>
#include <nt2/sdk/meta/strip.hpp>

#include <nt2/include/functions/is_ltz.hpp>

namespace nt2 { namespace functors
{
  //  no special validate for is_ltz


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is unsigned_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<is_ltz_,tag::simd_(tag::arithmetic_),unsigned_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>: meta::strip<A0>{};

    NT2_FUNCTOR_CALL(1)
    {
      details::ignore_unused(a0);
      return False<A0>();
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is int64_t
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<is_ltz_,tag::simd_(tag::arithmetic_),int64_t,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>: meta::strip<A0>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef simd::native<typename meta::int32_t_<A0>::type,tag::sse_> type;
      const type tmp1 = is_ltz(simd::native_cast<type>(a0));
      const type tmp = { _mm_shuffle_epi32(tmp1, _MM_SHUFFLE(2, 2, 0, 0))};
      return  simd::native_cast<A0>(tmp);
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<is_ltz_,tag::simd_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>: meta::strip<A0>{};

    NT2_FUNCTOR_CALL(1)
    {
        return lt(a0,Zero<A0>());
    }
  };

} }

#endif
/// Revised by jt the 15/11/2010
