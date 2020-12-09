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
};

class Function : public Symbol{};

class Variable : public Symbol{};


#endif //HW3_NONTERMINALS_H
