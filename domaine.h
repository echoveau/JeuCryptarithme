#ifndef DOMAIN_H
#define DOMAIN_H

#include <iostream>
#include <vector>

/*
 * le domaine, défini l'ensemble des données pour une variable.
 * Exemple de domaines :
 *      Domain d1(0,1)
 *      Domain d2(0,9)
 *      Domain d3({1,2,7,8})
 */

class Domaine
{
public:
    Domaine(int debut, int fin);
    Domaine(std::vector<int> intervalSpecial);
    int debut;
    int fin;

private:
    std::vector<int> intervalSpecial;
};

#endif // DOMAIN_H
