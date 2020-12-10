//
// Created by User on 2020-12-08.
//

#include "Symbol.h"

Symbol::~Symbol() {
    output::printID(name, offset, type);
    // TODO: tell symbol_table to remove this symbol
}

Symbol::Symbol(const string &name, const string &type) : name(name), type(type) {}

Symbol::Symbol(const string &name, const string &type, int offset) : name(name), type(type), offset(offset){}

Variable::Variable(const string &name, const string &type) : Symbol(name, type) {}

Variable::Variable(const string &name, const string &type, int offset) : Symbol(name, type, offset) {}

Function::Function(const string &name, const string &type) : Symbol(name, type) {}
