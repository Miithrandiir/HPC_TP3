#ifndef _MATERIAU_HPP
#define _MATERIAU_HPP

#include <iostream>
using namespace std;

#include "Couleur.hpp"

/**
 * \class Materiau
 * Classe permettant de représenter un matériau pour le  modèle de Phong
 * pour le calcul de l'éclairage. Les coefficients utilisés sont :
 * - ka : le cofficient de réflexion ambiant, qui précise la fraction de
 *        la lumière ambiante qui sera réfléchie par le matériau (dans [0, 1])
 * - kd : le cofficient de réflexion diffus, qui précise la fraction de
 *        la lumière issue des différentes sources de lumières présente dans
 *        la scène,  qui sera réfléchie de manière diffuse par le matériau 
 *        (dans [0, 1]) 
 * - ks : le cofficient de réflexion spéculaire, qui précise la fraction de
 *        la lumière issue des différentes sources de lumières présente dans
 *        la scène,  qui sera réfléchie de manière spéculaire par le matériau
 *        (dans [0, 1])
 * - s  : indice de brillance du matériau (s >> 1). Plus s est grand, 
 *        plus le matériau sera brillant.
 *
 * La classe contient également la couleur de base pour le matériau.
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
class Materiau {
private:
  Couleur coul; /**< couleur de base du materiau */
  float ka; /**< coefficient de réflexion ambiante (dans [0, 1])*/
  float kd; /**< coefficient de réflexion diffuse (dans [0, 1])*/
  float ks ; /**< coefficient de réflexion spéculaire (dans [0, 1])*/
  float s; /**< indice de brillance (s>>1)*/
public:
  /**
   * Construit un matériau par défaut, de couleur grise et de coefficients :
   * - ka = 0.05 coefficent de réflexion ambiant du matériau
   * - kd = 0.5 coefficent de réflexion diffus du matériau
   * - ks = 0.1 coefficent de réflexion spéculaire du matériau
   * - s = 10 indice de brillance du matériau
   */
  Materiau();

  /**
   * Construit un matériau, initialisé avec la valeur des différents paramètres.
   * @param c couleur de base de l'objet
   * @param ka coefficent de réflexion ambiant du matériau
   * @param kd coefficent de réflexion diffus du matériau
   * @param ks coefficent de réflexion spculaire du matériau
   * @param s indice de brillance du matériau
  */
  Materiau(Couleur c, float ka, float kd, float ks, float s);

    /**
   * Détruit le matériau.
   */
  ~Materiau();

    /**
   * Modifie les valeurs du matériau avec la valeur des différents paramètres.
   * @param c couleur de base de l'objet
   * @param ka coefficent de réflexion ambiant du matériau
   * @param kd coefficent de réflexion diffus du matériau
   * @param ks coefficent de réflexion spculaire du matériau
   * @param s indice de brillance du matériau
     */
  void set(Couleur c, float ka, float kd, float ks, float s);

  /**
   * Récupère la couleur du matériau.
   * @return la couleur du matériau
   */
  inline Couleur getCouleur(){return coul;}
  /**
   * Récupère le coefficient de réflexion ambiant du matériau.
   * @return  le coefficient de réflexion ambiant du matériau
   */
  inline float getKambiant(){ return ka;}
  /**
   * Récupère le coefficient de réflexion diffus du matériau.
   * @return  le coefficient de réflexion diffus du matériau
   */
  inline float getKd(){ return kd;}
  /**
   * Récupère le coefficient de réflexion spéculaire du matériau.
   * @return  le coefficient de réflexion spéculaire du matériau
   */
   inline float getKs(){ return ks;}
  /**
   * Récupère l'indice de brillance du matériau.
   * @return  l'indice de brillance du matériau
   */
  inline float getBrillance() { return s;}

  /**
   * Affichage de la description du matériau sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param m le matériau à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Materiau & m);

};

#endif
