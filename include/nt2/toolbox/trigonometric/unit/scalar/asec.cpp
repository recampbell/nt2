//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - asec/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by $author$ the $date$
/// modified by $author$ the $date$
/// acos(1/a0)
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/trigonometric/include/asec.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/trigonometric/include/constants.hpp>
#include <nt2/toolbox/crlibm/include/acos.hpp>
#include <nt2/include/functions/rec.hpp>

NT2_TEST_CASE_TPL ( asec_real__1,  NT2_REAL_TYPES)
{
  using nt2::asec;
  using nt2::tag::asec_;
  typedef typename nt2::meta::call<asec_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  asec(-nt2::Two<T>()), 2*nt2::Pi<r_t>()/3, 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Inf<T>()), nt2::Pio_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Minf<T>()), nt2::Pio_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Mone<T>()), nt2::Pi<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::One<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Two<T>()), nt2::Pi<r_t>()/3, 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Zero<T>()), nt2::Nan<r_t>(), 0.5);
  // random verifications
  static const uint32_t NR = 10000;
  {
    NT2_CREATE_BUFFER(a0,T, NR, T(1.05), nt2::Ten<T>());
    double ulp0 = 0.0;
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::asec(a0),nt2::crlibm::acos<nt2::rn>(nt2::rec(a0)),2.0);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( asec_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::asec;
  using nt2::tag::asec_;
  typedef typename nt2::meta::call<asec_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  asec(nt2::One<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Two<T>()), nt2::Pi<r_t>()/3, 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Zero<T>()), nt2::Nan<r_t>(), 0.5);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( asec_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::asec;
  using nt2::tag::asec_;
  typedef typename nt2::meta::call<asec_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  asec(nt2::One<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Two<T>()), nt2::Pi<r_t>()/3, 0.5);
  NT2_TEST_ULP_EQUAL(  asec(nt2::Zero<T>()), nt2::Nan<r_t>(), 0.5);
} // end of test for signed_int_