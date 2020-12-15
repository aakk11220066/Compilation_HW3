#include "Exceptions.h"

list<string> varsListToTypesList(const list<Variable>& varList){
    list<string> result = list<string>();
    for (const Variable& var : varList){
        result.push_back(var.type);
    }
    return result;
}