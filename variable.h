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
    Variable(String l,Domain d);
private:
    String lettre;
    Domaine domaine;
};

#endif // VARIABLE_H
