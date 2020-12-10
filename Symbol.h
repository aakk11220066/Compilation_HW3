#ifndef HW3_NONTERMINALS_H
#define HW3_NONTERMINALS_H

#include <string>
#include <unordered_map>
#include "hw3_output.hpp"
using std::string;

class Symbol{
public:
    const string name, type;
    const int offset = 0;
    std::unordered_map<string, Symbol*>* symbol_table; //only stored for the destructor
    virtual ~Symbol();
    Symbol(const string &name, const string &type);
    Symbol(const string &name, const string &type, unordered_map<string, Symbol*>& symbol_table);
    Symbol(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table);

};

class Function : public Symbol{
public:
    Function(const string &name, const string &type);
    Function(const string &name, const string &type, unordered_map<string, Symbol*>& symbol_table);
};

class Variable : public Symbol{
public:
    Variable(const string &name, const string &type);
    Variable(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table);
};


#endif //HW3_NONTERMINALS_H
