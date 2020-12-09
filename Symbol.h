#ifndef HW3_NONTERMINALS_H
#define HW3_NONTERMINALS_H

#include <string>
#include "hw3_output.hpp"

using std::string;

class Symbol{ // FIXME
public:
    const string name, type;
    const int offset;
    virtual ~Symbol();
    Symbol(const string &name, const string &type, int offset);
};

class Function : public Symbol{};

class Variable : public Symbol{};


#endif //HW3_NONTERMINALS_H
