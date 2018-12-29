//
// Created by Dorin Keshales on 2018-12-25.
//

#ifndef FIRSTMILESTONE_BINDER_H
#define FIRSTMILESTONE_BINDER_H

#include <string>
#include "SymbolTable.h"
#include <regex>

class Binder {
private:
    SymbolTable *symbolTable;
public:
    Binder(SymbolTable *symbolT) : symbolTable(symbolT) {};

    void bind(string newVar, string keeper);
};

#endif //FIRSTMILESTONE_BINDER_H
