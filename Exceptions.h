#ifndef HW3_EXCEPTIONS_H
#define HW3_EXCEPTIONS_H

#include <bits/exception.h>

namespace Exceptions {
    class HW3_Exception : std::exception {};

    class AlreadyExistsException : HW3_Exception {
    public:
        const string name;
        const int lineno;
        AlreadyExistsException(int lineno, const string& name) : name(name), lineno(lineno) {}
    };

    class IdentifierDoesNotExistException : HW3_Exception{
    public:
        const string name;
        const int lineno;
        IdentifierDoesNotExistException(int lineno, const string& name) : name(name), lineno(lineno) {}
    };
}
#endif //HW3_EXCEPTIONS_H
