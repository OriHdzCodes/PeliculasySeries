#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include <vector>
#include <iostream>

// clase derivada de clase base Video
class Serie : public Video {
private:
    // composición
    std::vector<Episodio> episodios;

public:
    // constructor
    Serie(std::string id, std::string nombre, double duracion, std::string genero);

    // agregar episodio
    void agregarEpisodio(Episodio episodio);

    // agregar duración
    void agregarDuracion(double duracion);

    // mostrar
    friend std::ostream& operator<<(std::ostream& os, const Serie& serie);

    // mostrar los episodios de la serie
    void mostrarEpisodios() const;

    // sobrescritura del método mostrar()
    void mostrar() const override;

    // get episodios
    std::vector<Episodio> getEpisodios() const;
};

#endif // SERIE_H
