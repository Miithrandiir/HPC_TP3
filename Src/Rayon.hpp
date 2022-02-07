#ifndef _RAYON_HPP
#define _RAYON_HPP

#include "Point.hpp"
#include "Vecteur.hpp"

#include <iostream>
using namespace std;

/**
 * \class Rayon
 * Classe permettant de représenter un rayon. Le rayon est représenté sous
 * la forme d'une demi-droite paramétrique telle que : R = O + tD, avec :
 * - R le rayon
 * - O le point d'origine du rayon
 * - D le vecteur directeur du rayon
 * - t >=0 le paramètre définissant l'ensemble des points de la demi-droite.
 * Afin de faciliter leur utilisation, les attributs d'un rayon sont publics.
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
class Rayon {
public:
  Point origine; /**< Origine du rayon */
  Vecteur direction; /**< Vecteur directeur du rayon */

public:
  /**
   * Construit un rayon vide.
   */
  Rayon();

  /**
   * Construit un rayon  initialisé avec les paramètres fournis.
   * @param o l'origine du rayon
   * @param d le vecteur directeur du rayon
   */
  Rayon(const Point& o, const Vecteur& d);

  /**
   * Détruit le rayon.
   */
  ~Rayon();

  /**
   * Affichage de la description d'un rayon sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param out le flot de sortie
   * @param r le rayon à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream& out, const Rayon& r);

};//Rayon

#endif
