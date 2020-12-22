#ifndef HW3_SOURCE_H
#define HW3_SOURCE_H

#include <string>
#include <list>
using namespace std;

#include "Symbol.h"

class NonTerminal{
public:
    string name;
    const string type;
    list<Variable> namesAndTypes = list<Variable>();
    list<string> arrguments_list = list<string>();
    NonTerminal() = default;
    NonTerminal(const string& name, const string& type) : name(name), type(type) {}
    NonTerminal& operator=(const NonTerminal& other){
        //  name = other.name;
        //  type = other.type;
        //  namesAndTypes = other.namesAndTypes;
        return *this;
    }
    void addParamToFunc(const string& name,const string& type){
        this->namesAndTypes.push_back(Variable(name, type));
    }
};

#endif //HW3_SOURCE_H
