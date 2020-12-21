#include "Symbol.h"

list<string> varsListToTypesList(const list<Variable>& varList){
    list<string> result = list<string>();
    for (const Variable& var : varList){
        result.push_back(var.type);
    }
    return result;
}

Symbol::~Symbol() {
    if (symbol_table) symbol_table->erase(name);
}

Symbol::Symbol(const string &name, const string &type) : name(name), type(type), symbol_table(nullptr) {}

Symbol::Symbol(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table)
    : name(name), type(type), offset(offset), symbol_table(&symbol_table){}

Symbol::Symbol(const string &name, const string &type, unordered_map<string, Symbol *> &symbol_table) : name(name), type(type), symbol_table(&symbol_table) {}

Variable::Variable(const string &name, const string &type) : Symbol(name, type) {}

Variable::Variable(const string &name, const string &type, int offset, unordered_map<string, Symbol*>& symbol_table) : Symbol(name, type, offset, symbol_table) {}

Function::Function(const string &name, const string &type, std::list<Variable>& params) : Symbol(name, type), params(params) {}

Function::Function(const string &name, const string &type, unordered_map<string, Symbol *> &symbol_table, const std::list<Variable> &params)
    : Symbol(name, type, symbol_table), params(params) {}

const std::list<Variable> &Function::getParameters() const {
    return params;
}

Function::~Function() {
    const list<string> argsTypesList = varsListToTypesList(params);
    vector<string> argsTypesVector = vector<string>(argsTypesList.begin(), argsTypesList.end());
    output::printID(name, offset, output::makeFunctionType(type, argsTypesVector));
}
