//
// Created by User on 2020-12-08.
//

#ifndef HW3_FRAMEWORK_H
#define HW3_FRAMEWORK_H

#include <string>
#include <list>
#include <unordered_map>
#include <stack>
#include <deque>
#include <memory>

#include "Symbol.h"
#include "Exceptions.h"

class Scope{
public:
    enum ScopeType{IF, LOOP, FUNCTION, BLOCK};

private:
    std::deque<Variable> variables;
    int nextOffset;
    enum ScopeType scopeType;

public:
    int getNextOffset() const;

    ScopeType getScopeType() const;

    Variable& insert(const Variable& newVar, unordered_map<string, Symbol*>& symbol_table);

    virtual ~Scope();

    Scope(enum ScopeType scopeType, int offset);
};



class Framework {
private:
    std::stack<Scope> scopes;
    std::unordered_map<string, Symbol*> symbol_table;
    std::deque<Function> functions;

    Framework();

public:
    bool contains(const string& name);
    bool mainExists = false;

    static Framework& getInstance();
    void insertVariableIntoTopScope(const Variable &newVar);
    void addScope(enum Scope::ScopeType scopeType);
    void addFunction(const Function &newFunc);
    Symbol& operator[](const string& name); //for accessing the symbol_table
    Scope& getTopScope();
};


#endif //HW3_FRAMEWORK_H
