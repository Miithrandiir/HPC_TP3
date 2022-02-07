#ifndef _SPHERE_HPP
#define _SPHERE_HPP

#include <iostream>
using namespace std;

#include "Point.hpp"
#include "Objet.hpp"

/**
 * \class Sphere
 * Classe permettant de représenter une sphère.
 * La sphère est donnée par les coordonnées de son centre et son rayon.
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

class Sphere : public Objet {
private:
  Point centre; /**< Coordonnées du centre de la sphère */
  float rayon; /** < Rayon de la sphère */
public:
  /**
   * Construit une sphère de centre O et de rayon 1.
   */
  Sphere();
  
    /**
   * Construit une sphère de centre (xc, yc, zc), de rayon r
   * et de matériau m.
   * @param xc abscisse du centre de la sphère
   * @param yc hauteur du centre de la sphère
   * @param zc ordonnée du centre de la sphère
   * @param r le rayon de la sphère
   * @param m le matériau de la sphère
   */
  Sphere(float xc, float yc, float zc, float r, Materiau m);

  /**
   * Détruit la sphère
   */
  ~Sphere();

  /**
   * Calcule l'intersection entre un rayon et la sphère, si elle existe. 
   * @param r le rayon pour lequel il faut calculer l'intersection
   * @param inter l'intersection trouvée si elle existe
   * @return true si une intersection est trouvée, auquel cas le paramètre
   * inter contient la description de cette intersection ; false sinon.
   */
  bool intersecte(const Rayon& r, Intersection& inter);
  
  /**
   * Détermine si la sphère coupe le rayon entre son origine
   * et l'extrémité de son vecteur directeur.
   * @param r le rayon pour lequel le test doit être effectué
   * @return true si la sphère coupe le rayon entre son origine
   *  et l'extrémité de son vecteur directeur, false sinon.
   */
  bool coupe(const Rayon& r);

  /**
   * Calcule la normale à la surface de la sphère au point considéré.
   * Le vecteur retourné doit être normalisé.
   * @param p le point auquel la normale doit être calculée
   * @return la normale à la surface de la pshère au point considéré. 
   * Le vecteur retourné est normalisé.
   */
  virtual Vecteur getNormale(const Point &p);
  
  /**
   * Affichage de la description de la sphère sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param s la sphère à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Sphere & s);

  virtual void affiche(ostream& out);


};
#endif
