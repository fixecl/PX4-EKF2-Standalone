#mathlib from PX4

set(MATHLIB_SRCS)

list(APPEND MATHLIB_SRCS
        math/test/test.cpp
        math/filter/LowPassFilter2p.hpp
        math/filter/MedianFilter.hpp
        math/filter/NotchFilter.hpp
        math/filter/second_order_reference_model.hpp
        )

add_library(mathlib
        ${MATHLIB_SRCS}
        )

