#ifndef HW3_NONTERMINALS_H
#define HW3_NONTERMINALS_H

#include <string>
#include "hw3_output.hpp"

using std::string;

class RetType{
public:
    const string name, type;
    const int offset;
    virtual ~RetType();
    RetType(const string &name, const string &type, int offset);
};


#endif //HW3_NONTERMINALS_H
