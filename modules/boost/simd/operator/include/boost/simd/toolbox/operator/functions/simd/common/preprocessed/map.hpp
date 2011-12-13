namespace boost { namespace simd { namespace ext { } } } namespace boost { namespace dispatch { namespace meta { template< class Func , class A0 , class X > inline :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > ) , tag::cpu_ > dispatching( boost::simd::tag::map_, tag::cpu_ , unspecified_<Func> const , simd_< unspecified_<A0>, X > const , adl_helper = adl_helper() ) { return :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > ) , tag::cpu_ >(); } } } } namespace boost { namespace simd { namespace ext { template< class Func , class A0 , class X > struct implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > ) , tag::cpu_ > { typedef typename dispatch::meta:: result_of< Func const( typename meta::scalar_of<A0>::type ) >::type rtype; typedef simd::native<rtype, X> result_type; inline result_type operator()(Func const& f, A0 const& a0) { BOOST_SIMD_ALIGNED_TYPE(rtype) tmp[meta::cardinal_of<A0>::value]; for(size_t i = 0; i != boost::simd::meta::cardinal_of<A0>::value; ++i) tmp[i] = f(a0[i]); return load<result_type>(&tmp[0], 0); } }; } } } namespace boost { namespace simd { namespace ext { } } } namespace boost { namespace dispatch { namespace meta { template< class Func , class A0 , class A1 , class X > inline :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > ) , tag::cpu_ > dispatching( boost::simd::tag::map_, tag::cpu_ , unspecified_<Func> const , simd_< unspecified_<A0>, X > const , simd_< unspecified_<A1>, X > const , adl_helper = adl_helper() ) { return :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > ) , tag::cpu_ >(); } } } } namespace boost { namespace simd { namespace ext { template< class Func , class A0 , class A1 , class X > struct implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > ) , tag::cpu_ > { typedef typename dispatch::meta:: result_of< Func const( typename meta::scalar_of<A0>::type , typename meta::scalar_of<A1>::type ) >::type rtype; typedef simd::native<rtype, X> result_type; inline result_type operator()(Func const& f, A0 const& a0 , A1 const& a1) { BOOST_SIMD_ALIGNED_TYPE(rtype) tmp[meta::cardinal_of<A0>::value]; for(size_t i = 0; i != boost::simd::meta::cardinal_of<A0>::value; ++i) tmp[i] = f(a0[i] , a1[i]); return load<result_type>(&tmp[0], 0); } }; } } } namespace boost { namespace simd { namespace ext { } } } namespace boost { namespace dispatch { namespace meta { template< class Func , class A0 , class A1 , class A2 , class X > inline :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > ) , tag::cpu_ > dispatching( boost::simd::tag::map_, tag::cpu_ , unspecified_<Func> const , simd_< unspecified_<A0>, X > const , simd_< unspecified_<A1>, X > const , simd_< unspecified_<A2>, X > const , adl_helper = adl_helper() ) { return :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > ) , tag::cpu_ >(); } } } } namespace boost { namespace simd { namespace ext { template< class Func , class A0 , class A1 , class A2 , class X > struct implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > ) , tag::cpu_ > { typedef typename dispatch::meta:: result_of< Func const( typename meta::scalar_of<A0>::type , typename meta::scalar_of<A1>::type , typename meta::scalar_of<A2>::type ) >::type rtype; typedef simd::native<rtype, X> result_type; inline result_type operator()(Func const& f, A0 const& a0 , A1 const& a1 , A2 const& a2) { BOOST_SIMD_ALIGNED_TYPE(rtype) tmp[meta::cardinal_of<A0>::value]; for(size_t i = 0; i != boost::simd::meta::cardinal_of<A0>::value; ++i) tmp[i] = f(a0[i] , a1[i] , a2[i]); return load<result_type>(&tmp[0], 0); } }; } } } namespace boost { namespace simd { namespace ext { } } } namespace boost { namespace dispatch { namespace meta { template< class Func , class A0 , class A1 , class A2 , class A3 , class X > inline :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > , simd_< unspecified_<A3>, X > ) , tag::cpu_ > dispatching( boost::simd::tag::map_, tag::cpu_ , unspecified_<Func> const , simd_< unspecified_<A0>, X > const , simd_< unspecified_<A1>, X > const , simd_< unspecified_<A2>, X > const , simd_< unspecified_<A3>, X > const , adl_helper = adl_helper() ) { return :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > , simd_< unspecified_<A3>, X > ) , tag::cpu_ >(); } } } } namespace boost { namespace simd { namespace ext { template< class Func , class A0 , class A1 , class A2 , class A3 , class X > struct implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > , simd_< unspecified_<A3>, X > ) , tag::cpu_ > { typedef typename dispatch::meta:: result_of< Func const( typename meta::scalar_of<A0>::type , typename meta::scalar_of<A1>::type , typename meta::scalar_of<A2>::type , typename meta::scalar_of<A3>::type ) >::type rtype; typedef simd::native<rtype, X> result_type; inline result_type operator()(Func const& f, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3) { BOOST_SIMD_ALIGNED_TYPE(rtype) tmp[meta::cardinal_of<A0>::value]; for(size_t i = 0; i != boost::simd::meta::cardinal_of<A0>::value; ++i) tmp[i] = f(a0[i] , a1[i] , a2[i] , a3[i]); return load<result_type>(&tmp[0], 0); } }; } } } namespace boost { namespace simd { namespace ext { } } } namespace boost { namespace dispatch { namespace meta { template< class Func , class A0 , class A1 , class A2 , class A3 , class A4 , class X > inline :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > , simd_< unspecified_<A3>, X > , simd_< unspecified_<A4>, X > ) , tag::cpu_ > dispatching( boost::simd::tag::map_, tag::cpu_ , unspecified_<Func> const , simd_< unspecified_<A0>, X > const , simd_< unspecified_<A1>, X > const , simd_< unspecified_<A2>, X > const , simd_< unspecified_<A3>, X > const , simd_< unspecified_<A4>, X > const , adl_helper = adl_helper() ) { return :: boost :: simd :: ext :: implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > , simd_< unspecified_<A3>, X > , simd_< unspecified_<A4>, X > ) , tag::cpu_ >(); } } } } namespace boost { namespace simd { namespace ext { template< class Func , class A0 , class A1 , class A2 , class A3 , class A4 , class X > struct implement< boost::simd::tag::map_ ( unspecified_<Func> , simd_< unspecified_<A0>, X > , simd_< unspecified_<A1>, X > , simd_< unspecified_<A2>, X > , simd_< unspecified_<A3>, X > , simd_< unspecified_<A4>, X > ) , tag::cpu_ > { typedef typename dispatch::meta:: result_of< Func const( typename meta::scalar_of<A0>::type , typename meta::scalar_of<A1>::type , typename meta::scalar_of<A2>::type , typename meta::scalar_of<A3>::type , typename meta::scalar_of<A4>::type ) >::type rtype; typedef simd::native<rtype, X> result_type; inline result_type operator()(Func const& f, A0 const& a0 , A1 const& a1 , A2 const& a2 , A3 const& a3 , A4 const& a4) { BOOST_SIMD_ALIGNED_TYPE(rtype) tmp[meta::cardinal_of<A0>::value]; for(size_t i = 0; i != boost::simd::meta::cardinal_of<A0>::value; ++i) tmp[i] = f(a0[i] , a1[i] , a2[i] , a3[i] , a4[i]); return load<result_type>(&tmp[0], 0); } }; } } }
