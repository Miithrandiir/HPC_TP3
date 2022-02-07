#ifndef _IMAGE_HPP
#define _IMAGE_HPP
#include <string>
using namespace std;
#include "Couleur.hpp"

/**
 * \class Image
 * Classe permettant de représenter une image sous forme d'un tableau de pixels.
 * Chaque pixel sera représenté par une couleur.
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
class Image{
private:
  Couleur *pixel;/**< Tableau des pixels de l'image */
  int largeur; /**< Largeur de l'image (nombre de colonnes de pixels)*/
  int  hauteur; /**< Hauteur de l'image (nombre de lignes de l'image) */
public:
  /**
   * Crée une image vide, de dimensions nulles
   */
  Image();
  
  /**
   * Crée une image de l colonnes par h lignes
   * @param l largeur de l'image (nombre de colonnes)
   * @param h hauteur de l'image (nombre de lignes)
   */
  Image(int l, int h);

  /**
   * Détruit l'image
   */
  ~Image();

  /**
   * Récupére la largeur de l'image
   */
  inline int getLargeur() const { return largeur; }
  /**
   * Récupére la hauteur de l'image
   */
  inline int getHauteur() const { return hauteur; }

  /**
   * Modifie la couleur d'un pixel. Si les coordonnées du pixel sont invalides
   * la méthode ne modifie pas l'image.
   * @param x abscisse du pixel
   * @param y ordonnée du pixel
   * @param c la valeur de couleur à affecter au pixel
   */
  void setPixel(int x, int y, Couleur c);

  /**
   * Récupère la couleur d'un pixel. Si les coordonnées du pixel sont invalides
   * la méthode retourne une couleur noire.
   * @param x abscisse du pixel
   * @param y ordonnée du pixel
   * @return la valeur de couleur du pixel (x, y)
   */
  Couleur getPixel(int x, int y);

  /**
   * Sauvegarde l'image dans un fichier au format PPM.
   * @param name le nom du fichier de sauvegarde.
   */
  bool sauver(string name);


};
#endif
