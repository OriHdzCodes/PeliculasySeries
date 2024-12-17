#include "Video.h"
#include <numeric>
#include <stdexcept>

// constructor
Video::Video(std::string id, std::string nombre, double duracion, std::string genero): id(id), nombre(nombre), duracion(duracion), genero(genero) {}

// getters
std::string Video::getId() const {
    return id;
}

std::string Video::getNombre() const {
    return nombre;
}

double Video::getDuracion() const {
    return duracion;
}

std::string Video::getGenero() const {
    return genero;
}

// calcular calificación promedio
double Video::getCalificacionPromedio() const {
    if (calificaciones.empty()) return 0;
    return std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / calificaciones.size();
}

// agregar calificación
void Video::agregarCalificacion(double calificacion) {
    if (calificacion < 1 || calificacion > 5) {
        throw std::out_of_range("La calificación debe estar entre 1 y 5");
    }
    calificaciones.push_back(calificacion);
}
