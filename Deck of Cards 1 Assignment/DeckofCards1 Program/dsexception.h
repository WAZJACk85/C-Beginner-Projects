// bwexception.h by Bill Weinman
// updated 2002-09-03

#ifndef dsexception_h
#define dsexception_h

#include <exception>

namespace DS {

    class E : public std::exception {
        const char* msg = nullptr;
        E();
    public:
        E(const char* s) noexcept(true) : msg(s) {}
        const char* what() const noexcept(true) { return msg; }
    };

} // namespace

#endif /* bwexception_h */
