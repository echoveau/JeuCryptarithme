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


/*
    Cette fonction retourne un entier :
        -1  Si la contrainte est indéfini 
                (Par exemple si on ne connait pas une valeur de l'équation : M=3,R1=2,S=??)
        0   Si la contrainte n'est pas respectée 
                (Par exemple si M=3,R1=2,S=4 et M+R1=S alors on retourne 0)    
        1   Si la contrainte est respectée 
                (Par exemple si M=3,R1=1,S=4 et M+R1=S alors on retourne 1)    
*/
int Contrainte::checkConstraint(){
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
                    return 0;
            }
        }
        return 1;
    }
    else{
        // On met toutes les valeurs des variables gauche dans un tableau
        int valeursGauche=0;
        for(Variable v : gauche) {
            if(v.getValeur()==-1){
                return -1;
            }
            valeursGauche = valeursGauche + v.getValeur();
        } 
        // On met toutes les valeurs des variables droite dans un tableau
        int valeursDroite=0;
        for(Variable v : droite) {
            if(v.getValeur()==-1){
                return -1;
            }
            valeursDroite = valeursDroite + v.getValeur();
        }

        if(valeursGauche!=valeursDroite) return 0;

        return 1;
    }
}