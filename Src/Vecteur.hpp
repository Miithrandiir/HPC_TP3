/* Vecteur.hpp: interface de la classe Vecteur*/
#ifndef __VECTEUR_HPP
#define __VECTEUR_HPP

#include <iostream>
using namespace std;

#include "Point.hpp"

/** 
 * \class Vecteur
 * Classe de base représentant un vecteur en trois dimensions.
 * Les vecteurs ne sont pas normalisés à leur création.
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
class Vecteur {
public:
  float dx, dy, dz;
public:
  /**
   * \brief Constructeur par défaut.
   *  
   * Ce constructeur donne au vecteur les coordonnées nulles par défaut.
   */
  Vecteur();
 
  /**
   * Constructeur paramétrique.
   * @param Xp	coordonnée en <CODE>X</CODE> du vecteur &agrave; créer.
   * @param Yp	coordonnée en <CODE>Y</CODE> du vecteur &agrave; créer.
   * @param Zp	coordonnée en <CODE>Z</CODE>du vecteur &agrave; créer.
   */
  Vecteur(float Xp, float Yp, float Zp);

  /**
   * Constructeur paramétrique.
   * @param PA	point de départ du vecteur à créer.
   * @param PB	point de d'arrivée du vecteur à créer.
   */
  Vecteur(const Point& PA, const Point& PB);

  /**
   * Destructeur par défaut.
   */
  ~Vecteur();

  void set(const double &x, const double &y, const double &z);

  /**
   ** Normalise le vecteur courant.
   */
  void normaliser();

  /**
   * Produit scalaire entre deux vecteurs.
   * @param v le second vecteur avec lequel effectuer le calcul du produit scalaire.
   * @return le produit scalaire entre le vecteur courant et v
   */
  float operator*(const Vecteur& v);

  /**
   * Produit du vecteur courant par un scalaire.
   * @param k le coefficient multiplicatif
   * @return le produit k x vecteur courant
   */
  Vecteur operator*(float k);

  /**
   * Addition de deux vecteurs
   * @param v le vecteur à additionner au vecteur courant
   * @return un vecteur représentant la somme du vecteur courant et de v
   */
  Vecteur operator+(const Vecteur& v);

  /**
   * Soustraction de deux vecteurs
   * @param v le vecteur à soustraire du vecteur courant
   * @return un vecteur représentant la différence du vecteur courant et de v
   */
  Vecteur operator-(const Vecteur& v);

  /**
   * Produit vectoriel entre deux vecteurs.
   * @param u la première opérande du produit vectoriel
   * @param v la seconde  opérande du produit vectoriel  
   * @return le produit vectoriel entre u et v
   */
  static Vecteur cross(const Vecteur &u, const Vecteur& v);

  /**
   * Affichage de la description d'un vecteur sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param v le vecteur à afficher
   * @return le flot modifié
   */  friend ostream& operator<<(ostream & sortie, const Vecteur & v);
};



#endif 
