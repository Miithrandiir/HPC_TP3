#include "Sphere.hpp"
#include <cmath>

#define SP_EPSILON 0.0001

Sphere::Sphere() : Objet(){
  rayon = 1.0;
}


Sphere::Sphere(float xc, float yc, float zc, float r, Materiau m) : Objet(m), centre(xc, yc, zc) {
  rayon = r;
}

Sphere::~Sphere(){}

bool Sphere::intersecte(const Rayon& r, Intersection& inter){
  float t, t1, t2;
  float delta, a, b, c;
  Vecteur d = r.direction;
  Point o = r.origine;

  a = d.dx*d.dx + d.dy*d.dy + d.dz*d.dz;
  b = 2*( d.dx*(o.X-centre.X) +
  	  d.dy*(o.Y-centre.Y) + 
  	  d.dz*(o.Z-centre.Z) );
  c = o.X*o.X + o.Y*o.Y + o.Z*o.Z +
    centre.X*centre.X + centre.Y*centre.Y +
    centre.Z*centre.Z - 
    2*(o.X*centre.X + o.Y*centre.Y + 
       o.Z*centre.Z) -
    rayon*rayon;

  delta = b*b -4*a*c;

  if(delta<0) return false; // aucune intersection

  if(delta==0.0){ // une seule intersection
    t = -b / (2*a);
    if(t<=SP_EPSILON) return false;
  }else{ // deux intersections
    t1 = (-b + (float)sqrt(delta))/(2*a);
    t2 = (-b - (float)sqrt(delta))/(2*a);
    // classement des deux racines
    if(t1>t2) {t=t1; t1=t2; t2=t;}
    if(t2<=SP_EPSILON) return false; // deux racines <=0
    if((-SP_EPSILON<=t1) && (t1<=SP_EPSILON)) return false; // t1 = 0.0
    if(t1>SP_EPSILON) t=t1; else t=t2;
  }

  // calcul du point d'intersection
  inter = Intersection(Point(o.X+t*d.dx,
  			     o.Y+t*d.dy,
  			     o.Z+t*d.dz),
  		       this, t);
  return true;
}

bool Sphere::coupe(const Rayon& r){
  float t, t1, t2;
  float delta, a, b, c;
  Vecteur d = r.direction;
  Point o = r.origine;

  a = d.dx*d.dx + d.dy*d.dy + d.dz*d.dz;
  b = 2*( d.dx*(o.X-centre.X) +
  	  d.dy*(o.Y-centre.Y) + 
  	  d.dz*(o.Z-centre.Z) );
  c = o.X*o.X + o.Y*o.Y + o.Z*o.Z +
    centre.X*centre.X + centre.Y*centre.Y +
    centre.Z*centre.Z - 
    2*(o.X*centre.X + o.Y*centre.Y + 
       o.Z*centre.Z) -
    rayon*rayon;

  delta = b*b -4*a*c;

  if(delta<0) return false; // aucune intersection

  if(delta==0.0){ // une seule intersection
    t = -b / (2*a);
    if(t<=SP_EPSILON || t>=1.0) return false;
  }else{
    t1 = (-b + (float)sqrt(delta))/(2*a);
    t2 = (-b - (float)sqrt(delta))/(2*a);
    // classement des deux racines
    if(t1>t2) {t=t1; t1=t2; t2=t;}
    if(t2<=SP_EPSILON) return false; // deux racines <=0
    if((-SP_EPSILON<=t1) && (t1<=SP_EPSILON)) return false; // t1 = 0.0
    if(t1>SP_EPSILON) t=t1; else t=t2;
  }

  if(t>1.0) return false; // intersections derrière la source

  return true;
}

ostream& operator<<(ostream & sortie, Sphere & s){
  // affichage de l'équation de la sphère
  sortie << "Sphere : de rayon " << s.rayon << ", de centre ";
  sortie << s.centre;
  // affichage du matériau de la sphère
  Objet *po = &s;
  sortie << *po << flush;
  return sortie;
}

Vecteur Sphere::getNormale(const Point &p){
  // la normale à la sphère au point P est égale
  // au vecteur CP, avec C le centre de la sphère
  Vecteur n(p.X-centre.X,p.Y-centre.Y, p.Z-centre.Z);
  n.normaliser();
  return n;
}


void Sphere::affiche(ostream& out) {
  out << "Sphere : de rayon " << rayon << ", de centre ";
  out << centre;
  Objet::affiche(out);
}

