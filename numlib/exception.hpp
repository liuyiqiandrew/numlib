#ifndef NUM_EXCEPTION_HPP
#define NUM_EXCEPTION_HPP

#include <exception>
#include <sstream>
#include <string>
#include <numlib/define.hpp>

BEGIN_NAMESPACE(num)

/**  The numlib exception class, error msg can be streamed into it.
*/
class Exception: public std::exception {
    public:
    // constructor
    explicit Exception(std::string const & errmsg): errmsg_(errmsg) {}
    // return error message
    virtual const char* what() const noexcept { return errmsg_.c_str(); }
    // dtor
    virtual ~Exception() {}

    protected:
    mutable std::string errmsg_;

    template <typename T>
    friend Exception & operator<<(Exception& ex, T const & msg);
};

// stream operator
template <typename T>
Exception & operator<<(Exception& ex, T const & msg) {
    std::ostringstream s;
    s << msg;
    ex.errmsg_ += s.str();
    return ex;
}

/** @def NUM_ASSERT
 *  @brief easy ways to stream error
 * 
*/
#define NUM_ASSERT(condition, errmsg) \
if (!(condition)) { \
  if ((std::string(errmsg)).empty()) \
  throw num::Exception("error: " #condition); \
  else \
  throw num::Exception(errmsg); \
}

END_NAMESPACE(num)

#endif