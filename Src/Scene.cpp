#include <iostream>
#include <fstream>
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Plan.hpp"
#include "Triangle.hpp"


Scene::Scene(){
  ambiante.intensite.set(0.2, 0.2, 0.2);
}

Scene::~Scene(){
  // suppression de tous les objets
  for(int i=0; i<objets.size(); i++)
    delete objets[i];
  objets.clear();
  //suppression de toutes les sources
  for(int i=0; i<sources.size(); i++)
    delete sources[i];
  sources.clear();
}

bool Scene::charger(string filename){

  Materiau curMat;

  ifstream in;
  in.open(filename.c_str(), ios::in);
  if(!in.is_open()) return false;

  string s;
  in >> s;

  while(!in.eof()){

    if(s[0]=='#'){// traiter un commentaire
      getline(in, s);
    }
    if(s=="sphere"){// charger une sphere
      float x, y, z, r;
      in >> x >> y >> z >> r;
      ajouter(new Sphere(x, y, z, r, curMat));
    }

    if(s=="plan"){// charger un plan
      float a, b, c, d;
      in >> a >> b >> c >> d;
      ajouter(new Plan(a, b, c, d, curMat));
    }

    if(s=="tri"){// charger un triangle
      Point s[3];
      for(int i=0; i<3; i++)
	in >> s[i].X >> s[i].Y >> s[i].Z;
      ajouter(new Triangle(s, curMat));
    }

    if(s=="materiau"){// charger un matériau
      float r, v, b, ka, kd, ks, s;
      in >> r >> v >> b >> ka >> kd >> ks >> s;
      curMat.set(Couleur(r, v, b), ka, kd, ks, s);
    }

    if(s=="source"){// charger une source
      float x, y, z, r, v, b;
      in >> x >> y >> z >> r >> v >> b;
      sources.push_back(new Source(Point(x,y,z), Intensite(r, v, b)));
    }

    if(s=="fond"){// charger la couleur de fond
      float r, v, b;
      in >> r >> v >> b;
      fond.set(r, v, b);
    }

    if(s=="ambiant"){// charger la source ambiante
      float r, v, b;
      in >> r >> v >> b;
      ambiante.intensite.set(r, v, b);
    }

    in >> s;
  }// while

  in.close();
  return true;
}

void Scene::ajouter(Objet *o){
  objets.push_back(o);
}

bool Scene::intersecte(const Rayon& r, Intersection& inter) const {
  float tmax = 1.0e50;// init d'une valeur maximal du paramètre t
  Intersection interCour;
  bool interTrouvee=false;

  for(int i=0; i<objets.size(); i++){
    if(objets[i]->intersecte(r, interCour)){
      // l'intersection est-elle plus proche que l'ntersection courante ?
      if(interCour.getDistance() < tmax){
       	tmax = interCour.getDistance();
      	inter = interCour;
      }
      interTrouvee = true;
    }
  }
  return interTrouvee;
}


bool Scene::coupe(const Rayon &r) const{
  for(int i=0; i<objets.size(); i++){
    // on s'arrête au premier objet qui coupe
    if(objets[i]->coupe(r)) return true;
  }
  return false;
}


ostream& operator<<(ostream & sortie, Scene & s){
  sortie << "contenu de la scène : " << endl;
  for(int i=0; i<s.objets.size(); i++){
    s.objets[i]->affiche(sortie);
    sortie << endl;
  }
  for(int i=0; i<s.sources.size(); i++)
    sortie << *s.sources[i] << endl;

  sortie << "la source ambiante vaut " << s.ambiante << endl;
  sortie << "La couleur de fond est " << s.fond << endl;
  return sortie;
}



