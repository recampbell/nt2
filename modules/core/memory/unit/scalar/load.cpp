//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/load.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <nt2/sdk/simd/logical.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

#include <boost/dispatch/functor/meta/call.hpp>
#include <boost/simd/memory/stack_buffer.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

NT2_TEST_CASE_TPL( load,  BOOST_SIMD_SIMD_TYPES)
{
  using nt2::load;
  using nt2::tag::load_;

  typedef typename  boost::dispatch::meta
                  ::call<load_( T*
                              , boost::dispatch::meta::as_<T>
                              )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, T );

  BOOST_SIMD_ALIGNED_STACK_BUFFER( data,  T, 3 );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( ref , rT, 3 );

  for(std::size_t i=0;i<3;++i)
  {
    data[i] = T(1+i);
    ref[i]  = T(1+i);
  }

  for(std::size_t i=0;i<3;++i)
  {
    rT v = nt2::load<T>(&data[i]);
    NT2_TEST_EQUAL(v , ref[i]);
  }
}

NT2_TEST_CASE_TPL( load_offset,  BOOST_SIMD_SIMD_TYPES)
{
  using nt2::load;
  using nt2::tag::load_;

  typedef typename  boost::dispatch::meta
                  ::call<load_( T*
                              , int
                              , boost::dispatch::meta::as_<T>
                              )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, T );

  BOOST_SIMD_ALIGNED_STACK_BUFFER( data,  T, 3 );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( ref , rT, 3 );

  for(std::size_t i=0;i<3;++i)
  {
    data[i] = T(1+i);
    ref[i] = T(1+i);
  }

  rT v;

  v = nt2::load<T>(&data[1],-1);
  NT2_TEST_EQUAL(v , ref[0]);

  v = nt2::load<T>(&data[1], 0);
  NT2_TEST_EQUAL(v , ref[1]);

  v = nt2::load<T>(&data[1],+1);
  NT2_TEST_EQUAL(v , ref[2]);
}

NT2_TEST_CASE_TPL( load_misaligned,  BOOST_SIMD_SIMD_TYPES)
{
  using nt2::load;
  using nt2::tag::load_;

  typedef typename  boost::dispatch::meta
                  ::call<load_( T*
                              , boost::dispatch::meta::as_<T>
                              )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, T );

  BOOST_SIMD_ALIGNED_STACK_BUFFER( data,  T, 3 );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( ref , rT, 3 );

  for(std::size_t i=0;i<3;++i)
  {
    data[i] = T(1+i);
    ref[i] = T(2+i);
  }

  for(std::size_t i=0;i<2;++i)
  {
    rT v = nt2::load<T,1>(&data[1+i]);
    NT2_TEST_EQUAL(v , ref[i]);
  }

  for(std::size_t i=0;i<3;++i)
  {
    ref[i]  = T(i);
  }

  for(std::size_t i=1;i<3;++i)
  {
    rT v = nt2::load<T,-1>(&data[i-1]);
    NT2_TEST_EQUAL(v , ref[i]);
  }
}

NT2_TEST_CASE_TPL( load_misaligned_offset,  BOOST_SIMD_SIMD_TYPES)
{
  using nt2::load;
  using nt2::tag::load_;

  typedef typename  boost::dispatch::meta
                  ::call<load_( T*
                              , int
                              , boost::dispatch::meta::as_<T>
                              )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, T );

  BOOST_SIMD_ALIGNED_STACK_BUFFER( data,  T, 5 );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( ref , rT, 5 );

  for(std::size_t i=0;i<5;++i)
  {
    data[i] = T(2+i);
    ref[i] = T(4+i);
  }

  for(std::size_t i=0;i<3;++i)
  {
    rT v = nt2::load<T,1>(&data[1+i],1);
    NT2_TEST_EQUAL(v , ref[i]);
  }

  for(std::size_t i=0;i<5;++i)
  {
    ref[i]  = T(2+i);
  }

  for(std::size_t i=1;i<4;++i)
  {
    rT v = nt2::load<T,-1>(&data[i-1],1);
    NT2_TEST_EQUAL(v , ref[i]);
  }
}

struct foo { short d; float f; char c; };

BOOST_FUSION_ADAPT_STRUCT(foo,(short,d)(float,f)(char,c))

NT2_TEST_CASE( load_sequence )
{
  using nt2::load;
  using nt2::tag::load_;
  using boost::fusion::make_vector;
  using boost::fusion::vector;
  using boost::fusion::result_of::value_at;

  BOOST_SIMD_ALIGNED_STACK_BUFFER( cdata, char  , 3 );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( fdata, float , 3 );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( sdata, short , 3 );

  for(std::size_t i=0;i<3;++i)
  {
    cdata[i] = char(1+i);
    fdata[i] = float(1+i);
    sdata[i] = short(1+i);
  }

  typedef  boost::dispatch::meta
                  ::call<load_( vector<short,float,char>
                              , boost::dispatch::meta::as_<foo>
                              )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, foo );

  typedef boost::dispatch::meta
                ::call<load_( vector<short,float,char>
                            , int
                            , boost::dispatch::meta::as_<foo>
                            )
                      >::type                     riT;

  NT2_TEST_TYPE_IS( riT, foo );

  foo v = load<foo>(make_vector(&sdata[0], &fdata[0], &cdata[0]) );

  typedef value_at<foo,boost::mpl::int_<0> >::type foo0_t;
  typedef value_at<foo,boost::mpl::int_<1> >::type foo1_t;
  typedef value_at<foo,boost::mpl::int_<2> >::type foo2_t;

  foo0_t sref = load<foo0_t>(&sdata[0]);
  foo1_t fref = load<foo1_t>(&fdata[0]);
  foo2_t cref = load<foo2_t>(&cdata[0]);

  NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , sref);
  NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , fref);
  NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , cref);

  for(std::size_t i=0;i<3;++i)
  {
    foo v = load<foo>(make_vector(&sdata[0], &fdata[0], &cdata[0]), i );

    typedef value_at<foo,boost::mpl::int_<0> >::type foo0_t;
    typedef value_at<foo,boost::mpl::int_<1> >::type foo1_t;
    typedef value_at<foo,boost::mpl::int_<2> >::type foo2_t;

    foo0_t sref = load<foo0_t>(&sdata[0],i);
    foo1_t fref = load<foo1_t>(&fdata[0],i);
    foo2_t cref = load<foo2_t>(&cdata[0],i);

    NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , sref);
    NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , fref);
    NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , cref);
  }
}

NT2_TEST_CASE( load_pointer_of_sequence )
{
  using nt2::load;
  using nt2::tag::load_;
  using boost::fusion::make_vector;
  using boost::fusion::result_of::value_at;

  BOOST_SIMD_ALIGNED_STACK_BUFFER( data, foo, 3 );

  typedef  boost::dispatch::meta
                  ::call<load_( foo*
                              , boost::dispatch::meta::as_<foo>
                              )
                        >::type                     rT;

  NT2_TEST_TYPE_IS( rT, foo );

  typedef  boost::dispatch::meta
                  ::call<load_( foo*
                              , int
                              , boost::dispatch::meta::as_<foo>
                              )
                        >::type                     riT;

  NT2_TEST_TYPE_IS( riT, foo );

  for(size_t i=0;i<3;++i)
  {
    data[i].d = int16_t(1+i);
    data[i].f = float(2+i);
    data[i].c = char(3+i);
  }

  foo v = load<foo>(&data[0]);

  NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , data[0].d);
  NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , data[0].f);
  NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , data[0].c);

  for(size_t i=0;i<3;++i)
  {
    foo v = load<foo>(&data[0],i);

    NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , data[i].d);
    NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , data[i].f);
    NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , data[i].c);
  }
}
