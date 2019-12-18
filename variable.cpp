#include "variable.h"

Variable::Variable(std::string l,Domaine d)
    :lettre(l),domaine(d){}


std::string Variable::getLettre(){
    return lettre;
}