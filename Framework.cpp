#include <assert.h>
#include "Framework.h"

#include <iostream>
#define DEBUG_PRINT(str) std::cout << str << std::endl

//NOTE: must modify default offset of Variable to correct offset! //
Variable& Scope::insert(const Variable &newVar, unordered_map<string, Symbol*>& symbol_table) {
    Variable addedVar = Variable(newVar.name, newVar.type, newVar.offset + (nextOffset++), symbol_table);
    variables.push_back(addedVar);
    return variables.back();
}

Scope::~Scope() {
    for (const Variable& var : variables){
        output::printID(var.name, var.offset, var.type);
        Framework::getInstance().symbol_table.erase(var.name);
    }
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
        Variable offsetFixedParam = Variable(param.name, param.type, -(++numParamsAddedSoFar), symbol_table);
        insertVariableIntoTopScope(offsetFixedParam); //TODO: param should be inserted into function scope, not surrounding scope
    }
}


Symbol &Framework::operator[](const string &name) {
    
    try{
        std::cout << std::endl << std::endl << "symtab.size() = " << symbol_table.size() << std::endl << std::endl;
        for (std::pair<const string&,Symbol*> myPair : symbol_table) std::cout << myPair.first << std::endl;

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
string print(string stringToPrint);
    list<Variable> printFuncParams = list<Variable>();
    printFuncParams.emplace_back(Variable("stringToPrint", "STRING"));
    addFunction(Function("print",  "VOID", printFuncParams));

    list<Variable> printiFuncParams = list<Variable>();
    printFuncParams.emplace_back(Variable("intToPrint", "INT"));
    addFunction(Function("printi",  "VOID", printiFuncParams));
}

Framework singleton = Framework();
Framework& Framework::getInstance() {
    return singleton;
}

void Framework::popScope() {
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

