#include "Framework.h"


bool Scope::contains(const string &name) {
    for (const RetType& id : identifiers)
        if (id.name == name) return true;
    return false;
}

Scope::Scope(const Scope::ScopeType scopeType) : scopeType(scopeType) {}

void Scope::insert(const RetType &newVar) {
    nextOffset++;
    identifiers.push_back(newVar);
}

Scope::~Scope() {
    output::endScope();
}

int Scope::getNextOffset() const {
    return nextOffset;
}

bool Framework::contains(const string &name) {
    std::stack<Scope> copyOfScopesStack = scopes;
    while (!copyOfScopesStack.empty()){
        if (copyOfScopesStack.top().contains(name)) return true;
        copyOfScopesStack.pop();
    }
    return false;
}

void Framework::insertIntoTopScope(const RetType &newVar) {
    if (contains(newVar.name)) throw Exceptions::AlreadyExistsException();
    scopes.top().insert(newVar);
}

void Framework::addScope(const Scope &newScope) {
    scopes.push(newScope);
}
