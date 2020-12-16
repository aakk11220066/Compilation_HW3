#ifndef HW3_EXCEPTIONS_H
#define HW3_EXCEPTIONS_H

#include <bits/exception.h>
#include <string>
#include <list>
#include <vector>

#include "Symbol.h"

using std::string;
using std::list;
using std::vector;

extern list<string> varsListToTypesList(const list<Variable>& varList);

namespace Exceptions {
    class HW3_Exception : std::exception {
    public:
        virtual void printError() = 0;
    };

    class AlreadyExistsException : HW3_Exception {
    public:
        const string name;
        const int lineno;
        AlreadyExistsException(int lineno, const string& name) : name(name), lineno(lineno) {}
        void printError() override{}
    };

    class IdentifierDoesNotExistException : HW3_Exception{
    public:
        const string name;
        const int lineno;
        IdentifierDoesNotExistException(int lineno, const string& name) : name(name), lineno(lineno) {}
        void printError() override{
            output::errorDef(lineno, name);
        }
    };

    class MismatchException : HW3_Exception{
    public:
        const int lineno;
        explicit MismatchException(int lineno) : lineno(lineno) {};
        void printError() override{
            output::errorMismatch(lineno);
        }
    };

    class NoMainException : HW3_Exception {
    public:
        void printError() override{
            output::errorMainMissing();
        }
    };

    class UnexpectedBreakException : HW3_Exception{
    public:
        const int lineno;
        explicit UnexpectedBreakException(int lineno) : lineno(lineno) {}
        void printError() override{
            output::errorUnexpectedBreak(lineno);
        }
    };

    class UnexpectedContinueException : HW3_Exception{
    public:
        const int lineno;
        explicit UnexpectedContinueException(int lineno) : lineno(lineno) {}
        void printError() override{
            output::errorUnexpectedContinue(lineno);
        }
    };

    class UndefFuncException : HW3_Exception{
    public:
        const string name;
        const int lineno;
        UndefFuncException(int lineno, const string& name) : lineno(lineno), name(name) {}
        void printError() override{
            output::errorUndefFunc(lineno, name);
        }
    };

    class UndefException : HW3_Exception{
    public:
        const string name;
        const int lineno;
        UndefException(int lineno, const string& name) : name(name), lineno(lineno) {}
        void printError() override{
            output::errorDef(lineno, name);
        }
    };


    class PrototypeMismatchException : HW3_Exception{
    public:
        const int lineno;
        const string name;
        const list<Variable> params;
        PrototypeMismatchException(int lineno, const string& name, const list<Variable>& params) : lineno(lineno), name(name), params(params) {}
        void printError() override{
            const std::list<string> typesList = varsListToTypesList(params);
            vector<string> argTypes = vector<string>(typesList.begin(), typesList.end());
            output::errorPrototypeMismatch(lineno, name, argTypes);
        }
    };

}
#endif //HW3_EXCEPTIONS_H
