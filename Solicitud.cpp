//
// Created by ulloc on 17-09-2024.
//

#include "Solicitud.h"

// Implementación del constructor
Solicitud::Solicitud(std::string nickname, std::string fecha, std::string descripcion, Dificultad dificultad, int puntos, std::string ciudad)
    : Estructura(std::move(nickname), std::move(fecha), std::move(descripcion), dificultad),
      puntos(puntos), ciudad(std::move(ciudad)) {

}



