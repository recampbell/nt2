//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/store.hpp>
#include <nt2/include/functions/load.hpp>
#include <boost/simd/memory/stack_buffer.hpp>
#include <nt2/sdk/simd/logical.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE_TPL(store, BOOST_SIMD_TYPES )
{
  using nt2::store;
  using nt2::load;
  using nt2::tag::store_;

  typedef typename boost::dispatch::meta::call<store_(T,T*)>::type  rT;
  NT2_TEST_TYPE_IS( rT, T );

  std::size_t card = 5;
  BOOST_SIMD_ALIGNED_STACK_BUFFER( data,  T, card );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( out ,  T, card );

  for(std::size_t i=0;i<card;++i)
  {
    data[i] = T(1+i);
    out[i] = T(0);
  }

  for(std::size_t i=0;i<card;++i)
  {
    T v = load<T>(&data[i]);
    T res = store(v,&out[i]);
    T ref = load<T>(&out[i]);

    NT2_TEST_EQUAL( ref, res );
  }
}

NT2_TEST_CASE_TPL(store_offset, BOOST_SIMD_TYPES )
{
  using nt2::store;
  using nt2::load;
  using nt2::tag::store_;

  typedef typename boost::dispatch::meta::call<store_(T,T*,int)>::type  rT;
  NT2_TEST_TYPE_IS( rT, T );

  std::size_t card = 5;
  BOOST_SIMD_ALIGNED_STACK_BUFFER( data,  T, card );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( out ,  T, card );

  for(std::size_t i=0;i<card;++i)
  {
    data[i] = T(1+i);
    out[i] = T(0);
  }

  for(std::size_t i=0;i<card;++i)
  {
    T v = load<T>(&data[0],i);
    T res = store(v,&out[0],i);
    T ref = load<T>(&out[0],i);

    NT2_TEST_EQUAL( ref, res );
  }
}

struct foo { short d; float f; char c; };
BOOST_FUSION_ADAPT_STRUCT(foo,(short,d)(float,f)(char,c))

NT2_TEST_CASE( store_sequence )
{
  using nt2::store;
  using nt2::tag::store_;
  using nt2::load;
  using boost::fusion::make_vector;
  using boost::fusion::result_of::value_at;

  static const size_t sz = 5;

  BOOST_SIMD_ALIGNED_STACK_BUFFER( cdata, char  , sz );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( fdata, float , sz );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( sdata, short , sz );

  BOOST_SIMD_ALIGNED_STACK_BUFFER( scdata, char  , sz );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( sfdata, float , sz );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( ssdata, short , sz );

  for(std::size_t i=0;i<sz;++i)
  {
    cdata[i] = char(1+i);
    fdata[i] = float(1+i);
    sdata[i] = short(1+i);
  }

  for(std::size_t i=0;i<sz;++i)
  {
    foo v = load<foo>(boost::fusion::make_vector(&sdata[i], &fdata[i], &cdata[i]), 0);
    store(v, boost::fusion::make_vector(&ssdata[i], &sfdata[i], &scdata[i]), 0);

    typedef value_at<foo,boost::mpl::int_<0> >::type foo0_t;
    typedef value_at<foo,boost::mpl::int_<1> >::type foo1_t;
    typedef value_at<foo,boost::mpl::int_<2> >::type foo2_t;

    foo0_t sref = load<foo0_t>(&ssdata[i]);
    foo1_t fref = load<foo1_t>(&sfdata[i]);
    foo2_t cref = load<foo2_t>(&scdata[i]);

    NT2_TEST_EQUAL(boost::fusion::at_c<0>(v) , sref);
    NT2_TEST_EQUAL(boost::fusion::at_c<1>(v) , fref);
    NT2_TEST_EQUAL(boost::fusion::at_c<2>(v) , cref);
  }
}

NT2_TEST_CASE( store_pointer_of_sequence )
{
  using nt2::load;
  using nt2::store;
  using nt2::tag::store_;
  using boost::fusion::make_vector;
  using boost::fusion::result_of::value_at;

  using boost::fusion::operator<<;

  std::size_t sz = 3;
  BOOST_SIMD_ALIGNED_STACK_BUFFER( data, foo, sz );
  BOOST_SIMD_ALIGNED_STACK_BUFFER( out, foo, sz );

  for(size_t i=0;i<sz;++i)
  {
    data[i].d = int16_t(1+i); out[i].d = 0;
    data[i].f = float(2+i);   out[i].f = 0;
    data[i].c = char(3+i);    out[i].c = 0;
  }

  for(size_t i=0;i<sz;++i)
  {
    foo v   = load<foo>(&data[0], i);
    foo res = store<foo>(v, &out[0], i);
    foo ref = load<foo>(&out[0], i);

    NT2_TEST_EQUAL(res , ref);
  }
}
