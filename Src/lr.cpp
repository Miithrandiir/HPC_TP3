#include <iostream>
#include <chrono>
using namespace std;

//#include "Sphere.hpp"
//#include "Plan.hpp"
#include "Scene.hpp"
#include "Vecteur.hpp"
#include "Image.hpp"
#include "Camera.hpp"

// profondeur de la récursion pour le lancer de rayons
#define PROF 2
// nombre de threads à utiliser
#define NBT 1


int main(int argc, char *argv[]){

  // vérification de la syntaxe de la commande

  if(argc !=2){
    cerr << "ERREUR - Syntaxe = ";
    cerr << argv[0] << " <fichier descriptif d'une scène>";
    cerr << endl;
    return -1;
  }


  // création et chargement de la scène
  Scene sc;
  if(!sc.charger(argv[1])){
    cerr << "ERREUR au chargement du fichier " << argv[1] << endl;
    return -1;
  };

  // création de l'image et de la caméra
  Image im(512,512);
  Camera cam;

  // génération de l'image à partir de la caméra

  cam.genererImage(sc, im, PROF);


  // sauvegarde de l'image
  im.sauver("image.ppm");


  return 1;
}
