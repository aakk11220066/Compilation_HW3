//
// Created by User on 2020-12-08.
//

#include "Symbol.h"

Symbol::~Symbol() {
    output::printID(name, offset, type);
    // TODO: tell Framework::symbol_table to remove this symbol
}

Symbol::Symbol(const string &name, const string &type) : name(name), type(type) {}
