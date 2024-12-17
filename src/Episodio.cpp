#include "Episodio.h"
#include <iostream>

// constructor
Episodio::Episodio(std::string id, std::string nombre, double duracion, std::string genero, int numero, int temporada)
    : Video(id, nombre, duracion, genero), numero(numero), temporada(temporada) {}

// get
int Episodio::getTemporada() const {
    return temporada;
}

int Episodio::getNumero() const {
    return numero;
}

// sobrescritura de mostrar()
void Episodio::mostrar() const {
    std::cout << "Episodio " << numero << ": " << nombre
              << ", Temporada: " << temporada
              << ", Duracion: " << duracion
              << " mins, Genero: " << genero
              << ", Calificacion: " << getCalificacionPromedio() << std::endl;
}
