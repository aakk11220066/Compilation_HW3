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

#include "Symbol.h"
#include "Exceptions.h"

class Scope{
private:
    std::deque<Variable> variables;
    int nextOffset;
public:
    int getNextOffset() const;

public:
    enum ScopeType{IF, LOOP, FUNCTION, BLOCK} scopeType;

    Variable& insert(const Variable& newVar);

    virtual ~Scope();

    Scope(enum ScopeType scopeType, int offset);
};


//singleton
class Framework {
private:
    std::stack<Scope> scopes;
    std::deque<Function> functions;
    std::unordered_map<string, Symbol*> symbol_table;

    bool contains(const string& name);
    Framework();

public:
    static Framework getInstance();
    void insertVariableIntoTopScope(const Variable &newVar);
    void addScope(enum Scope::ScopeType scopeType);
    void addFunction(const Function &newFunc);
    Symbol& operator[](const string& name); //for accessing the symbol_table
};


#endif //HW3_FRAMEWORK_H
