#ifndef VARIABLE_H
#define VARIABLE_H
#include "domaine.h"

/*
 * Exemple :
 *      Variable E("E", d2)     //Avec d2 étant un domain
 */

class Variable
{
public:
    Variable(std::string l, Domaine d);
    std::string getLettre();
private:
    std::string lettre;
    Domaine domaine;
};

#endif // VARIABLE_H
