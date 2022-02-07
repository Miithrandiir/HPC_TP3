#include "Couleur.hpp"

Couleur::Couleur(){
  rouge = vert = bleu = 0.8;
}

Couleur::Couleur(float r, float v, float b){
  rouge = r; vert = v; bleu = b;
}


Couleur::~Couleur(){}

void Couleur::set(float r, float v, float b){
  rouge = r; vert = v; bleu = b;
}

int  Couleur::getRougei(){
  return (rouge>1.0) ? 255 : (int)(rouge*255);
}

int  Couleur::getVerti(){
  return (vert>1.0) ? 255 : (int)(vert*255);
}

int  Couleur::getBleui(){
  return (bleu>1.0) ? 255 : (int)(bleu*255);
}

Couleur& Couleur::operator*(const float k){
  rouge *= k; vert *= k ; bleu *= k;
  return *this;
}

Couleur& Couleur::operator+=(const Couleur& c){
  rouge += c.rouge;
  vert += c.vert;
  bleu += c.bleu;
  return *this;
}

Couleur& Couleur::operator+=(const Intensite& I){
  rouge += I.getR();
  vert += I.getV();
  bleu += I.getB();
  return *this;
}
Couleur Couleur::operator*(const Intensite& I){
  return Couleur(rouge*I.getR(), vert*I.getV(), bleu*I.getB());
}


ostream& operator<<(ostream & sortie, Couleur & c){
  sortie << "(" << c.rouge << "," << c.vert << "," << c.bleu << ")" << flush;
  return sortie;
}


