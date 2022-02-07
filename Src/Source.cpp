#include "Source.hpp"

Source::Source(){
}

Source::Source(const Point& p, const Intensite& i) : position(p), intensite(i){
}

Source::~Source(){
}

ostream& operator<<(ostream & sortie, Source & s){
  sortie << "Source en " << s.position << " d'intensité " << s.intensite << flush;
  return sortie;
}
