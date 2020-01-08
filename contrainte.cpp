#include <iostream>
#include <algorithm>
#include "contrainte.h"

Contrainte::Contrainte(std::vector<Variable> gauche,std::vector<Variable> droite)
    :gauche(gauche), droite(droite), alldiff(std::vector<Variable>()){}

Contrainte::Contrainte(std::vector<Variable> alldiff)
    :gauche(std::vector<Variable>()), droite(std::vector<Variable>()), alldiff(alldiff){}

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


bool Contrainte::checkContrainte(){
    if(!alldiff.empty()){
        std::vector<int> valeurs;
        // On met toutes les valeurs des variables dans un tableau
        for(Variable v : alldiff) {
            valeurs.push_back(v.getValeur());
        }
        // On verifie que toutes les cases du tableau sont différentes
        for(int val : valeurs) {
            if(val!=-1){
                if(std::count(valeurs.begin(), valeurs.end(), val) > 1) 
                    return false;
            }
        }
        return true;
    }
    else{
        // On met toutes les valeurs des variables gauche dans un tableau
        int valeursGauche=0;
        for(Variable v : gauche) {
            if(v.getValeur()==-1){
                return false;
            }
            valeursGauche = valeursGauche + v.getValeur();
        } 
        // On met toutes les valeurs des variables droite dans un tableau
        int valeursDroite=0;
        for(Variable v : droite) {
            if(v.getValeur()==-1){
                return false;
            }
            valeursDroite = valeursDroite + v.getValeur();
        }

        if(valeursGauche!=valeursDroite) return false;

        return true;
    }
}