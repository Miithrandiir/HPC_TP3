#include "Rayon.hpp"

Rayon::Rayon(){
}

Rayon::Rayon(const Point& o, const Vecteur& d) : origine(o), direction(d){
}

Rayon::~Rayon(){
}

ostream& operator<<(ostream& out, const Rayon& r){
  out << r.origine << " -> " << r.direction << flush;
  return out;
}
