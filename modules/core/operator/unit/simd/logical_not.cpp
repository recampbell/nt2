//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 operator toolbox - logical_not/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/toolbox/operator/include/functions/logical_not.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/sdk/simd/logical.hpp>

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
#include <nt2/toolbox/constant/constant.hpp>
#include <boost/dispatch/meta/ignore_unused.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/toolbox/constant/constant.hpp>
#include <boost/dispatch/meta/ignore_unused.hpp>


NT2_TEST_CASE_TPL ( logical_not_integer__1_0,  NT2_SIMD_INTEGRAL_TYPES)
{
  using nt2::logical_not;
  using nt2::tag::logical_not_;
  using nt2::load;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<logical_not_(vT)>::type r_t;
  typedef typename nt2::meta::call<logical_not_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;
  boost::dispatch::ignore_unused(ulpd);

  // specific values tests
  NT2_TEST_EQUAL(logical_not(nt2::False<vlT>())[0], nt2::True<sr_t>());
  NT2_TEST_EQUAL(logical_not(nt2::True<vlT>())[0], nt2::False<sr_t>());
} // end of test for integer_

NT2_TEST_CASE_TPL ( logical_not_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::logical_not;
  using nt2::tag::logical_not_;
  using nt2::load;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<logical_not_(vT)>::type r_t;
  typedef typename nt2::meta::call<logical_not_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;
  boost::dispatch::ignore_unused(ulpd);

  // specific values tests
  NT2_TEST_EQUAL(logical_not(nt2::False<vlT>())[0], nt2::True<sr_t>());
  NT2_TEST_EQUAL(logical_not(nt2::True<vlT>())[0], nt2::False<sr_t>());
} // end of test for real_
