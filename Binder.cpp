//
// Created by lev on 24/12/18.
//
#include "Binder.h"

/**
 * The binding.
 * @param newVar
 * @param keeper
 */
void Binder::bind(string newVar, string keeper) {
    regex pathFormat("\"(.+)\"");
    if (regex_match(keeper, pathFormat)) {
        string pathToWhichWeBind = keeper.substr(1, keeper.length() - 2);
        /*
         * Because the Binder always saves only representatives of each link to varValuesPaths, the varValuesPaths represents
         * a bijective function. That is, each representative is saved once(key) and has a unique path(value).
         * The Binder works with SymbolTable which's varValuesPath is bijective.Otherwise, an exception is thrown.
         * Therefore this vector must have only key-value pair(else, we throw an exception).
         */
        vector<string> vectorWithVarsOfThisPath = this->symbolTable->getVarValuesPaths()->getVariablesOfPath(
                pathToWhichWeBind);
        if (vectorWithVarsOfThisPath.size() > 1) {
            throw "Error. Binder operates only on SymbolTables with bijective varValuesPaths object.";
        }
        if (vectorWithVarsOfThisPath.size() == 1) {
            //first argument is a new var. Second argument is an existing var.
            this->symbolTable->bindNewVarToExistingLink(newVar, vectorWithVarsOfThisPath[0]);
        } else {
            this->symbolTable->createNewLinkWithNewVar(newVar, pathToWhichWeBind);
        }
    } else if (this->symbolTable->isVarExist(keeper)) {
        this->symbolTable->bindNewVarToExistingLink(newVar, keeper);
    } else {
        throw "Error. The binder cannot bind a new variable to non-existing variable.";
    }

}