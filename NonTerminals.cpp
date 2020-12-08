//
// Created by User on 2020-12-08.
//

#include "NonTerminals.h"

RetType::RetType(const string &name, const string &type, const int offset) : name(name), type(type), offset(offset) {}

RetType::~RetType() {
    output::printID(name, offset, type);
}
