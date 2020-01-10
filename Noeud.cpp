#include "Noeud.h"


Noeud::Noeud(int cv,std::vector<Variable> vars,std::vector<Contrainte> conts){
    currentVariable=cv;
    variables=vars;
    contraintes=conts;
}

bool Noeud::checkConstraintInNoeud(){
    unsigned int numberOfOne=0;
    bool branchIsGood=true;
    for(Contrainte c : contraintes){
        std::cout<<c.checkContrainte()<<std::endl;
        if(c.checkContrainte()==0)
            branchIsGood=false;
        if(c.checkContrainte()==1)
            ++numberOfOne;
    }

    std::cout<<std::endl<<numberOfOne<<"     "<<contraintes.size()<<std::endl<<std::endl;

    if(numberOfOne==contraintes.size()){

        return true;
    }
    else{
        if(branchIsGood)
            addChildren();
        //sinon, on ajoute pas d'enfant, la branche est morte
        return false;
    }
}

void Noeud::addChildren(){
    for(int i=variables.at(currentVariable).domaine.debut; i<variables.at(currentVariable).domaine.fin;++i){    
    	if((unsigned)currentVariable+1 < variables.size()){
            std::vector<Variable> variablesSuivantes;
            for(Variable var : variables){
                variablesSuivantes.push_back(var);
            }
            variablesSuivantes.at(currentVariable).setValeur(i);
            children.push_back(Noeud(currentVariable+1,variables,contraintes));
            std::cout<<children.size()<<std::endl;
        }	
    }
}


void Noeud::afficherVariableCourante(){
    std::cout<<variables.at(currentVariable).getLettre()<<" "<<variables.at(currentVariable).getValeur()<<std::endl;
}