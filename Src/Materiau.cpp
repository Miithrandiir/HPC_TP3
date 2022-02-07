#include "Materiau.hpp"

Materiau::Materiau(){
  ka = 0.05;
  kd = 0.5;
  ks = 0.1;
  s = 10;
}

Materiau::Materiau(Couleur c, float ka, float kd, float ks, float s) : coul(c){
  this->ka = ka;
  this->kd = kd;
  this->ks = ks;
  this->s = s;
}

Materiau::~Materiau(){}

void Materiau::set(Couleur c, float ka, float kd, float ks, float s){
  this->coul = c;
  this->ka = ka;
  this->kd = kd;
  this->ks = ks;
  this->s = s;
}

ostream& operator<<(ostream & sortie, Materiau & m){
  sortie  << "[" << m.coul << "," << m.ka << "," << m.kd << "," << m.ks << "," << m.s << "]" << flush;
  return sortie;
}
