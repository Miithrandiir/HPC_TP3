#include "Point.hpp"


ostream& operator<<(ostream& out, const Point& p){
  out << "(" << p.X << "," << p.Y << ",";
  out << p.Z << ")";
  return out;
}

