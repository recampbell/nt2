//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_ALIGNMENT_HPP_INCLUDED
#define NT2_CORE_SETTINGS_ALIGNMENT_HPP_INCLUDED

#include <nt2/core/settings/forward/alignment.hpp>

namespace nt2 { namespace tag
{
  struct alignment_
  {
    template<class T, class Dummy = void>
    struct apply : boost::mpl::false_
    {};
  };

  template<class Dummy>
  struct alignment_::apply<nt2::aligned_, Dummy>
                      : boost::mpl::true_
  {};

  template<class Dummy>
  struct alignment_::apply<nt2::unaligned_, Dummy>
                      : boost::mpl::true_
  {};
} }

#endif
