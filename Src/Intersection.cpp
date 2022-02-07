#include "Intersection.hpp"

Intersection::Intersection(){
  objet = NULL;
  distance = 0;
}
  
Intersection::Intersection(const Point& p, Objet *o, const float& t)
  : Point(p)
{
  objet = o;
  distance = t;
}


Couleur Intersection::getCouleur(const Scene & sc, const Point& obs, 
				 int profondeur){

 // calcul des contributions diffuse et speculaire de l'éclairage direct
  // par toutes les sources présentes dans la scène, en tenant compte
  // des occultations potentielles.
  Couleur final = objet->calculerDirect(obs, sc, *this);

  // Ajout de la contribution ambiante, indépendante de toute source
  final += objet->calculerAmbiant(sc.getAmbiant());
  Couleur ambiant=objet->calculerAmbiant(sc.getAmbiant());

  // lancement éventuel du calcul récursif par lancer de rayons
  // ce calcul n'est déclenché que si la profondeur courante est > 0
  // et que le matériau de l'objet a une composante spéculaire
  if(profondeur >0 && objet->isSpecular()){
    
    // calcul du rayon réfléchi
    Rayon r = objet->getReflechi(obs, *this);

    // lancer du rayon réflechi
    Intersection inter;
    if(sc.intersecte(r, inter)){
      // le rayon réflechi intersecte un objet - on calcule sa contribution
      // lumineuse sur le point courant, par appel récursif de la méthode
      // getCouleur, en diminuant la profondeur restant à calculer d'une unité
      Couleur speculaire = inter.getCouleur(sc, *this, profondeur-1);
      final += speculaire;
    }
  }

  return final;
 }


Vecteur Intersection::getNormale() const{
    return objet->getNormale(*this);
}
