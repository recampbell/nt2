//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/include/functions/unaligned_load.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

NT2_TEST_CASE_TPL( unaligned_load,  BOOST_SIMD_TYPES)
{
  using boost::simd::unaligned_load;
  using boost::simd::tag::unaligned_load_;

  typedef typename
          boost::dispatch::
          meta::call<unaligned_load_(T*,boost::dispatch::meta::as_<T>)>::type r_t;

  NT2_TEST( (boost::is_same<T,r_t>::value) );

  T data[ 3 ];
  for(size_t i=0;i<3;++i) data[i] = T(1+i);

  for(int i=0;i<3;++i)
  {
    r_t v = boost::simd::unaligned_load<T>(&data[i]);
    NT2_TEST_EQUAL(v , data[i]);
  }
}

NT2_TEST_CASE_TPL( unaligned_load_logical,  BOOST_SIMD_TYPES)
{
  using boost::simd::unaligned_load;
  using boost::simd::tag::unaligned_load_;
  using boost::simd::logical;

  typedef typename  boost::dispatch::meta
                  ::call<unaligned_load_( logical<T>*
                                        , boost::dispatch::meta::as_<T>
                                        )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, T );

  logical<T> data[3];
  rT         ref[3];

  for(std::size_t i=0;i<3;++i)
  {
    data[i] = logical<T>(i%2);
    ref[i]  = logical<T>(i%2);
  }

  for(std::size_t i=0;i<3;++i)
  {
    rT v = boost::simd::unaligned_load<T>(&data[i]);
    NT2_TEST_EQUAL(v , ref[i]);
  }
}

NT2_TEST_CASE_TPL( unaligned_load_offset,  BOOST_SIMD_TYPES)
{
  using boost::simd::unaligned_load;
  using boost::simd::tag::unaligned_load_;

  typedef typename
          boost::dispatch::
          meta::call<unaligned_load_(T*,int,boost::dispatch::meta::as_<T>)>::type r_t;

  NT2_TEST( (boost::is_same<T,r_t>::value) );

  T data[ 3 ];
  for(size_t i=0;i<3;++i) data[i] = T(1+i);

  {
    r_t v = boost::simd::unaligned_load<T>(&data[1],-1);
    NT2_TEST_EQUAL(v , data[0]);
  }

  {
    r_t v = boost::simd::unaligned_load<T>(&data[1], 0);
    NT2_TEST_EQUAL(v , data[1]);
  }

  {
    r_t v = boost::simd::unaligned_load<T>(&data[1],+1);
    NT2_TEST_EQUAL(v , data[2]);
  }
}

NT2_TEST_CASE_TPL( unaligned_load_offset_logical,  BOOST_SIMD_TYPES)
{
  using boost::simd::unaligned_load;
  using boost::simd::tag::unaligned_load_;
  using boost::simd::logical;

  typedef typename  boost::dispatch::meta
                  ::call<unaligned_load_( logical<T>*
                                        , int
                                        , boost::dispatch::meta::as_<T>
                                        )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, T );

  logical<T> data[3];
  rT         ref[3];

  for(std::size_t i=0;i<3;++i)
  {
    data[i] = logical<T>(i%2);
    ref[i]  = logical<T>(i%2);
  }

  for(std::size_t i=0;i<3;++i)
  {
    rT v = boost::simd::unaligned_load<T>(&data[0],i);
    NT2_TEST_EQUAL(v , ref[i]);
  }
}

struct foo { short d; float f; char c; };
BOOST_FUSION_ADAPT_STRUCT(foo,(short,d)(float,f)(char,c))

NT2_TEST_CASE( unaligned_load_sequence )
{
  using boost::fusion::make_vector;
  using boost::simd::unaligned_load;
  using boost::simd::tag::unaligned_load_;

  static const size_t sz = 3;

  char     cdata[ sz ];
  float    fdata[ sz ];
  int16_t  ddata[ sz ];

  for(size_t i=0;i<sz;++i)
  {
    cdata[i] = char(1+i);
    fdata[i] = float(1+i);
    ddata[i] = short(1+i);
  }

  for(size_t i=0;i<sz;++i)
  {
    foo v = unaligned_load<foo>(make_vector(&ddata[0], &fdata[0], &cdata[0]), i);
    NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , ddata[i]);
    NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , fdata[i]);
    NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , cdata[i]);
  }
}

NT2_TEST_CASE( unaligned_load_pointer_of_sequence )
{
  using boost::simd::unaligned_load;
  using boost::simd::tag::unaligned_load_;

  foo data[3];

  for(std::size_t i=0;i<3;++i)
  {
    data[i].d = double(1+i);
    data[i].f = float(2+i);
    data[i].c = char(3+i);
  }

  for(std::size_t i=0;i<3;++i)
  {
    foo v = unaligned_load<foo>(&data[0], i);
    NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , data[i].d);
    NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , data[i].f);
    NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , data[i].c);
  }
}
