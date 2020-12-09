//
// Created by User on 2020-12-08.
//

#include "Symbol.h"

Symbol::~Symbol() {
    output::printID(name, offset, type);
}

Symbol::Symbol(const string &name, const string &type, const int offset) : name(name), type(type), offset(offset) {

}
