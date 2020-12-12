#include "Symbol.h"

Symbol::~Symbol() {
    output::printID(name, offset, type);
    symbol_table->erase(name);
}

Symbol::Symbol(const string &name, const string &type) : name(name), type(type), symbol_table(nullptr) {}

Symbol::Symbol(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table)
    : name(name), type(type), offset(offset), symbol_table(&symbol_table){}

Symbol::Symbol(const string &name, const string &type, unordered_map<string, Symbol *> &symbol_table) : name(name), type(type), symbol_table(&symbol_table) {}

Variable::Variable(const string &name, const string &type) : Symbol(name, type) {}

Variable::Variable(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table) : Symbol(name, type, offset, symbol_table) {}

Function::Function(const string &name, const string &type) : Symbol(name, type) {}

Function::Function(const string &name, const string &type, unordered_map<string, Symbol *> &symbol_table) : Symbol(name, type, symbol_table) {}
