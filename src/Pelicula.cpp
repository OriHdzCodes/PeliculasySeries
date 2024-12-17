#include "Pelicula.h"
#include <iostream>

// constructor
Pelicula::Pelicula(std::string id, std::string nombre, double duracion, std::string genero)
    : Video(id, nombre, duracion, genero) {}

// sobrescritura método mostrar()
void Pelicula::mostrar() const {
    std::cout << "ID: " << id << "\t\t"
              << "Pelicula: " << nombre
              << ", Duracion: " << duracion
              << " mins, Genero: " << genero
              << ", Calificacion: " << getCalificacionPromedio() << std::endl;
}
