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

#include "NonTerminals.h"
#include "Exceptions.h"

class Scope{
private:
    std::deque<RetType> identifiers;
public:
    enum ScopeType{IF, LOOP, FUNCTION};

    const enum ScopeType scopeType;

    bool contains(const string& name);

    virtual ~Scope();

    void insert(const RetType& newVar);

    explicit Scope(enum ScopeType scopeType);
};



class Framework {
private:
    static std::stack<Scope> scopes;
    static std::stack<int> offsets;
    //unnecessary - use contains method instead
    //std::unordered_map<string, RetType*> identifiers;
    static bool contains(const string& name);
public:
    static void insertIntoTopScope(const RetType& newVar);
};


#endif //HW3_FRAMEWORK_H
