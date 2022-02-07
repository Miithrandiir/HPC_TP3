#ifndef __SOURCE_HPP
#define __SOURCE_HPP

#include <iostream>
using namespace std;

#include "Point.hpp"
#include "Intensite.hpp"

/**
 * \class Source
 * Classe permettant de représenter une source ponctuelle isotrope. 
 * Celle-ci sera représentée par une position et une intensité.
 * Afin de faciliter leur utilisation, les attributs d'une source sont publics.
 *
 * @author  C. Renaud
 * @version 1.0
 * @date Janvier 2021
 * @remark Cette classe fait partie de l'application de lancer de rayons simplifiée 
 * développée pour servir d'exemple aux travaux pratiques dans les modules "High Parallel
 * Computing" et "Initiation à la recherche" du master informatique de l'Université du
 * Littoral Côte d'Opale. 
 * 
 */
class Source {
public:
  Point position;/**< Coordonnées de la source */
  Intensite intensite;/**< Intensité de la source */
public:
  /**
   * Construit une source par défaut, localisée en (0,0,0), d'intensité (1,1,1)
   */
  Source();
 

  /**
   * Construit une source initialisée avec les paramètres fournis.
   * @param p les coordonnées de la source
   * @param i l'intensite de la source
   */
  Source(const Point& p, const Intensite& i);

  /**
   * Détruit le rayon.
   */
  ~Source();

  /**
   * Affichage de la description d'une source sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param s la source à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Source & s);
};



#endif 
