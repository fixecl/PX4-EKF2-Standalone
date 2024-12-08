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
 * Symbolic function: compute_drag_y_innov_var_and_h
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix23_23
 *     rho: Scalar
 *     cd: Scalar
 *     cm: Scalar
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov_var: Scalar
 *     Hy: Matrix23_1
 */
template <typename Scalar>
void ComputeDragYInnovVarAndH(const matrix::Matrix<Scalar, 24, 1>& state,
                              const matrix::Matrix<Scalar, 23, 23>& P, const Scalar rho,
                              const Scalar cd, const Scalar cm, const Scalar R,
                              const Scalar epsilon, Scalar* const innov_var = nullptr,
                              matrix::Matrix<Scalar, 23, 1>* const Hy = nullptr) {
  // Total ops: 360

  // Input arrays

  // Intermediate terms (76)
  const Scalar _tmp0 = 2 * state(0, 0);
  const Scalar _tmp1 = _tmp0 * state(3, 0);
  const Scalar _tmp2 = 2 * state(1, 0);
  const Scalar _tmp3 = _tmp2 * state(2, 0);
  const Scalar _tmp4 = -_tmp1 + _tmp3;
  const Scalar _tmp5 = _tmp4 * cm;
  const Scalar _tmp6 = -2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp7 = -2 * std::pow(state(2, 0), Scalar(2));
  const Scalar _tmp8 = _tmp6 + _tmp7 + 1;
  const Scalar _tmp9 = -state(22, 0) + state(4, 0);
  const Scalar _tmp10 = _tmp1 + _tmp3;
  const Scalar _tmp11 = -state(23, 0) + state(5, 0);
  const Scalar _tmp12 = _tmp0 * state(2, 0);
  const Scalar _tmp13 = _tmp2 * state(3, 0);
  const Scalar _tmp14 = -_tmp12 + _tmp13;
  const Scalar _tmp15 = _tmp10 * _tmp11 + _tmp14 * state(6, 0) + _tmp8 * _tmp9;
  const Scalar _tmp16 = 2 * state(3, 0);
  const Scalar _tmp17 = _tmp16 * state(2, 0);
  const Scalar _tmp18 = _tmp2 * state(0, 0);
  const Scalar _tmp19 = _tmp17 - _tmp18;
  const Scalar _tmp20 = _tmp12 + _tmp13;
  const Scalar _tmp21 = 1 - 2 * std::pow(state(1, 0), Scalar(2));
  const Scalar _tmp22 = _tmp21 + _tmp7;
  const Scalar _tmp23 = _tmp11 * _tmp19 + _tmp20 * _tmp9 + _tmp22 * state(6, 0);
  const Scalar _tmp24 = _tmp21 + _tmp6;
  const Scalar _tmp25 = _tmp17 + _tmp18;
  const Scalar _tmp26 = _tmp11 * _tmp24 + _tmp25 * state(6, 0) + _tmp4 * _tmp9;
  const Scalar _tmp27 = std::sqrt(Scalar(std::pow(_tmp15, Scalar(2)) + std::pow(_tmp23, Scalar(2)) +
                                         std::pow(_tmp26, Scalar(2)) + epsilon));
  const Scalar _tmp28 = cd * rho;
  const Scalar _tmp29 = Scalar(0.5) * _tmp27 * _tmp28;
  const Scalar _tmp30 = _tmp29 * _tmp4;
  const Scalar _tmp31 = 2 * _tmp15;
  const Scalar _tmp32 = _tmp31 * _tmp8;
  const Scalar _tmp33 = 2 * _tmp23;
  const Scalar _tmp34 = _tmp20 * _tmp33;
  const Scalar _tmp35 = 2 * _tmp26;
  const Scalar _tmp36 = _tmp35 * _tmp4;
  const Scalar _tmp37 = Scalar(0.25) * _tmp26 * _tmp28 / _tmp27;
  const Scalar _tmp38 = _tmp30 - _tmp37 * (-_tmp32 - _tmp34 - _tmp36) + _tmp5;
  const Scalar _tmp39 = -_tmp30 - _tmp37 * (_tmp32 + _tmp34 + _tmp36) - _tmp5;
  const Scalar _tmp40 = _tmp24 * cm;
  const Scalar _tmp41 = _tmp10 * _tmp31;
  const Scalar _tmp42 = _tmp19 * _tmp33;
  const Scalar _tmp43 = _tmp24 * _tmp35;
  const Scalar _tmp44 = _tmp24 * _tmp29;
  const Scalar _tmp45 = -_tmp37 * (_tmp41 + _tmp42 + _tmp43) - _tmp40 - _tmp44;
  const Scalar _tmp46 = _tmp16 * _tmp9;
  const Scalar _tmp47 = _tmp0 * _tmp11;
  const Scalar _tmp48 = state(1, 0) * state(6, 0);
  const Scalar _tmp49 = 2 * state(2, 0);
  const Scalar _tmp50 = _tmp11 * _tmp49;
  const Scalar _tmp51 = _tmp16 * state(6, 0);
  const Scalar _tmp52 = 4 * _tmp11;
  const Scalar _tmp53 = _tmp49 * _tmp9;
  const Scalar _tmp54 = _tmp0 * state(6, 0);
  const Scalar _tmp55 = -_tmp52 * state(1, 0) + _tmp53 + _tmp54;
  const Scalar _tmp56 =
      -Scalar(1) / Scalar(2) * _tmp29 * _tmp55 -
      Scalar(1) / Scalar(2) * _tmp37 *
          (_tmp31 * (_tmp50 + _tmp51) + _tmp33 * (_tmp46 - _tmp47 - 4 * _tmp48) + _tmp35 * _tmp55) -
      Scalar(1) / Scalar(2) * _tmp55 * cm;
  const Scalar _tmp57 = 2 * _tmp48;
  const Scalar _tmp58 = -_tmp46 + _tmp57;
  const Scalar _tmp59 = _tmp11 * _tmp2;
  const Scalar _tmp60 = _tmp11 * _tmp16;
  const Scalar _tmp61 = state(2, 0) * state(6, 0);
  const Scalar _tmp62 = 2 * _tmp61;
  const Scalar _tmp63 =
      -Scalar(1) / Scalar(2) * _tmp29 * _tmp58 -
      Scalar(1) / Scalar(2) * _tmp37 *
          (_tmp31 * (_tmp60 - _tmp62) + _tmp33 * (_tmp53 - _tmp59) + _tmp35 * _tmp58) -
      Scalar(1) / Scalar(2) * _tmp58 * cm;
  const Scalar _tmp64 = _tmp2 * _tmp9;
  const Scalar _tmp65 = _tmp51 + _tmp64;
  const Scalar _tmp66 = _tmp0 * _tmp9;
  const Scalar _tmp67 = 4 * _tmp9;
  const Scalar _tmp68 = -Scalar(1) / Scalar(2) * _tmp29 * _tmp65 -
                        Scalar(1) / Scalar(2) * _tmp37 *
                            (_tmp31 * (-_tmp54 + _tmp59 - _tmp67 * state(2, 0)) +
                             _tmp33 * (_tmp60 - 4 * _tmp61 + _tmp66) + _tmp35 * _tmp65) -
                        Scalar(1) / Scalar(2) * _tmp65 * cm;
  const Scalar _tmp69 = -_tmp52 * state(3, 0) + _tmp62 - _tmp66;
  const Scalar _tmp70 = -Scalar(1) / Scalar(2) * _tmp29 * _tmp69 -
                        Scalar(1) / Scalar(2) * _tmp37 *
                            (_tmp31 * (_tmp47 + _tmp57 - _tmp67 * state(3, 0)) +
                             _tmp33 * (_tmp50 + _tmp64) + _tmp35 * _tmp69) -
                        Scalar(1) / Scalar(2) * _tmp69 * cm;
  const Scalar _tmp71 =
      -_tmp56 * state(2, 0) - _tmp63 * state(3, 0) + _tmp68 * state(1, 0) + _tmp70 * state(0, 0);
  const Scalar _tmp72 =
      _tmp56 * state(3, 0) - _tmp63 * state(2, 0) + _tmp68 * state(0, 0) - _tmp70 * state(1, 0);
  const Scalar _tmp73 =
      _tmp56 * state(0, 0) - _tmp63 * state(1, 0) - _tmp68 * state(3, 0) + _tmp70 * state(2, 0);
  const Scalar _tmp74 = -_tmp37 * (-_tmp41 - _tmp42 - _tmp43) + _tmp40 + _tmp44;
  const Scalar _tmp75 = -_tmp25 * _tmp29 - _tmp25 * cm -
                        _tmp37 * (_tmp14 * _tmp31 + _tmp22 * _tmp33 + _tmp25 * _tmp35);

  // Output terms (2)
  if (innov_var != nullptr) {
    Scalar& _innov_var = (*innov_var);

    _innov_var =
        R +
        _tmp38 * (P(0, 21) * _tmp73 + P(1, 21) * _tmp72 + P(2, 21) * _tmp71 + P(21, 21) * _tmp38 +
                  P(22, 21) * _tmp74 + P(3, 21) * _tmp39 + P(4, 21) * _tmp45 + P(5, 21) * _tmp75) +
        _tmp39 * (P(0, 3) * _tmp73 + P(1, 3) * _tmp72 + P(2, 3) * _tmp71 + P(21, 3) * _tmp38 +
                  P(22, 3) * _tmp74 + P(3, 3) * _tmp39 + P(4, 3) * _tmp45 + P(5, 3) * _tmp75) +
        _tmp45 * (P(0, 4) * _tmp73 + P(1, 4) * _tmp72 + P(2, 4) * _tmp71 + P(21, 4) * _tmp38 +
                  P(22, 4) * _tmp74 + P(3, 4) * _tmp39 + P(4, 4) * _tmp45 + P(5, 4) * _tmp75) +
        _tmp71 * (P(0, 2) * _tmp73 + P(1, 2) * _tmp72 + P(2, 2) * _tmp71 + P(21, 2) * _tmp38 +
                  P(22, 2) * _tmp74 + P(3, 2) * _tmp39 + P(4, 2) * _tmp45 + P(5, 2) * _tmp75) +
        _tmp72 * (P(0, 1) * _tmp73 + P(1, 1) * _tmp72 + P(2, 1) * _tmp71 + P(21, 1) * _tmp38 +
                  P(22, 1) * _tmp74 + P(3, 1) * _tmp39 + P(4, 1) * _tmp45 + P(5, 1) * _tmp75) +
        _tmp73 * (P(0, 0) * _tmp73 + P(1, 0) * _tmp72 + P(2, 0) * _tmp71 + P(21, 0) * _tmp38 +
                  P(22, 0) * _tmp74 + P(3, 0) * _tmp39 + P(4, 0) * _tmp45 + P(5, 0) * _tmp75) +
        _tmp74 * (P(0, 22) * _tmp73 + P(1, 22) * _tmp72 + P(2, 22) * _tmp71 + P(21, 22) * _tmp38 +
                  P(22, 22) * _tmp74 + P(3, 22) * _tmp39 + P(4, 22) * _tmp45 + P(5, 22) * _tmp75) +
        _tmp75 * (P(0, 5) * _tmp73 + P(1, 5) * _tmp72 + P(2, 5) * _tmp71 + P(21, 5) * _tmp38 +
                  P(22, 5) * _tmp74 + P(3, 5) * _tmp39 + P(4, 5) * _tmp45 + P(5, 5) * _tmp75);
  }

  if (Hy != nullptr) {
    matrix::Matrix<Scalar, 23, 1>& _hy = (*Hy);

    _hy.setZero();

    _hy(0, 0) = _tmp73;
    _hy(1, 0) = _tmp72;
    _hy(2, 0) = _tmp71;
    _hy(3, 0) = _tmp39;
    _hy(4, 0) = _tmp45;
    _hy(5, 0) = _tmp75;
    _hy(21, 0) = _tmp38;
    _hy(22, 0) = _tmp74;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym