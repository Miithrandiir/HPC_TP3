#ifndef _OBJET_HPP
#define _OBJET_HPP

#include <iostream>
using namespace std;

#include "Materiau.hpp"
#include "Rayon.hpp"
#include "Intersection.hpp"
#include "Intensite.hpp"
#include "Scene.hpp"

/**
 * \class Objet 
 * Classe abstraite permettant de représenter un objet générique
 * et les méthodes et attributs dont un objet spécifique doit disposer,
 * pour pouvoir être utilisé dans un algorithme de lancer de rayons.
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
class Objet {
private:
  Materiau mat;/**< Matériau de l'objet */
public:
  /** 
   * Construit un objet avec le matériau par défaut
   */
  Objet();
  
  /**
   * Construit un objet avec un matériau spécifique
   * @param m le matériau dont est constitué l'objet
   */
  Objet(Materiau m);

  /**
   * Détruit l'objet
   */
  ~Objet();

  /**
   * Calcule l'intersection entre un rayon et l'objet si elle existe. 
   * Cette méthode doit être implantée par chaque classe héritant de Objet.
   * @param r le rayon pour lequel il faut calculer l'intersection
   * @param inter l'intersection trouvée si elle existe
   * @return true si une intersection est trouvée, auquel cas le paramètre
   * inter contient la description de cette intersection ; false sinon.
   */
  virtual bool intersecte(const Rayon& r, Intersection& inter)=0;

  /**
   * Détermine si l'objet coupe le rayon entre son origine
   * et l'extrémité de son vecteur directeur.
   * Cette méthode doit être implantée par chaque classe héritant de Objet.
   * @param r le rayon pour lequel le test doit être effectué
   * @return true si l'objet coupe le rayon entre son origine
   *  et l'extrémité de son vecteur directeur, false sinon.
   */
  virtual bool coupe(const Rayon& r) = 0;


  Couleur getCouleur();

  /**
   * Indique si le matériau de l'objet dispose d'une composante spéculaire
   * @return true si le matériau a une composante spéculaire, false sinon.
   */
  bool isSpecular();

  /**
   * Calcul du rayon réfléchi en un point de l'objet.
   * @param obs la position depuis laquelle le point p est vu
   * @param p un point d'intersection sur l'objet
   * @return le rayon réfléchi, considéré comme le symétrique
   * par rapport à la direction d'incidence ObsP. Le rayon retourné
   * est normalisé.
   */
  Rayon getReflechi(const Point& obs, const Intersection& p);

  /**
   * Calcul l'intensité ambiante réflechie par le matériau de l'objet.
   * @param ambiant l'intensite ambiante reçue de l'environnement
   * @return l'intensite ambiante réfélchie par le matériau de l'objet en
   * fonction de l'intensite reçu depuis la source ambiante.
   */
  Couleur calculerAmbiant(const Intensite& ambiant);

  /**
   * Calcul de l'éclairage direct reçu en un point depuis chaque source
   * de la scène. la fonction premd en compte le fait que les sources soient
   * visibles depuis le point considéré et calcule la contribution diffuse et
   * la contribution spéculaire de la formule de Phong.
   * @param obs la position depuis laquelle le point p est vu
   * @param sc la scène
   * @param p un point d'intersection sur l'objet
   * @return l'intensité lumineuse directe réflechie par l'objet au point
   * considéré, par calcul des composantes diffuses et spéculaires de la 
   * formule de Phong.
   */
  Couleur calculerDirect(const Point &obs, const Scene& sc, Intersection &p);

  /**
   * Calcule la normale à la surface de l'objet au point considéré.
   * Cette méthode doit être implantée par chaque classe héritant de Objet. 
   * Le vecteur retourné doit être normalisé.
   * @param p le point auquel la normale doit être calculée
   * @return la normale à la surface de l'objet au point considéré. Le vecteur
   * retourné est normalisé.
   */
  virtual Vecteur getNormale(const Point &p) = 0;

  /**
   * Affichage du contenu de l'objet sur le flot de sortie, dans un format
   * lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param o  l'objet à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Objet & o);

  virtual void affiche(ostream& out);


};
#endif
