#include "variable.h"

Variable::Variable(std::string l,Domaine d)
    :lettre(l),domaine(d),valeur(-1){}


std::string Variable::getLettre(){
    return lettre;
}

int Variable::getValeur(){
    return valeur;
}

void Variable::setValeur(int v){
    valeur = v;
}