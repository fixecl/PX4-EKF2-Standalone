// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_mag_y_innov_var_and_h
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix23_23
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov_var: Scalar
 *     H: Matrix23_1
 */
template <typename Scalar>
void ComputeMagYInnovVarAndH(const matrix::Matrix<Scalar, 24, 1>& state,
                             const matrix::Matrix<Scalar, 23, 23>& P, const Scalar R,
                             const Scalar epsilon, Scalar* const innov_var = nullptr,
                             matrix::Matrix<Scalar, 23, 1>* const H = nullptr) {
  // Total ops: 159

  // Unused inputs
  (void)epsilon;

  // Input arrays

  // Intermediate terms (18)
  const Scalar _tmp0 = 2 * state(2, 0);
  const Scalar _tmp1 = 2 * state(1, 0);
  const Scalar _tmp2 = _tmp0 * state(3, 0) + _tmp1 * state(0, 0);
  const Scalar _tmp3 = 2 * state(3, 0);
  const Scalar _tmp4 = _tmp0 * state(1, 0) - _tmp3 * state(0, 0);
  const Scalar _tmp5 =
      -2 * std::pow(state(1, 0), Scalar(2)) - 2 * std::pow(state(3, 0), Scalar(2)) + 1;
  const Scalar _tmp6 = _tmp1 * state(18, 0) - _tmp3 * state(16, 0);
  const Scalar _tmp7 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp8 = (Scalar(1) / Scalar(2)) * _tmp1 * state(16, 0) +
                       (Scalar(1) / Scalar(2)) * _tmp3 * state(18, 0);
  const Scalar _tmp9 = 4 * state(17, 0);
  const Scalar _tmp10 = 2 * state(0, 0);
  const Scalar _tmp11 = _tmp0 * state(16, 0) + _tmp10 * state(18, 0) - _tmp9 * state(1, 0);
  const Scalar _tmp12 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp13 = (Scalar(1) / Scalar(2)) * _tmp0 * state(18, 0) -
                        Scalar(1) / Scalar(2) * _tmp10 * state(16, 0) -
                        Scalar(1) / Scalar(2) * _tmp9 * state(3, 0);
  const Scalar _tmp14 =
      _tmp12 * state(0, 0) + _tmp13 * state(2, 0) - _tmp7 * state(1, 0) - _tmp8 * state(3, 0);
  const Scalar _tmp15 = (Scalar(1) / Scalar(2)) * state(2, 0);
  const Scalar _tmp16 =
      -_tmp11 * _tmp15 + _tmp13 * state(0, 0) - _tmp7 * state(3, 0) + _tmp8 * state(1, 0);
  const Scalar _tmp17 =
      _tmp12 * state(3, 0) - _tmp13 * state(1, 0) - _tmp15 * _tmp6 + _tmp8 * state(0, 0);

  // Output terms (2)
  if (innov_var != nullptr) {
    Scalar& _innov_var = (*innov_var);

    _innov_var = P(0, 19) * _tmp14 + P(1, 19) * _tmp17 + P(15, 19) * _tmp4 + P(16, 19) * _tmp5 +
                 P(17, 19) * _tmp2 + P(19, 19) + P(2, 19) * _tmp16 + R +
                 _tmp14 * (P(0, 0) * _tmp14 + P(1, 0) * _tmp17 + P(15, 0) * _tmp4 +
                           P(16, 0) * _tmp5 + P(17, 0) * _tmp2 + P(19, 0) + P(2, 0) * _tmp16) +
                 _tmp16 * (P(0, 2) * _tmp14 + P(1, 2) * _tmp17 + P(15, 2) * _tmp4 +
                           P(16, 2) * _tmp5 + P(17, 2) * _tmp2 + P(19, 2) + P(2, 2) * _tmp16) +
                 _tmp17 * (P(0, 1) * _tmp14 + P(1, 1) * _tmp17 + P(15, 1) * _tmp4 +
                           P(16, 1) * _tmp5 + P(17, 1) * _tmp2 + P(19, 1) + P(2, 1) * _tmp16) +
                 _tmp2 * (P(0, 17) * _tmp14 + P(1, 17) * _tmp17 + P(15, 17) * _tmp4 +
                          P(16, 17) * _tmp5 + P(17, 17) * _tmp2 + P(19, 17) + P(2, 17) * _tmp16) +
                 _tmp4 * (P(0, 15) * _tmp14 + P(1, 15) * _tmp17 + P(15, 15) * _tmp4 +
                          P(16, 15) * _tmp5 + P(17, 15) * _tmp2 + P(19, 15) + P(2, 15) * _tmp16) +
                 _tmp5 * (P(0, 16) * _tmp14 + P(1, 16) * _tmp17 + P(15, 16) * _tmp4 +
                          P(16, 16) * _tmp5 + P(17, 16) * _tmp2 + P(19, 16) + P(2, 16) * _tmp16);
  }

  if (H != nullptr) {
    matrix::Matrix<Scalar, 23, 1>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp14;
    _h(1, 0) = _tmp17;
    _h(2, 0) = _tmp16;
    _h(15, 0) = _tmp4;
    _h(16, 0) = _tmp5;
    _h(17, 0) = _tmp2;
    _h(19, 0) = 1;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
