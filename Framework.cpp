#include "Framework.h"


void Scope::insert(const Variable &newVar) {
    nextOffset++;
    identifiers.push_back(newVar);
}

Scope::~Scope() {
    output::endScope();
}

//NOTE: must modify default offset of Variable to correct offset!
void Framework::insertVariableIntoTopScope(const Variable &newVar) {
    if (contains(newVar.name)) throw Exceptions::AlreadyExistsException();
    // TODO: modify offset of newVar
    scopes.top().insert(newVar);
}

Symbol &Framework::operator[](const string &name) {
    return <#initializer#>;
}
