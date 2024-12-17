#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>

// clase abstracta -> no se puede instanciar
class Video {
  // atributos protegidos -> accesibles por las clases hijas
protected:
  std::string id;
  std::string nombre;
  double duracion;
  std::string genero;
  std::vector<double> calificaciones;

  // métodos públicos -> accesibles por cualquier clase
public:
  // constructor
  Video(std::string id, std::string nombre, double duracion,
        std::string genero);

  // destructor
  virtual ~Video() {}

  // métodos de acceso -> getters
  std::string getId() const;
  std::string getNombre() const;
  double getDuracion() const;
  std::string getGenero() const;

  // calcular calificación promedio
  double getCalificacionPromedio() const;

  // agregar calificación
  void agregarCalificacion(double calificacion);

  // método virtual -> obliga a las clases hijas a implementarlo
  virtual void mostrar() const = 0;
};

#endif
