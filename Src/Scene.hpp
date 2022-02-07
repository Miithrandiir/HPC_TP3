#ifndef _SCENE_HPP
#define _SCENE_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Objet.hpp"
#include "Couleur.hpp"
#include "Source.hpp"
#include "Rayon.hpp"
#include "Intersection.hpp"

class Objet;

/**
 * \class Scene
 * Classe permettant de représenter une scène et d'effectuer les calculs
 * de lancer de rayons avec les objets qui la composent.
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
class Scene {
private:
  vector <Objet *> objets;/**< liste des objets de la scène **/
  vector <Source *> sources;/**< liste des sources de la scène **/
  Source ambiante;/**< source ambiante */
  Couleur fond;/**< couleur de fond */
public:
  /**
   * Construit une scène vide.
   */
  Scene();
  /**
   * Détruit l'ensemble des objets et sources de la scène.
   */
  ~Scene();

  /**
   * Chargement de la scène
   * @param filename nom du fichier contenant la scène à charger
   * @return true si le fichier a été correctment chargé, false sinon
   */
  bool charger(string filename);

  /**
   * Ajoute un objet à la scène
   * @param o un pointeur vers l'objet à ajouter
   */
  void ajouter(Objet *o);

  /**
   * Calcule l'intersection entre un rayon et la scène si elle existe
   * @param r le rayon pour lequel il faut calculer l'intersection
   * @param inter l'intersection trouvée si elle existe
   * @return true si une intersection est trouvée, auquel cas le paramètre
   * inter contient la description de cette intersection ; false sinon.
   */
  bool intersecte(const Rayon& r, Intersection& inter) const;
  
  /**
   * Détermine si un objet de la scène coupe le rayon entre son origine
   *  et l'extrémité de son vecteur directeur.
   * @param r le rayon pour lequel le test doit être effectué
   * @return true si un objet de la scène coupe le rayon entre son origine
   *  et l'extrémité de son vecteur directeur, false sinon.
   */
  bool coupe(const Rayon &r) const;

  /**
   * Récupère la couleur de fond de la scène.
   * @return la couleur de fond de la scène.
   */
  inline Couleur getFond() const {return fond;}

  /**
   * Récupère l'intensité de la source ambiante de la scène.
   * @return l'intensité de la source ambiante de la scène.
   */
  inline Intensite getAmbiant() const {return ambiante.intensite;}

  /**
   * Récupère le nombre de sources de lumière présentes dans la scène.
   * @return le nombre de sources de lumière présentes dans la scène.
   */
  inline int nombreDeSources() const{
    return sources.size();
  }
  /**
   * Récupère la ieme source présente dans la scène. Les sources sont indicées
   * à partir de 0 jusqu'à (n-1), n'étant le nombre de sources présentes.
   * Aucun contrôle n'est effectué sur la validité du numéro de source demandé.
   * @param i le numéro de la source demandé. 
   * @return La iemme source si i est valide, une valeur indéfinie sinon.
   */
  inline Source getSource(int i) const{
    return *sources[i];
  }

  /**
   * Affichage du contenu de la scène sur le flot de sortie, dans un format
   * lisible par un utilisateur humain.
   * @param sortie le flot de sortie
   * @param s la scène à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream & sortie, Scene & s);
  

};
#endif
