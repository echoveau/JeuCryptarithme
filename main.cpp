#include <iostream>
#include "variable.h"
#include "domaine.h"
#include <cstring>
#include <vector>

using namespace std;

//Retourne la taille du plus petit mot qui nous permettra de savoir le nombre de retenu
int trouverTaillePlusPetitMot(vector<string> mots){
    int taille = 1000;
    for(string mot : mots){
        if(taille>mot.size())
            taille = mot.size();
    }
    return taille;
}


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
    Domaine d2 = Domaine(0,9);
    domaines.push_back(d2);
    for(string mot : mots){
        for(char lettre : mot){
            string lettreToString(1,lettre);
            variables.push_back(Variable(lettreToString,d2))
        }
    }

    //Varaiable retenu
    Domaine d1 = Domaine(0,mots.size()-2);
    domaines.push_back(d1);
    int nombreRetenu = trouverTaillePlusPetitMot(mots);

    for(int i = 1; i < nombreRetenu+1 ; i++){
        string R = "R"+i;
        variables.push_back(Variable(R,d1));
    }
  
    return 0;
}

