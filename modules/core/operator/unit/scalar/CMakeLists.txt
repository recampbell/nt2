################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET(SOURCES
    is_not_equal.cpp
    is_less_equal.cpp
    is_less.cpp
    is_greater_equal.cpp
    is_greater.cpp
    is_equal.cpp
    access.cpp
    at.cpp
    unary_plus.cpp
    complement.cpp
    logical_not.cpp
    unary_minus.cpp
    plus.cpp
    minus.cpp
    multiplies.cpp
    divides.cpp
    bitwise_and.cpp
    bitwise_or.cpp
    bitwise_xor.cpp
    logical_and.cpp
    logical_or.cpp
    comma.cpp
    if_else.cpp
    modulo.cpp
    shift_left.cpp
    shift_right.cpp
#    splat.cpp
    )

nt2_module_add_tests(core.operator.scalar.unit ${SOURCES})

