//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_GENERIC_FAST_SINCOSD_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_GENERIC_FAST_SINCOSD_HPP_INCLUDED
#include <nt2/toolbox/trigonometric/functions/fast_sincosd.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <nt2/toolbox/trigonometric/functions/scalar/impl/trigo.hpp>
#include <nt2/toolbox/trigonometric/functions/simd/common/impl/trigo.hpp>
#include <boost/simd/sdk/simd/meta/is_native.hpp>
#include <nt2/sdk/meta/as_floating.hpp>

namespace nt2 { namespace ext
{

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::fast_sincosd_
                            , tag::cpu_
                            , (A0)
                            , ((generic_< floating_<A0> >))
                              ((generic_< floating_<A0> >))
                            )
  {
    typedef A0 result_type;
    typedef typename boost::simd::meta::is_native<A0>::type is_native_t;
    BOOST_FORCEINLINE result_type operator()(A0 const& a0,A0 & a2) const
    {
      return impl::trig_base <A0,degree_tag,is_native_t,clipped_pio4_>::sincosa(a0,a2);
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::fast_sincosd_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {
    typedef std::pair<A0, A0>                      result_type;
    typedef typename boost::simd::meta::is_native<A0>::type     is_native_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0) const
    {
      result_type res;
      res.first = impl::trig_base <A0,degree_tag,is_native_t,clipped_pio4_>::sincosa(a0,res.second);
      return res;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::fast_sincosd_, tag::cpu_
                            , (A0)
                            , ((generic_< floating_<A0> >))
                              ((generic_< floating_<A0> >))
                              ((generic_< floating_<A0> >))
                            )
  {
    typedef void result_type;
    typedef typename boost::simd::meta::is_native<A0>::type is_native_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0,A0 & a1,A0 & a2) const
    {
      a1 = impl::trig_base <A0,degree_tag,is_native_t,clipped_pio4_>::sincosa(a0,a2);
    }
  };

} }

#endif
