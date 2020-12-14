#include <assert.h>
#include "Framework.h"


//NOTE: must modify default offset of Variable to correct offset!
Variable& Scope::insert(const Variable &newVar, unordered_map<string, Symbol*>& symbol_table) {
    Variable addedVar = Variable(newVar.name, newVar.type, newVar.offset + (nextOffset++), symbol_table);
    variables.push_back(addedVar);
    return variables.back();
}

Scope::~Scope() {
    output::endScope();
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
    Variable& addedVar = scopes.top().insert(newVar, symbol_table);
    symbol_table.insert({newVar.name, &addedVar});
}


void Framework::addFunction(const Function &newFunc) {
    if (contains(newFunc.name)) throw Exceptions::AlreadyExistsException(0, newFunc.name); //FIXME: 0 is only a placeholder number, should be lineno
    assert(newFunc.offset == 0);
    if (newFunc.name == "main" && newFunc.type == "INT" && newFunc.getParameters() == list<Variable>()) mainExists = true;
    Function funcToAdd = Function(newFunc.name, newFunc.type, symbol_table, newFunc.getParameters());
    functions.push_back(funcToAdd);
    Function& addedFunc = functions.back();
    symbol_table.insert({newFunc.name, &addedFunc});

    int numParamsAddedSoFar = 0;
    for (Variable param : newFunc.getParameters()){
        param.offset = -(++numParamsAddedSoFar);
        insertVariableIntoTopScope(param); //TODO: param should be inserted into function scope, not surrounding scope
    }
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
    scopes.push(Scope(Scope::BLOCK, 0));

    list<string> printFuncParams = list<string>();
    printFuncParams.emplace_back("STRING");
    addFunction(Function("print",  "VOID", printFuncParams));

    list<string> printiFuncParams = list<string>();
    printFuncParams.emplace_back("INT");
    addFunction(Function("printi",  "VOID", printiFuncParams));
}

Framework& Framework::getInstance() {
    static Framework singleton = Framework();
    return singleton;
}

