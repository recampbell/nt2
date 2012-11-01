//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_ADD_SETTINGS_HPP_INCLUDED
#define NT2_CORE_SETTINGS_ADD_SETTINGS_HPP_INCLUDED

/*!
  @file
  @brief
 **/

#include <nt2/core/settings/settings.hpp>

namespace nt2 { namespace meta
{
  template<class Type, class Settings = void>
  struct add_settings
  {
    typedef nt2::settings type(Type,Settings);
  };

  /// INTERNAL ONLY
  template<class Type>
  struct add_settings<Type,void>
  {
    typedef Type type;
  };

  /// INTERNAL ONLY
  template<class Type>
  struct add_settings<Type, nt2::settings()>
  {
    typedef Type type;
  };

  /// INTERNAL ONLY
  template<class T0, class S0>
  struct add_settings<nt2::settings(T0), nt2::settings(S0)>
  {
    typedef nt2::settings type(T0,S0);
  };

  /// INTERNAL ONLY
  template<class S0>
  struct add_settings<nt2::settings(T0), void>
  {
    typedef T0 type;
  };

  #define M0(z,n,t)                                               \
  template<class Type, BOOST_PP_ENUM_PARAMS(n,class S)>           \
  struct add_settings< Type, settings(BOOST_PP_ENUM_PARAMS(n,S))> \
  {                                                               \
    typedef nt2::settings type(Type,BOOST_PP_ENUM_PARAMS(n,S));   \
  };                                                              \
  /**/

  /// INTERNAL ONLY
  BOOST_PP_REPEAT_FROM_TO(2,NT2_META_MAX_OPTIONS_NB,M0,~)

  #undef M0
} }

#endif
