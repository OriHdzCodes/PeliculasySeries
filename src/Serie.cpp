#include "Serie.h"
#include <iostream>

// contructor
Serie::Serie(std::string id, std::string nombre, double duracion, std::string genero)
    : Video(id, nombre, duracion, genero) {}

// agregar episodio
void Serie::agregarEpisodio(Episodio episodio) {
    episodios.push_back(episodio);
}

// agregar duración
void Serie::agregarDuracion(double duracion) {
    this->duracion += duracion;
}

std::ostream& operator<<(std::ostream &os, const Serie& serie) {
    os << "ID: " << serie.id << "\t\t"
       << "Serie: " << serie.nombre
       << ", Genero: " << serie.genero
       << ", Duración: " << serie.duracion
       << " mins, Calificacion: " << serie.getCalificacionPromedio() << std::endl;

    return os;
}

// mostrar los episodios de la serie
void Serie::mostrarEpisodios() const {
    for (const auto& episodio : episodios) {
        episodio.mostrar();
    }
}

// sobrescritura del método mostrar()
void Serie::mostrar() const {
    std::cout << *this << std::endl;
    mostrarEpisodios();
}

// get episodios
std::vector<Episodio> Serie::getEpisodios() const {
    return episodios;
}