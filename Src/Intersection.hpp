#ifndef _INTERSECTION_HPP
#define _INTERSECTION_HPP

class Intersection;

#include "Objet.hpp"
#include "Point.hpp"
#include "Scene.hpp"

class Objet;
class Scene;

/**
 * \class Intersection
 * Classe permettant de représenter un point d'intersection entre
 * un rayon et un objet. Cette classe hérite des coordonnées du point
 * d'intersection de la classe Point et stocke en plus des informations
 * sur l'objet intersecté et sur la distance paramétrique entre le point et
 * l'origine du rayon.
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
class Intersection : public Point {
private:
  Objet *objet;/**< Pointeur vers l'objet intersecté*/
  float distance;/**< Distance paramétrique entre le point d'intersection et l'origine du rayon */
public:
  /**
   * Construit une intersection vide (sans objet intersecté).
   */
  Intersection();

  /**
   * Construit une intersection initialisé avec la valeur des paramètres.
   * @param p les coordonnées du point d'intersection
   * @param o l'objet intersecté
   * @param t la distance paramétrique entre l'origine du rayon et p
   */
  Intersection(const Point& p, Objet* o, const float& t);
  /**
   * Détruit l'intersection. L'objet référencé par l'intersection n'est pas
   * supprimé.
   */
  ~Intersection(){};

  /**
   * Récupération de la distance paramétrique entre l'origine du rayon 
   * et le point d'intersection.
   */
  inline float getDistance() { return distance; }

  /**
   * Calcul de la couleur de l'objet telle que perçue à la position de 
   * l'observateur par la formule de Phong. Si la profondeur indiquée lors
   * de l'appel est supérieure à 0 et que le matériau de l'objet dispose
   * d'une composante spéculaire, une contribution par réflexion est ajoutée
   * à la valeur calculée.
   * @param sc la scène virtuelle en cours de calcul. Ce paramètre est nécessaire
   * en cas de déclenchement de la récursion du lancer de rayons, si le paramètre
   * profondeur a une valeur supérieure à 0.
   * @param obs le point depuis lequel le point d'intersection courant est vu.
   * Ce paramètre correspond à l'origine du rayon auant créé l'intersection
   * courante.
   * @param profondeur indique la profondeur de la récursion pour le calcul
   * d'éclairage par lancer de rayons. Une profondeur de 0 ne calculera ainsi
   * que l'éclairage direct des objets visibles depuis la caméra. Une valeur de 1
   * déclenchera le calcul de l'effet d'une réflexion de lumière ; 
   * une valeur de 2 de deux réflexion, et ainsi de suite.
   * @return la couleur obtenue au point d'intersection,  suite au calcul
   * d'éclairage effectué par lancer de rayons.
   */
  Couleur getCouleur(const Scene & sc, const Point& obs, int profondeur);

  /**
   * Récupère la normale à l'objet au point d'intersection.
   */
  Vecteur getNormale() const;
};
#endif
