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
    std::deque<Variable> identifiers;
    int nextOffset = 0;
public:
    enum ScopeType{IF, LOOP, FUNCTION};

    const enum ScopeType scopeType;

    bool contains(const string& name);

    void insert(const Variable& newVar);

    int getNextOffset() const;

    virtual ~Scope();

    explicit Scope(enum ScopeType scopeType, int offset);
};



class Framework {
private:
    static std::stack<Scope> scopes;
    static std::stack<int> offsets;
    std::unordered_map<string, Symbol> symbol_table;
    static bool contains(const string& name);
public:
    static void insertIntoTopScope(const Symbol& newVar);
    static void addScope(const Scope& newScope);
    static bool functionExists(const std::string& id);
};


#endif //HW3_FRAMEWORK_H
