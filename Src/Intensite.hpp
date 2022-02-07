#ifndef _INTENSITE_HPP
#define _INTENSITE_HPP

#include <iostream>
using namespace std;

/**
 * \class Intensite
 * Classe permettant de représenter une intensité lumineuse dans le modèle RVB
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
class Intensite {
private:
  float rouge;/**< intensité rouge - valeur >= 0 */
  float vert;/**< intensité verte - valeur >=0 */
  float bleu;/**< intensité bleue - valeur >= 0 */
public:
  /**
   * Création d'une intensite blanche, de valeurs (1.0, 1.0, 1.0)
   */
  Intensite();

  /**
   * Création d'une intensité de valeurs (r, v, b). Une composante négative
   * sera remise à 0.
   */
  Intensite(float r, float v, float b);
  
  /**
   * Détruit l'intensité
   */  
  ~Intensite();

  /**
   * Modifie la valeur de l'intensité en lui affectant les valeurs
   * (r, v, b). Une composante négative sera remise à 0.
   */  
  void set(float r, float v, float b);
  
  /**
   * Récupère la composante rouge de l'intensité, sous forme d'un
   * nombre réel.
   */
  inline float getR() const { return rouge;}
  /**
   * Récupère la composante verte de l'intensité, sous forme d'un
   * nombre réel.
   */
  inline float getV() const { return vert;}
  /**
   * Récupère la composante bleue de l'intensité, sous forme d'un
   * nombre réel.
   */
  inline float getB() const { return bleu;}

  /**
   * Produit d'une intensité par un scalaire
   * @param k le scalaire multiplicateur
   * @return kxl'intensité initiale
   */
  Intensite operator*(float k);
  
  /**
   * Produit d'un scalaire par une intensité, sous la forme k x I
   * @param k le scalaire multiplicateur
   * @param I l'intensité à multiplier
   * @return k x I
   */
  friend Intensite operator*(float k, const Intensite& I){
    return Intensite(k*I.rouge, k*I.vert, k*I.bleu);
  }
  /**
   * Affichage de la description de l'intensité sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param i l'intensité à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Intensite & i);
};

#endif

