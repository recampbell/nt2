//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 crlibm toolbox - sinh_rn/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of crlibm components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 02/03/2011
///
#include <nt2/toolbox/crlibm/include/functions/sinh_rn.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/sinh.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>


NT2_TEST_CASE_TPL ( sinh_rn_real__1_0,  NT2_REAL_TYPES)
{
  using nt2::rn;
  using nt2::crlibm::sinh_rn;
  using nt2::crlibm::tag::sinh_rn_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<sinh_rn_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-80), T(80));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::crlibm::sinh_rn(a0),nt2::sinh(a0),1);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for floating_
