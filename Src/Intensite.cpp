#include "Intensite.hpp"

Intensite::Intensite(){
  rouge = vert = bleu = 1.0;
}

Intensite::Intensite(float r, float v, float b){
  rouge = (r<0) ? 0.0 : r;
  vert = (v<0) ? 0.0 : v;
  bleu = (b<0) ? 0.0 : b;
}

void Intensite::set(float r, float v, float b){
  rouge = (r<0) ? 0.0 : r;
  vert = (v<0) ? 0.0 : v;
  bleu = (b<0) ? 0.0 : b;
}

Intensite::~Intensite(){
}


Intensite Intensite::operator*(float k){
  return Intensite(k*rouge, k*vert, k*bleu);
}


ostream& operator<<(ostream & sortie, Intensite & i){
  sortie << "(" << i.rouge << "," << i.vert << "," << i.bleu << ")" << flush;
  return sortie;
}
