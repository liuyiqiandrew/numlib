#ifndef NUM_MATRIX_HPP
#define NUM_MATRIX_HPP

#include <armadillo>
#include <numlib/define.hpp>

BEGIN_NAMESPACE(num)

using Vector = arma::vec;
using RowVector = arma::rowvec;
using ComplexVector = arma::cx_vec;
using Matrix = arma::mat;

END_NAMESPACE(num)

#endif