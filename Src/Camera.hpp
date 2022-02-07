#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include <iostream>
using namespace std;

#include "Point.hpp"
#include "Vecteur.hpp"
#include "Scene.hpp"
#include "Image.hpp"

/**
 * \class Camera
 * Classe représentant une caméra virtuelle simplifiée, générant des images
 * à l'aide de l'algorithme de lancer de rayons.
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

struct zone {
  int x, y; // coordonnées du coin supérieur gauche de la zone
  int largeur, hauteur; // dimensions de la zone
};

class Camera {
private:
  Point position;/**< Position de la caméra */
  Point cible;/**< Point visé par la caméra. Ce point sera au centre de l'image */
  float distance;/**< distance de l'origine de la caméra au plan image */

public:
  /**
   * Construit une caméra positionnée aux coordonnées (0, 0, 2).
   * Le point visé est l'origine du repère (0, 0, 0) et la distance au plan
   * image est fixée à 2.
   */
  Camera();

  /**
   * Détruit la caméra.
   */
  ~Camera();

  /**
   *  Calcul de l'image d'une scène telle que vue par la caméra. La méthode
   * de calcul est le lancer de rayons récursif.
   * @param sc la scène virtuelle à utiliser pour la génération de l'image
   * @param im l'image à générer par lancer de rayons
   * @param profondeur nombre de réflexions à prendre en compte dans le
   * processus récursif.
   */
  void genererImage(const Scene& sc, Image& im, int profondeur);


  /**
   * Affichage des paramètres d'une caméra sur un flot de sortie,
   * dans un format lisible par un utilisateur humain.
   * @param out le flot de sortie
   * @param c la caméra à afficher
   * @return le flot modifié
   */
  friend ostream& operator<<(ostream& out, const Camera& c);


};

#endif
