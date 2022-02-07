#ifndef __POINT_HPP
#define __POINT_HPP

#include <iostream>
using namespace std;

#define EPSILON 0.001
/** 
 * \class Point
 * Classe de base représentant un point en trois dimensions. 
 * Afin de faciliter leur utilisation, les attributs dune point sont publics.
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

class Point  {

public :
  double X;/**< Coordonnée spatiale en <CODE>X</CODE> à partir de l'origine du repère global.*/
  double Y;/**< Coordonnée spatiale en <CODE>Y</CODE> à partir de l'origine du repère global.*/
  double Z;/**< Coordonnée spatiale en <CODE>Z</CODE> à partir de l'origine du repère global.*/

public:
  /**
   * Constructeur par défaut. 
   * Ce constructeur place le point en coordonnées <CODE>(0, 0, 0)</CODE> 
   * par défaut.
   */
  Point(){X=Y=Z=0.0;}


  /**
   * Constructeur initialisant un point avec la valeur des paramètres fournis.
   * @param Xp	coordonnée en <CODE>X</CODE> du point à créer.
   * @param Yp	coordonnée en <CODE>Y</CODE> du point à créer.
   * @param Zp	coordonnée en <CODE>Z</CODE> du point à créer.
   */
  Point(const double& Xp, const double& Yp, const double& Zp){
    X=Xp; Y=Yp; Z=Zp;
  }

  /**
   * Destruit le point
   */
  virtual ~Point(){};

  /**
   * Modification des coordonnées du point
   * @param nX	nouvelle valeur pour l'attribut <CODE>X</CODE>.
   * @param nY	nouvelle valeur pour l'attribut <CODE>Y</CODE>.
   * @param nZ	nouvelle valeur pour l'attribut <CODE>Z</CODE>.
   */
  void set(const double& nX, const double &nY, const double &nZ){
    X = nX; Y = nY; Z = nZ;
  }


  /**
   * Affichage de la description d'un point sur le flot de sortie, 
   * dans un format lisible par un utilisateur humain.
   * @param out le flot de sortie
   * @param p le rayon à afficher
   * @return le flot modifié
   */  friend ostream& operator<<(ostream& out, const Point& p);


};//Point


#endif 
