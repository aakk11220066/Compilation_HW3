#include <assert.h>
#include "Framework.h"

#include <iostream>
#define DEBUG_PRINT(str) std::cout << str << std::endl

//NOTE: must modify default offset of Variable to correct offset!
Variable& Scope::insert(const Variable &newVar) {
    Variable addedVar = Variable("BAD", "BAD");
    if (newVar.offset < 0) addedVar = Variable(newVar.name, newVar.type, newVar.offset);
    else addedVar = Variable(newVar.name, newVar.type, newVar.offset + (nextOffset++));
    variables.push_back(addedVar);
    return variables.back();
}

Scope::Scope(Scope::ScopeType scopeType, int offset) : scopeType(scopeType), nextOffset(offset){}

Scope::ScopeType Scope::getScopeType() const {
    return scopeType;
}

int Scope::getNextOffset() const {
    return nextOffset;
}

void Framework::insertVariableIntoTopScope(const Variable &newVar) {
    
    if (contains(newVar.name)) throw Exceptions::AlreadyExistsException(0, newVar.name); //FIXME: 0 is only a placeholder number, should be lineno
    Variable& addedVar = scopes.top().insert(newVar);
    symbol_table.insert({newVar.name, &addedVar});
}


void Framework::addFunction(const Function &newFunc) {
    
    if (contains(newFunc.name)) throw Exceptions::AlreadyExistsException(0, newFunc.name);
    assert(newFunc.offset == 0);
    if (newFunc.name == "main" && newFunc.type == "VOID" && newFunc.getParameters().empty()) mainExists = true;
    Function funcToAdd = Function(newFunc.name, newFunc.type);
    functions.push_back(funcToAdd);
    Function& addedFunc = functions.back();
    symbol_table.insert({newFunc.name, &addedFunc});
}


Symbol &Framework::operator[](const string &name) {
    try{
        return *(symbol_table.at(name));
    } catch(std::out_of_range&) {
        throw Exceptions::IdentifierDoesNotExistException(0, name); //FIXME: 0 is only a placeholder number, should be lineno
    }

}

bool Framework::contains(const string &name) {
    
    try{
        symbol_table.at(name);
    } catch(std::out_of_range&){
        return false;
    }
    return true;
}

void Framework::addScope(enum Scope::ScopeType scopeType) {
    
    scopes.push(Scope(scopeType, scopes.top().getNextOffset()));
}

Scope &Framework::getTopScope() {
    return scopes.top();
}

Framework::Framework() {
    
    scopes.push(std::move(Scope(Scope::BLOCK, 0)));

    Function printFunction = Function("print",  "VOID");
    printFunction.params.emplace_back(Variable("stringToPrint", "STRING"));
    addFunction(printFunction);
    addParamToLastFunc(printFunction.params.back());

    Function printiFunction = Function("printi", "VOID");
    printiFunction.params.emplace_back(Variable("intToPrint", "INT"));
    addFunction(Function("printi",  "VOID"));
    addParamToLastFunc(printiFunction.params.back());
}

Framework singleton = Framework();
Framework& Framework::getInstance() {
    return singleton;
}

void Framework::popScope() {
    for (const Variable& var : scopes.top().variables){
        output::printID(var.name, var.offset, var.type);
        symbol_table.erase(var.name);
    }

    scopes.pop();
    output::endScope();
}

Framework::~Framework() {
    for (const Function& func : functions){
        const list<string> argsTypesList = varsListToTypesList(func.getParameters());
        vector<string> argsTypesVector = vector<string>(argsTypesList.begin(), argsTypesList.end());
        output::printID(func.name, func.offset, output::makeFunctionType(func.type, argsTypesVector));
    }
}

void Framework::addParamToLastFunc(const Variable &param) {
    functions.back().params.push_back(param);
}

