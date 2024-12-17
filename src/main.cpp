#include "../libs/json.hpp"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json;

// cargar datos
void cargarDatos(const std::string &filename, std::vector<Video *> &videos,
                 std::vector<Serie *> &series) {
  std::ifstream file(filename);
  json j;
  file >> j;

  for (const auto &item : j) {
    std::string type = item["type"];
    if (type == "Pelicula") {
      Pelicula *pelicula = new Pelicula(item["ID"], item["nombre"],
                                        item["duracion"], item["genero"]);
      pelicula->agregarCalificacion(item["calificacion"]);
      videos.push_back(pelicula);
    } else if (type == "Serie") {
      Serie *serie = new Serie(item["ID"], item["nombre"], 0, item["genero"]);
      for (const auto &episodio : item["episodios"]) {
        Episodio ep(item["ID"], episodio["titulo"], episodio["duracion"],
                    item["genero"], episodio["numero"], episodio["temporada"]);
        ep.agregarCalificacion(episodio["calificacion"]);
        serie->agregarCalificacion(episodio["calificacion"]);
        serie->agregarEpisodio(ep);
        serie->agregarDuracion(episodio["duracion"]);
      }
      series.push_back(serie);
    }
  }
}

int main() {
  std::vector<Video *> peliculas;
  std::vector<Serie *> series;
  int opt = 1;

  // cargar datos del json en los vectores videos y series
  cargarDatos("../data.json", peliculas, series);

  while (opt != 0) {
    std::string id;

    // 0. Salir
    std::cout << "MENÚ" << std::endl;
    std::cout << "1. Mostrar los videos en general con una cierta calificación "
                 "o de un cierto género"
              << std::endl;
    std::cout << "2. Mostrar los episodios de una determinada serie con una "
                 "calificación determinada"
              << std::endl;
    std::cout << "3. Mostrar las películas con cierta calificación"
              << std::endl;
    std::cout << "4. Calificar un video" << std::endl;
    std::cout << "5. Mostrar todos los videos" << std::endl;
    std::cout << "6. Mostrar un determinado video con su ID" << std::endl;
    std::cout << "0. Salir" << std::endl;

    std::cout << "Opción: ";
    std::cin >> opt;

    switch (opt) {
    case 1:
      int opt1;
      // 1. mostrar los videos en general con una cierta calificación o de un
      // cierto género
      double calificacion;
      std::cout << "\n1. Calificación\n2. Género\n";
      std::cout << "Opción: ";
      std::cin >> opt1;
      if (opt1 == 1) {
        std::cout << "Calificación: ";
        std::cin >> calificacion;
        std::cout << std::endl;
      } else {
        std::string genero;
        std::cout << "Género: ";
        std::cin >> genero;
        std::cout << std::endl;
        std::cout << "PELÍCULAS:\n";
        for (const auto &video : peliculas) {
          if (video->getGenero() == genero) {
            video->mostrar();
            std::cout << std::endl;
          }
        }

        std::cout << "\n\nSERIES Y EPISODIOS:\n";
        for (const auto &serie : series) {
          if (serie->getGenero() == genero) {
            serie->mostrar();
            std::cout << std::endl;
          }
        }
        break;
      }

      std::cout << "PELÍCULAS:\n";
      for (const auto &pelicula : peliculas) {
        if (pelicula->getCalificacionPromedio() >= calificacion) {
          pelicula->mostrar();
          std::cout << std::endl;
        }
      }

      std::cout << "\n\nSERIES Y EPISODIOS:\n";
      for (const auto &serie : series) {
        if (serie->getCalificacionPromedio() >= calificacion) {
          serie->mostrar();
          std::cout << std::endl;
        }
      }
      break;
    case 2:
      // 2. mostrar los episodios de una determinada serie con una calificación
      // determinada
      std::cout << "ID de la serie: ";
      std::cin >> id;
      std::cout << "Calificación: ";
      std::cin >> calificacion;
      for (const auto &serie : series) {
        if (serie->getId() == id) {
          for (const auto &episodio : serie->getEpisodios()) {
            if (episodio.getCalificacionPromedio() >= calificacion) {
              episodio.mostrar();
            }
          }
        }
      }
      break;
    case 3:
      // 3. mostrar las películas con cierta calificación
      std::cout << "Calificación: ";
      std::cin >> calificacion;
      std::cout << "PELÍCULAS:\n";
      for (const auto &video : peliculas) {
        if (video->getCalificacionPromedio() >= calificacion) {
          video->mostrar();
          std::cout << std::endl;
        }
      }
      break;
    case 4:
      // 4. calificar un video
      std::cout << "ID del video: ";
      std::cin >> id;
      std::cout << "Calificación: ";
      std::cin >> calificacion;
      for (const auto &video : peliculas) {
        if (video->getId() == id) {
          video->agregarCalificacion(calificacion);
        }
      }
      for (const auto &serie : series) {
        if (serie->getId() == id) {
          serie->agregarCalificacion(calificacion);
        }
      }
      break;
    case 5:
      // 5. mostrar todos los videos
      std::cout << "PELÍCULAS:\n";
      for (const auto &pelicula : peliculas) {
        pelicula->mostrar();
        std::cout << std::endl;
      }

      // mostrar todas las series y sus episodios
      std::cout << "\n\nSERIES Y EPISODIOS:\n";
      for (const auto &serie : series) {
        serie->mostrar();
        serie->mostrarEpisodios();
        std::cout << std::endl;
      }
      break;
    case 6:
      std::cout << "ID: ";
      std::cin >> id;
      for (const auto &video : peliculas) {
        if (video->getId() == id) {
          video->mostrar();
        }
      }
      for (const auto &serie : series) {
        if (serie->getId() == id) {
          serie->mostrar();
        }
      }
      break;
    default:
      break;
    }
    std::cout << std::endl;
  }

  // limpiar la memoria
  for (auto &pelicula : peliculas) {
    delete pelicula;
  }
  for (auto &serie : series) {
    delete serie;
  }

  return 0;
}
