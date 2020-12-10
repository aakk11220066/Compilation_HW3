#ifndef HW3_NONTERMINALS_H
#define HW3_NONTERMINALS_H

#include <string>
#include "hw3_output.hpp"
using std::string;

class Symbol{
public:
    const string name, type;
    const int offset = 0;
    virtual ~Symbol();
    Symbol(const string &name, const string &type);
    Symbol(const string &name, const string &type, int offset);
};

class Function : public Symbol{
public:
    Function(const string &name, const string &type);
};

class Variable : public Symbol{
public:
    Variable(const string &name, const string &type);
    Variable(const string &name, const string &type, int offset);
};


#endif //HW3_NONTERMINALS_H
