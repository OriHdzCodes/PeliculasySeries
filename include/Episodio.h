#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"

// clase derivada de la clase base Video
class Episodio : public Video {
private:
    int temporada;
    int numero;

public:
    // constructor
    Episodio(std::string id, std::string nombre, double duracion, std::string genero, int numero, int temporada);

    // get
    int getTemporada() const;
    int getNumero() const;

    // sobrescritura de mostrar()
    void mostrar() const override;
};

#endif // EPISODIO_H
