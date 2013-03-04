//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 standard toolbox - frexp/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of standard components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 06/03/2011
///
#include <nt2/toolbox/standard/include/functions/frexp.hpp>
#include <nt2/include/functions/max.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/include/functions/mantissa.hpp>
#include <nt2/include/functions/exponent.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>


NT2_TEST_CASE_TPL ( frexp_float_1_0,  (float))
{

  using nt2::standard::frexp;
  using nt2::standard::tag::frexp_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<frexp_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef boost::fusion::vector<T,nt2::int32_t> wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-100), T(100));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        r_t r = nt2::standard::frexp(a0);
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,0>::type>::type r_t0;
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,1>::type>::type r_t1;
//         r_t0 r0 = boost::fusion::get<0>(r);
//         r_t1 r1 = boost::fusion::get<1>(r);
        NT2_TEST_EQUAL( boost::fusion::get<0>(r), nt2::mantissa(a0)/2);
        if (ulpd>ulp0) ulp0=ulpd;
        NT2_TEST_EQUAL( boost::fusion::get<1>(r), nt2::exponent(a0)+1);
        if (ulpd>ulp0) ulp0=ulpd;
     }

   }
} // end of test for float

NT2_TEST_CASE_TPL ( frexp_double_1_0,  (double))
{

  using nt2::standard::frexp;
  using nt2::standard::tag::frexp_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<frexp_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef boost::fusion::vector<T,nt2::int32_t> wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-100), T(100));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        r_t r = nt2::standard::frexp(a0);
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,0>::type>::type r_t0;
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,1>::type>::type r_t1;
//         r_t0 r0 = boost::fusion::get<0>(r);
//         r_t1 r1 = boost::fusion::get<1>(r);
        NT2_TEST_EQUAL( boost::fusion::get<0>(r), nt2::mantissa(a0)/2);
        if (ulpd>ulp0) ulp0=ulpd;
        NT2_TEST_EQUAL( boost::fusion::get<1>(r), nt2::exponent(a0)+1);
        if (ulpd>ulp0) ulp0=ulpd;
     }

   }
} // end of test for double
