#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

// clase derivada de la clase base Video (herencia)
class Pelicula : public Video {
public:
    // constructor
    Pelicula(std::string id, std::string nombre, double duracion, std::string genero);

    // sobrescritura método mostrar()
    void mostrar() const override;
};

#endif // PELICULA_H
