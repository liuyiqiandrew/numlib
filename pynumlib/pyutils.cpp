#include <pynumlib/pyutils.hpp>
#include <numlib/exception.hpp>

// check if the the handle can be casted to specified type
template <typename T>
bool tryCastPyHandle(py::handle pyHand) {
    try {
        pyHand.cast<T>();
        return true;
    } catch (const py::cast_error&) {
        return false;
    }
}

// convert a python iterable to arma vector
num::ComplexVector pyIterToCxVector(py::object pyIterable) {
    for (auto item : pyIterable) {
        NUM_ASSERT(tryCastPyHandle<std::complex<double>>(item), "Iterable contains incorrect non-complex type");
    }
    std::vector<std::complex<double>> data = pyIterable.cast<std::vector<std::complex<double>>>();
    return num::ComplexVector(data);
}