#include "Triangle.hpp"
#include "Plan.hpp"

// choix du code de la méthode de calcul d'intersection
#define MOLLER
//#define BASIC

Triangle::Triangle() : Objet(){
  s[0].set(-1, 0, -1);
  s[1].set(1, 0, -1);
  s[2].set(0, 0, 1);
  n.set(0, 0, 1);
}

Triangle::Triangle(const Point p[3], Materiau m) : Objet(m) {
  for(int i=0; i<3; i++)
    s[i] = p[i];
  // calcul de la normale à partir du produit vectoriel AB^AC
  // cette normale doit ensuite être normalisée...
  n = Vecteur::cross(Vecteur(s[0], s[1]), Vecteur(s[0], s[2]));
  n.normaliser();
}

Triangle::~Triangle(){}

#ifdef MOLLER
bool Triangle::intersecte(const Rayon& r, Intersection& inter){

  const float TRI_EPSILON = 0.0001;

  float a,f,u,v;
  Vecteur edge1(s[0], s[1]);
  Vecteur edge2(s[0], s[2]);
  Vecteur h = Vecteur::cross(r.direction, edge2);
  a = edge1*h;
  if (a > -TRI_EPSILON && a < TRI_EPSILON)
    return false;    // Le rayon est parallèle au triangle.

  f = 1.0/a;
  Vecteur ss(s[0], r.origine); 
  u = f * (ss*h);
  if (u < 0.0 || u > 1.0)
    return false;
  Vecteur q = Vecteur::cross(ss,edge1);
  v = f * (q * r.direction);
  if (v < 0.0 || u + v > 1.0)
    return false;

  // On calcule t pour savoir où le point d'intersection se situe sur la ligne.
  float t = f * (edge2 * q);
  if (t > TRI_EPSILON){ // Intersection avec le rayon
    inter = Intersection(Point (r.origine.X + t*r.direction.dx,
				r.origine.Y + t*r.direction.dy,
				r.origine.Z + t*r.direction.dz),
			 this, t);;
    return true;
  }
  else // On a bien une intersection de droite, mais pas de rayon.
    return false;
}


bool Triangle::coupe(const Rayon& r){
  const float TRI_EPSILON = 0.0001;

  float a,f,u,v;
  Vecteur edge1(s[0], s[1]);
  Vecteur edge2(s[0], s[2]);
  Vecteur h = Vecteur::cross(r.direction, edge2);
  a = edge1*h;
  if (a > -TRI_EPSILON && a < TRI_EPSILON)
    return false;    // Le rayon est parallèle au triangle.

  f = 1.0/a;
  Vecteur ss(s[0], r.origine); 
  u = f * (ss*h);
  if (u < 0.0 || u > 1.0)
    return false;
  Vecteur q = Vecteur::cross(ss,edge1);
  v = f * (q * r.direction);
  if (v < 0.0 || u + v > 1.0)
    return false;

  // On calcule t pour savoir où le point d'intersection se situe sur la ligne.
  float t = f * (edge2 * q);
  if (t > TRI_EPSILON) // Intersection avec le rayon
    return true;

    return false;
}

#endif

#ifdef BASIC
bool Triangle::intersecte(const Rayon& r, Intersection& inter){
   const float TRI_EPSILON = 0.000001;
 
  // calcul du dernier coefficient du plan ax+by+cz=-d
  float d = -(n.dx*s[0].X+n.dy*s[0].Y+n.dz*s[0].Z);

  // calcul de l'intersection avec le plan support
  // Attention : ne pas passer par la classe Plan
  // car l'intersection appartiendrait au plan, pas au triangle ...
  
  Point o = r.origine;
  Vecteur dir = r.direction;
  
  // calcul du dénominateur

  float denominateur = n.dx*dir.dx + n.dy*dir.dy + n.dz*dir.dz;
  if(denominateur == 0) return false;

  // calcul du numerateur
  float numerateur = n.dx*o.X + n.dy*o.Y + n.dz*o.Z + d;

  float t= -numerateur/denominateur;
  if(t<TRI_EPSILON) return false;

  // calcul du point d'intersection
  inter = Intersection(Point(o.X+t*dir.dx,
			     o.Y+t*dir.dy,
			     o.Z+t*dir.dz),
		       this, t);

  // le point d'intersection est-il à l'intérieur du triangle ?
  
  if(Vecteur::cross(Vecteur(s[0],s[1]),Vecteur(s[0], inter))*n<TRI_EPSILON) return false;
  if(Vecteur::cross(Vecteur(s[1],s[2]),Vecteur(s[1], inter))*n<TRI_EPSILON) return false;
  if(Vecteur::cross(Vecteur(s[2],s[0]),Vecteur(s[2], inter))*n<TRI_EPSILON) return false;

  return true;
  
}

bool Triangle::coupe(const Rayon& r){
  Intersection tmp;
  return intersecte(r, tmp);
}
#endif

Vecteur Triangle::getNormale(const Point &p){
  return n;
}

ostream& operator<<(ostream & sortie, Triangle & t){
  sortie << "triangle : ";
  for(int i=0; i<3; i++)
    sortie << t.s[i] << " - ";
  sortie << endl;

  return sortie;
    
}

void Triangle::affiche(ostream& out){
  out << "triangle : ";
  for(int i=0; i<3; i++)
    out << s[i] << " - ";
  out << endl;
}

