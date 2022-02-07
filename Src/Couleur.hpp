#ifndef _COULEUR_HPP
#define _COULEUR_HPP

#include <iostream>
using namespace std;

#include "Intensite.hpp"

/**
 * \class Couleur
 * Classe permettant de représenter une couleur dans le modèle RVB
 * (Rouge, Vert, Bleu).
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
class Couleur {
private:
  float rouge;/**< canal de couleur rouge - valeur dans [0,1] */
  float vert;/**< canal de couleur vert - valeur dans [0,1] */
  float bleu;/**< canal de couleur bleu - valeur dans [0,1] */
public:
  /**
   * Création d'une couleur gris clair, de valeurs (0.8, 0.8, 0.8)
   */
  Couleur();
  
  /**
   * Création d'une couleur de valeurs (r, v, b)
   */ 
  Couleur(float r, float v, float b);

  /**
   * Détruit la couleur
   */
  ~Couleur();

  /**
   * Modifie la valeur de la couleur en lui affectant les valeurs
   * (r, v, b)
   */
  void set(float r, float v, float b);

  /**
   * Récupère la composante rouge de la couleur, sous forme d'un
   * entier dans [0,255].
   */
  int getRougei();
  /**
   * Récupère la composante verte de la couleur, sous forme d'un
   * entier dans [0,255].
   */
  int getVerti();
  /**
   * Récupère la composante bleue de la couleur, sous forme d'un
   * entier dans [0,255].
   */
  int getBleui();

  /**
   * Récupère la composante rouge de la couleur, sous forme d'un
   * nombre réel.
   */
  inline float getR(){ return rouge;}
  /**
   * Récupère la composante verte de la couleur, sous forme d'un
   * nombre réel.
   */
  inline float getV(){ return vert;}
  /**
   * Récupère la composante bleue de la couleur, sous forme d'un
   * nombre réel.
   */
  inline float getB(){ return bleu;}

  /**
   * Produit d'une couleur par un scalaire
   * @param k le scalaire multiplicateur
   * @return kxla couleur initiale
   */
  Couleur& operator*(const float k);

  /**
   * Ajout d'une valeur de couleur à la couleur courante
   * @param c la valeur de couleur à ajouter
   * @return la couleur courante après ajout de c
   */
  Couleur& operator+=(const Couleur& c);
  
  /**
   * Ajout d'une valeur d'intensité à la couleur courante
   * @param I la valeur d'intensité à ajouter
   * @return la couleur courante après ajout de I
   */
  Couleur& operator+=(const Intensite& I);

  /**
   * Produit d'une couleur par une inensité
   * @param I l'intensité multiplicative
   * @return la couleur courante mulipliée par I
   */
  Couleur operator*(const Intensite& I);

  /**
   * Affichage de la description de la couleur sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param c la couleur à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Couleur & c);

  /**
   * Produit d'un scalaire par une couleur, sous la forme k x c
   * @param k le scalaire multiplicateur
   * @param c la couleur à multiplier
   * @return k x c
   */
  friend Couleur operator*(float k,  Couleur c){
    return c*k;
  }


};

#endif
