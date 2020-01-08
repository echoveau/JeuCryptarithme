#ifndef CONTRAINTE_H
#define CONTRAINTE_H
#include "variable.h"

class Contrainte
{
public:
    Contrainte(std::vector<Variable> gauche,std::vector<Variable> droite); //addition
    //Contrainte(Variable gauche,Variable droite); //égalité
    Contrainte(std::vector<Variable> alldiff); //alldiff
    void afficherContrainte();
    bool checkContrainte();
private:
    std::vector<Variable> gauche;
    std::vector<Variable> droite;
    std::vector<Variable> alldiff;

};

#endif // CONTRAINTE_H
