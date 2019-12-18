#include <iostream>
#include "contrainte.h"

Contrainte::Contrainte(std::vector<Variable> gauche,std::vector<Variable> droite)
    :gauche(gauche), droite(droite){}

Contrainte::Contrainte(std::vector<Variable> alldiff)
    :alldiff(alldiff){}

void Contrainte::afficherContrainte(){
    std::cout<<" ";
    for(Variable var : gauche){
       std::cout<<var.getLettre()<<" + "; 
    }

    std::cout<<" = ";

    for(Variable var : droite){
        std::cout<<var.getLettre()<<" + "; 
    }

    std::cout<<std::endl;
}

