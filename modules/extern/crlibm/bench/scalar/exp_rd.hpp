//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/toolbox/crlibm/include/functions/sin_rz.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <cmath>



//////////////////////////////////////////////////////////////////////////////
// Scalar Runtime benchmark for functor<sin_rz_> from crlibm
//////////////////////////////////////////////////////////////////////////////
using nt2::crlibm::sin_rz_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) , T(V2))

NT2_TIMING(nt2::crlibm::sin_rz_,(RS(float,-31.4,31.4)))
NT2_TIMING(nt2::crlibm::sin_rz_,(RS(double,-31.4,31.4)))

#undef RS
