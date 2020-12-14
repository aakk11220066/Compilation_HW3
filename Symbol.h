#ifndef HW3_NONTERMINALS_H
#define HW3_NONTERMINALS_H

#include <string>
#include <unordered_map>
#include <list>
#include "hw3_output.hpp"
using std::string;

//ABSTRACT CLASS
class Symbol{
public:
    const string name, type;
    const int offset = 0;
    virtual ~Symbol();
protected:
    std::unordered_map<string, Symbol*>* symbol_table; //only stored for the destructor
    Symbol(const string &name, const string &type);
    Symbol(const string &name, const string &type, unordered_map<string, Symbol*>& symbol_table);
    Symbol(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table);
};

class Variable : public Symbol{
public:
    Variable(const string &name, const string &type); //For Shlomi's use
    Variable(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table); //For Akiva's use
};

class Function : public Symbol{
    std::list<Variable> params;
public:
    Function(const string &name, const string &type, std::list<Variable>& params); //For Shlomi's use
    Function(const string &name, const string &type, unordered_map<string, Symbol *> &symbol_table, const list<Variable>& params); //For Akiva's use
    const std::list<Variable>& getParameters() const;
};


#endif //HW3_NONTERMINALS_H
