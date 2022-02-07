#include <cmath>
#include "Objet.hpp"

Objet::Objet(){
}

Objet::Objet(Materiau m): mat(m) {
}

Objet::~Objet(){
}


Couleur Objet::getCouleur(){
  return mat.getCouleur();
}

bool Objet::isSpecular(){
  return (mat.getKs() != 0.0);
}

Rayon Objet::getReflechi(const Point& obs, const Intersection& p){
  // calcul du rayon symétrique à la direction obs-P par rapport à la normale
  // à l'objet au point p
    Vecteur normale = p.getNormale();
    Vecteur incident(p, obs);
    incident.normaliser();
    float ps = normale*incident;
    Vecteur reflechi = normale*2.0*ps - incident;
    reflechi.normaliser();
    return Rayon(p, reflechi);
}

Couleur Objet::calculerAmbiant(const Intensite& ambiant){
  float ka = mat.getKambiant();
  Couleur tmp = ka*mat.getCouleur();
  Couleur cam(tmp.getR()*ambiant.getR(), tmp.getV()*ambiant.getV(), tmp.getB()*ambiant.getB());
  return cam;
}

Couleur  Objet::calculerDirect(const Point &obs, const Scene& sc, Intersection& p){

  Couleur direct(0,0,0);


  // pour chaque source ...
  for(int i=0; i<sc.nombreDeSources(); i++){
    Source curSrc = sc.getSource(i);

    // vérifier la visibilité de la source courante
    Vecteur dir(p, curSrc.position);
    Rayon ro(p, dir);
    if(sc.coupe(ro)) continue;

    // calcul de la contribution diffuse;
    Vecteur normale = p.getNormale();
    Vecteur incident(p, curSrc.position);
    incident.normaliser();

    float ps = normale*incident;

     if(ps>0.0)
       direct += mat.getKd()* mat.getCouleur() * ps * curSrc.intensite;

    // calcul de la contribution spéculaire
    Vecteur visee(p, obs);
    visee.normaliser();
    Vecteur reflechi = normale*2.0*ps - incident;
    reflechi.normaliser();
    ps = visee * reflechi;
    if(ps>0){
      ps = (float)pow(ps, mat.getBrillance());
      direct += (ps*mat.getKs())*curSrc.intensite;
    }

  }
  return direct;
}

ostream& operator<<(ostream & sortie, Objet & o){
  sortie  << " en " << o.mat << flush;
  return sortie;
}


void Objet::affiche(ostream& out){
  out << " de matériau " << mat << flush;
}
