//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_TABLE_SEMANTIC_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_SEMANTIC_HPP_INCLUDED

#include <nt2/core/settings/size.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/settings/shape.hpp>
#include <nt2/core/settings/buffer.hpp>
#include <nt2/core/settings/semantic.hpp>
#include <nt2/core/settings/alignment.hpp>
// #include <nt2/core/settings/sharing.hpp>
#include <nt2/core/settings/allocator.hpp>
#include <nt2/core/settings/interleaving.hpp>
#include <nt2/core/settings/storage_order.hpp>
#include <nt2/core/settings/storage_scheme.hpp>
// #include <nt2/core/settings/storage_duration.hpp>
#include <boost/simd/sdk/memory/allocator.hpp>

namespace nt2 { namespace tag
{
  /*!
    @brief Table semantic tag

    table_ tag marking a type as using the table semantic and defines
    table default settings
  **/
  struct table_
  {
  /*
    typedef conventional_                                   storage_scheme_t;
    typedef owned_                                          sharing_t;
    typedef dynamic_                                        storage_duration_t;
  */

    /// INTERNAL ONLY Table usually use whatever the use specify
    template<typename Settings, typename Option>
    struct option
    {
      typedef Settings type;
    };

    /// INTERNAL ONLY Table default option
    template<typename Option, typename Dummy=void> struct default_;
  };

  /// INTERNAL ONLY Table default option for size
  template<typename Dummy>
  struct table_::default_<nt2::tag::of_size_, Dummy>
  {
    typedef _4D type;
  };

  /// INTERNAL ONLY Table default option for index
  template<typename Dummy>
  struct table_::default_<nt2::tag::index_, Dummy>
  {
    typedef matlab_index_ type;
  };

  /// INTERNAL ONLY Table default option for allocator
  template<typename Dummy>
  struct table_::default_<nt2::tag::allocator_, Dummy>
  {
    typedef boost::simd::memory::allocator<void*> type;
  };

  /// INTERNAL ONLY Table default option for interleaving
  template<typename Dummy>
  struct table_::default_<nt2::tag::interleaving_, Dummy>
  {
    typedef interleaved_ type;
  };

  /// INTERNAL ONLY Table default option for alignment
  template<typename Dummy>
  struct table_::default_<nt2::tag::alignment_, Dummy>
  {
    typedef aligned_ type;
  };

  /// INTERNAL ONLY Table default option for buffer structure
  template<typename Dummy>
  struct table_::default_<nt2::tag::buffer_, Dummy>
  {
    typedef buffer_ type;
  };

  /// INTERNAL ONLY Table default option for storage order
  template<typename Dummy>
  struct table_::default_<nt2::tag::storage_order_, Dummy>
  {
    typedef column_major_ type;
  };

  /// INTERNAL ONLY Table default option for shape
  template<typename Dummy>
  struct table_::default_<nt2::tag::shape_, Dummy>
  {
    typedef rectangular_ type;
  };

  /// INTERNAL ONLY Table default option for storage scheme
  template<typename Dummy>
  struct table_::default_<nt2::tag::storage_scheme_, Dummy>
  {
    typedef nt2::conventional_ type;
  };

  /// INTERNAL ONLY table_ is a semantic
  template<class Dummy>
  struct semantic_::apply<table_, Dummy>
                      : boost::mpl::true_
  {};
} }

#endif
