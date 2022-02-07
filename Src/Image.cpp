#include <iostream>
#include <fstream>
using namespace std;

#include "Image.hpp"

Image::Image(){
  pixel=nullptr;
  largeur=hauteur=0;
}

Image::Image(int l, int h){
  largeur=l; hauteur=h;
  pixel = new Couleur[l*h];
}


Image::~Image(){
  if(pixel!=nullptr) delete [] pixel;
}


void Image::setPixel(int x, int y, Couleur c){
  if(x>=0 && x<largeur && y>=0 && y<hauteur)
    pixel[x+y*largeur] = c;
}

Couleur Image::getPixel(int x, int y){
  if(x>=0 && x<largeur && y>=0 && y<hauteur)
    return pixel[x+y*largeur];
  return Couleur(0,0,0);
}




bool Image::sauver(string name){
  
  cout << "saving in " << name << endl;
  
  ofstream out;// flot de sortie

  out.open(name, ios::out);
  if(!out.is_open()){
    cout << "erreur d'ouverture de " << name << endl;
    return false;
  }

  // Sortie de l'entête PPM
  out << "P3" << endl;
  out << "# mon commentaire" << endl;
  out << largeur << " " << hauteur << endl;
  out << "255" << endl;

  // sortie des pixels de l'image, ligne par ligne
  for(int y=0; y<hauteur; y++)
    for(int x=0; x<largeur; x++){
      out << pixel[x+y*largeur].getRougei() << endl;
      out << pixel[x+y*largeur].getVerti() << endl;
      out << pixel[x+y*largeur].getBleui() << endl;
    }

  out.close();
  return true;
}


