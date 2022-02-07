#include <thread>
#include "Camera.hpp"
#include "Rayon.hpp"
#include "mutex"

std::mutex mutex_img;
std::mutex mutex_cout;

Camera::Camera() {
    position = Point(0.0, 0.0, 2.0);;
    cible = Point(0.0, 0.0, 0.0);
    distance = 2.0;
}

Camera::~Camera() {}

void Camera::genererImage(const Scene &sc, Image &im, int profondeur) {

    // Calcul des dimensions d'un pixel par rapport
    // à la résolution de l'image - Les pixels doivent être carrés
    // pour éviter les déformations de l'image.
    // On fixe :
    // - les dimensions en largeur de l'écran seront comprises dans [-1, 1]
    // - les dimensions en hauteur de l'écran soront comprises dans [-H/L, H/L]
    float cotePixel = 2.0 / im.getLargeur();

    // Pour chaque pixel
    for (int i = 0; i < im.getLargeur(); i++) {
        for (int j = 0; j < im.getHauteur(); j++) {

            // calcul des coordonnées du centre du pixel
            float milieuX = -1 + (i + 0.5f) * cotePixel;
            float milieuY = (float) im.getHauteur() / (float) im.getLargeur()
                            - (j + 0.5f) * cotePixel;

            Point centre(milieuX, milieuY, 0);

            // Création du rayon
            Vecteur dir(position, centre);
            dir.normaliser();
            Rayon ray(position, dir);

            // Lancer du rayon primaire
            Intersection inter;
            if (sc.intersecte(ray, inter)) {
                im.setPixel(i, j, inter.getCouleur(sc, position, profondeur));
            } else
                im.setPixel(i, j, sc.getFond());

        }// for j

    }// for i
}


ostream &operator<<(ostream &out, const Camera &c) {

    out << " position = " << c.position << " - cible = " << c.cible;
    out << " - distance = " << c.distance << flush;
    return out;
}

void Camera::genererImageParallele(const Scene &sc, Image &im, int profondeur, int thread) {

    std::thread threads[thread];

    int hauteurBande = im.getHauteur() / thread;
    for (int w = 0; w < thread; ++w) {
        Zone zone;
        zone.x = 0;
        zone.y = hauteurBande * w;
        zone.largeur = im.getLargeur();

        zone.hauteur = hauteurBande;

        threads[w] = std::thread(calculerZone, std::cref(sc), std::ref(im), profondeur, zone,
                                 std::cref(position));

    }

    for (std::thread &item: threads) {
        item.join();
    }

}

void Camera::calculerZone(const Scene &sc, Image &im, int profondeur, const Zone &area, const Point &position) {
    auto start = std::chrono::steady_clock::now();
    float cotePixel = 2.0f / area.largeur;

     mutex_cout.lock();
     std::cout << "zone à calculer : " << " x: " << area.x << " y: " << area.y << std::endl;
     mutex_cout.unlock();

    for (int i = area.x; i < area.x + area.largeur; i++) {
        for (int j = area.y; j < area.y + area.hauteur; j++) {

            // calcul des coordonnées du centre du pixel
            float milieuX = -1 + (i + 0.5f) * cotePixel;
            float milieuY = (float) im.getHauteur() / (float) im.getLargeur()
                            - (j + 0.5f) * cotePixel;

            Point centre(milieuX, milieuY, 0);

            // Création du rayon
            Vecteur dir(position, centre);
            dir.normaliser();
            Rayon ray(position, dir);

            // Lancer du rayon primaire
            Intersection inter;

            if (sc.intersecte(ray, inter)) {
                im.setPixel(i, j, inter.getCouleur(sc, position, profondeur));
            } else {
                im.setPixel(i, j, sc.getFond());
            }

        }// for j

    }// for i
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    mutex_cout.lock();
    std::cout << "[Thread - " << std::this_thread::get_id() << "] end in " << elapsed_seconds.count() << "s"
              << std::endl;
    mutex_cout.unlock();
}
