#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <numlib/matrix.hpp>

namespace py = pybind11;

// check if the the handle can be casted to specified type
template <typename T>
bool tryCastPyHandle(py::handle pyHand);

// convert a python iterable to arma vector
num::ComplexVector pyIterToCxVector(py::object iterable);