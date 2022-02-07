#ifndef _PLAN_HPP
#define _PLAN_HPP

#include <iostream>
using namespace std;

#include "Objet.hpp"

/**
 * \class Plan
 * Classe représentant un plan infini d'équation a.x + b.y +c.z + d =0.
 * La classe implante les méthodes permettant sont utilisation dans le cadre
 * d'un algorithme de lancer de rayons.
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

class Plan : public Objet {
private:
  float a, b, c, d;/**< Coefficients de l'équation du plan */
public:
  /**
   * Construit un plan horizontal d'équation y=0
   */
  Plan();
  /**
   * Construit un plan d'équation a.x + b.y +c.z + d =0, de matériau m
   * @param a coefficient du plan selon l'axe Ox
   * @param b coefficient du plan selon l'axe Oy
   * @param c coefficient du plan selon l'axe Oz
   * @param d décalage du plan par rapport à l'origine
   * @param m matériau du plan.
   */
  Plan(float a, float b, float c, float d, Materiau m);

  /**
   * détruit le plan
   */
  ~Plan();

  /**
   * Calcule l'intersection entre un rayon et le plan si elle existe. 
   * @param r le rayon pour lequel il faut calculer l'intersection
   * @param inter l'intersection trouvée si elle existe
   * @return true si une intersection est trouvée, auquel cas le paramètre
   * inter contient la description de cette intersection ; false sinon.
   */
  bool intersecte(const Rayon& r, Intersection& inter);

  /**
   * Détermine si le plan coupe le rayon entre son origine
   * et l'extrémité de son vecteur directeur.
   * @param r le rayon pour lequel le test doit être effectué
   * @return true si le plan coupe le rayon entre son origine
   *  et l'extrémité de son vecteur directeur, false sinon.
   */
  bool coupe(const Rayon& r);

    /**
   * Calcule la normale à la surface du plan au point considéré.
   * Le vecteur retourné doit être normalisé.
   * @param p le point auquel la normale doit être calculée
   * @return la normale à la surface du plan au point considéré. Le vecteur
   * retourné est normalisé.
   */
  virtual Vecteur getNormale(const Point &p);


  /**
   * Affichage de la description du plan sur le flot de sortie, dans un format
   * lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param p le plan à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Plan & p);



  virtual void affiche(ostream& out);

};
#endif
