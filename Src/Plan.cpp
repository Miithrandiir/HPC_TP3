#include "Plan.hpp"

#define PL_EPSILON  0.0001

Plan::Plan() : Objet(){
  // plan horizontal d'équation y=0
  a=0.0; b=1.0; c=0.0; d=0.0;
}


Plan::Plan(float a, float b, float c, float d, Materiau m) : Objet(m) {
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;

}

Plan::~Plan(){}

ostream& operator<<(ostream & sortie, Plan & p){
  // affichage de l'équation du plan
  sortie << "Plan : d'équation " << p.a<<" x + "<< p.b <<" y + "<< p.c <<" z + "<< p.d << " = 0 ";
  // affichage du matériau du plan
  Objet *po = &p;
  sortie << *po << flush;
  return sortie;
}

bool Plan::intersecte(const Rayon& r, Intersection& inter)
{
  Point o = r.origine;
  Vecteur d = r.direction;

  // calcul du dénominateur
  float denominateur = a*d.dx + b*d.dy + c*d.dz;
  if(denominateur == 0) return false;

  // calcul du numerateur
  float numerateur = a*o.X + b*o.Y + c*o.Z + this->d;

  float t= -numerateur/denominateur;
  if(t<PL_EPSILON) return false;

  // calcul du point d'intersection
  inter = Intersection(Point(o.X+t*d.dx,
			     o.Y+t*d.dy,
			     o.Z+t*d.dz),
		       this, t);
  return true;
}


bool Plan::coupe(const Rayon& r){
  return false;
  Point o = r.origine;
  Vecteur d = r.direction;

  // calcul du dénominateur
  float denominateur = a*d.dx + b*d.dy + c*d.dz;
  if(denominateur == 0) return false;

  // calcul du numerateur
  float numerateur = a*o.X + b*o.Y + c*o.Z + this->d;

  float t= -numerateur/denominateur;
  if(t<PL_EPSILON || t>1.0) return false;

  return true;
}


Vecteur Plan::getNormale(const Point &p){
  // construit le vecteur normal au plan, qui est donné par
  // N = (a,b,c)
  Vecteur n(a, b, c);
  n.normaliser();
  return n;
}

void Plan::affiche(ostream& out){
  out << "Plan : d'équation " <<  a <<" x + "<< b <<" y + "<< c <<" z + "<< d << " = 0 ";
  Objet::affiche(out);
}

