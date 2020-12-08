#ifndef HW3_EXCEPTIONS_H
#define HW3_EXCEPTIONS_H

#include <bits/exception.h>

namespace Exceptions {
    class HW3_Exception : std::exception {
    };

    class AlreadyExistsException : HW3_Exception {
    };
}
}
#endif //HW3_EXCEPTIONS_H
