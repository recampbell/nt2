//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 trigonometric toolbox - sin/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/trigonometric/include/sin.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<sin_> from trigonometric
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::sin_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))
namespace n001 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,-nt2::Pi<T>()/4,nt2::Pi<T>()/4)))
}
namespace n002 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,-nt2::Pi<T>()/4,nt2::Pi<T>()/4)))
}
namespace n01 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,-nt2::Pi<T>()/2,nt2::Pi<T>()/2)))
}
namespace n02 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,-nt2::Pi<T>()/2,nt2::Pi<T>()/2)))
}
namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n11 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,nt2::Valmin<T>()/4,nt2::Valmax<T>()/4)))
}
namespace n12 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(sin_,(RS(T,nt2::Valmin<T>()/4,nt2::Valmax<T>()/4)))
}// namespace n3 {
//   typedef uint8_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(0),T(40))))
// }
// namespace n4 {
//   typedef uint16_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(0),T(40))))
// }
// namespace n5 {
//   typedef uint32_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(0),T(40))))
// }
// namespace n6 {
//   typedef uint64_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(0),T(40))))
// }
// namespace n7 {
//   typedef int8_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(-40),T(40))))
// }
// namespace n8 {
//   typedef int16_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(-40),T(40))))
// }
// namespace n9 {
//   typedef int32_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(-40),T(40))))
// }
// namespace n10 {
//   typedef int64_t T;
//   typedef nt2::meta::as_integer<T>::type iT;
//   NT2_TIMING(sin_,(RS(T,T(-40),T(40))))
// }

#undef RS
