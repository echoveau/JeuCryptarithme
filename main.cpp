#include <iostream>
#include "variable.h"
#include "domaine.h"
#include "contrainte.h"
#include "Noeud.h"
#include <cstring>
#include <vector>

using namespace std;

//######################################################################################################
//              METHODES

//Retourne la taille du plus grand mot qui nous permettra de savoir le nombre de retenu
int trouverTailleDuResultat(vector<string> &mots){
    unsigned int taille = 0;
    for(string mot : mots){
        if(taille < mot.size()){
            taille = mot.size();
        }
            
    }
    return taille-1;
}


//Retrouve la variable lettre depuis une lettre
Variable trouverVariableDepuisLettre(string lettre,  vector<Variable> variables){
    for(Variable var : variables){
        if(lettre == var.getLettre()){
           return var;
        }
    }
}

//Retourne vrai si mot est le dernier mot de la liste mots
bool estLeDernier(string mot,vector<string> mots){
    return mots[mots.size()-1] == mot;
}

//Inverse le mot
vector<string> inverseMots(vector<string> mots){
    vector<string> imots;
    for(string mot : mots){
        string m;
        for(int i=mot.size()-1;i>=0;--i){
            string l(1,mot[i]);
            m += l;
        }
        imots.push_back(m);
    }
    return imots;
}

//Verifie si une contraintes n'est pas respectée, auquel cas, on coupe la branche de l'arbre
bool checkAllConstraints(vector<Contrainte> contraintes){
    for(Contrainte c : contraintes){
        if(c.checkContrainte()==0)
            return false;
    }
    return true;
}

//Compte le nombre de contraintes réspectées
int numberOfTrueConstraints(vector<Contrainte> contraintes){
    int count = 0;
    for(Contrainte c : contraintes){
        if(c.checkContrainte()==1)
            count++;
    }
    return count;
}

/*
//Supprime une variable de la liste
void deleteVar(string lettre,vector<Variable> variables){
    for(int i =0; i<variables.size();++i){
        if(variables.at(i).getLettre()==lettre){
            variables.erase(i)
        }
    }
}*/
//######################################################################################################

int main(int argc, char* argv[])
{
    vector<Variable> variables;
    vector<Domaine> domaines;
    vector<string> mots;

    //Les premiers arguments correspondent aux opérandes
    // Le dernier element de "mots" correspond au résultat de l'adition
    for(int i=1; i<argc ; ++i) {     
        mots.push_back(argv[i]);
    }

    // Création des variables

    //Variable des lettres
    Domaine d2 = Domaine(0,9); //définition du domaine des lettres
    domaines.push_back(d2);
    for(string mot : mots){
        for(char lettre : mot){
            string lettreToString(1,lettre);
            bool estDansListe = false; //Permet de déterminer si la variable à déjà été prise en compte
            for(Variable v : variables){
                if(v.getLettre() == lettreToString){
                    estDansListe = true;
                }
            }
            if(!estDansListe)
                variables.push_back(Variable(lettreToString,d2));
        }
    }

    //Variable retenu
    Domaine d1 = Domaine(0,mots.size()-2);
    domaines.push_back(d1);
    int nombreRetenu = trouverTailleDuResultat(mots);
    for(int i = 1; i < nombreRetenu+1 ; i++){
        string R = "R"+to_string(i);
        variables.push_back(Variable(R,d1));
    }
  

    //Création des contraintes
    vector<Contrainte> contraintes;
    contraintes.push_back(Contrainte(variables));       //alldiff

    mots = inverseMots(mots);

    int nbMots = mots[mots.size()-1].size()-1; // Nombre de mot -1 pour réaliser la boucle

    for(int i = nbMots; i >= 0 ; i--){
        std::vector<Variable> gauche;
        std::vector<Variable> droite;
       
        //Ajout de la variable dans la contrainte
        for(string mot : mots){
            if(i<mot.size() && mot[i]){
                string lettreToString(1,mot[i]);
                Variable var = trouverVariableDepuisLettre(lettreToString, variables);
                //Determine si il faut mettre à droite ou à gauche
                if(estLeDernier(mot,mots)) droite.push_back(var);
                else gauche.push_back(var);
            }
            //cout<<endl;
        }

        //Ajout de la retenue dans la contrainte
        if(i > 0){
            string R1 = "R"+to_string(i);
            gauche.push_back(trouverVariableDepuisLettre(R1,variables));
        }
        if(i < nbMots){
            string R2 = "R"+to_string(i+1);
            droite.push_back(trouverVariableDepuisLettre(R2,variables));
        }
        contraintes.push_back(Contrainte(gauche,droite)); 
    }



    //###############################################################################################
    //                  TEST
    
    //Affichage des contraintes
    for(Contrainte c : contraintes){
        c.afficherContrainte();  
    }

    //On met la variable M à 1
    for(Variable var : variables){
        if(var.getLettre()=="M"){
            var.setValeur(1);
        }
    }

    cout<<endl;
    //###############################################################################################
    //                  ARBRE

    Noeud racine = Noeud(1,variables,contraintes);

    while(!racine.checkConstraintInNoeud()){
        racine.afficherVariableCourante();
        if(!racine.children.empty()){
            racine = racine.children.at(0);
            racine.afficherVariableCourante();
        }
    }
    return 0;
}

