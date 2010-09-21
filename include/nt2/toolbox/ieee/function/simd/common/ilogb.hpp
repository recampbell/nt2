//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_ILOGB_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_COMMON_ILOGB_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/exponent.hpp>
#include <nt2/include/functions/seladd.hpp>
#include <nt2/include/functions/is_gtz.hpp>
#include <nt2/include/functions/predecessor.hpp>
#include <nt2/include/functions/dist.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for ilogb

  /////////////////////////////////////////////////////////////////////////////
  // Compute ilogb(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<ilogb_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
      {
	typedef typename meta::scalar_of<A0>::type sA0; 
        typedef typename meta::is_signed<sA0>::type sgn; 
	typedef typename meta::as_integer<A0, sgn>::type  type; };

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (5, (real_,signed_, uint8_t, uint16_t, uint32_t))
    )
    private:
    NT2_FUNCTOR_CALL_EVAL_IF(1,real_)
    {
      return exponent(a0);
    }

    // this macro is just a shorcut which is undefined at the end of this file
#define MKN(N) simd::native_cast<vtype##N>
    
    NT2_FUNCTOR_CALL_EVAL_IF(1,uint8_t)
    {
      typedef A0 vtype8; 
      static const vtype8& o = One<vtype8>();
      static const vtype8 mask =  integral_constant<vtype8, 0x7f>();
      typedef simd::native<uint16_t, typename meta::category_of<A0>::type::type> type; 
      vtype8 n = a0;
      vtype8 i = o;
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      n = b_and(MKN(8)(_mm_srli_epi16(n, 1)), mask);
      i = seladd(isnez(n), i, o); 
      return i-o;      
    }
    
    NT2_FUNCTOR_CALL_EVAL_IF(1,signed_)
    {
      typedef typename meta::as_integer<A0,unsigned>::type vtype; 
      static const A0 z = Zero<A0>();
      vtype tmp = ilogb(simd::native_cast<vtype>(a0)); 
      return seladd(isgtz(a0), z, simd::native_cast<A0>(tmp)); 
    }
    
    NT2_FUNCTOR_CALL_EVAL_IF(1,uint16_t)
    {
      typedef A0 vtype16; 
      typedef simd::native<uint8_t, typename meta::category_of<A0>::type::type>  vtype8;
      static const vtype8& z = Zero<vtype8>();
      static const vtype8& o = One<vtype8>();
      static const vtype16 mask =  integral_constant<vtype16, 0x7f7f > (); 
      vtype8 i = sel(iseqz(MKN(8)(a0)), z, o);
      //      vtype8 i = sb2b(isnez((vtype8)a0)); 
      vtype8 n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(a0, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(16)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      
      static const vtype16 mask1 = integral_constant<vtype16, 0x00ff>();
      static const vtype16 mask2 = integral_constant<vtype16, 0xff00>();
      static const vtype16 huit  = integral_constant<vtype16, 8u>();
      
      vtype16 yy = b_and(MKN(16)(i), mask2);
      vtype16 zz = b_and(MKN(16)(i), mask1); 
      vtype16 xx = sel(isnez(yy), MKN(16)(_mm_srli_epi16(yy, 8))+huit, zz);
      return MKN(16)(isnez(MKN(8)(xx))&(MKN(8)(xx)-o)); 
				    }

    NT2_FUNCTOR_CALL_EVAL_IF(1,uint32_t)
    {
      typedef A0 vtype32; 
      typedef simd::native<uint8_t, typename meta::category_of<A0>::type::type>  vtype8;
      static const vtype8& z = Zero<vtype8>();
      static const vtype8& o = One<vtype8>();
      static const vtype32 mask =  integral_constant<vtype32, 0x7f7f7f7f>(); 
      //      vtype8 i = boolean(isnez((vtype8)a0)); 
      vtype8 i = sel(iseqz(MKN(8)(a0)), z, o);
      vtype8 n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(a0, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      n = MKN(8)(b_and(MKN(32)(_mm_srli_epi16(n, 1)), mask));
      i = seladd(isnez(n), i, o);
      static const vtype32 mask1 = integral_constant<vtype32,0x000000ff>();
      static const vtype32 mask2 = integral_constant<vtype32,0x0000ff00>();
      static const vtype32 mask3 = integral_constant<vtype32,0x00ff0000>();
      static const vtype32 mask4 = integral_constant<vtype32,0xff000000>(); 
      static const vtype32 huit  = integral_constant<vtype32,8>();
      static const vtype32 seize = integral_constant<vtype32,16u>();
      static const vtype32 v4    = integral_constant<vtype32,24u>(); 
      
      vtype32 yy = b_and(MKN(32)(i), mask4);
      vtype32 zz = b_and(MKN(32)(i), mask3);
      vtype32 tt = b_and(MKN(32)(i), mask2);
      vtype32 uu = b_and(MKN(32)(i), mask1); 
      vtype32 xx = sel(isnez(yy), MKN(32)(_mm_srli_epi32(yy,24))+v4,
		     sel(isnez(zz), MKN(32)(_mm_srli_epi32(zz,16))+seize,
			 sel(isnez(tt), MKN(32)(_mm_srli_epi32(tt,8))+huit,
			     uu))); 
      return MKN(32)(isnez(MKN(8)(xx))&(MKN(8)(xx)-o)); 
    }
    
#undef MKN
    
  };
} }

      
#endif
