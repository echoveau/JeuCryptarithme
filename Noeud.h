#ifndef NOEUD_H
#define NOEUD_H

#include <iostream>
#include <vector>
#include "variable.h"
#include "domaine.h"
#include "contrainte.h"

class Noeud
{
public:
    Noeud(int cv,std::vector<Variable> vars,std::vector<Contrainte> conts);
    bool checkConstraintInNoeud();
    void addChildren();
    void afficherVariableCourante();
    std::vector<Noeud> children;

private:
    int currentVariable;
    std::vector<Variable> variables;
	std::vector<Contrainte> contraintes;
};

#endif // NOEUD_H