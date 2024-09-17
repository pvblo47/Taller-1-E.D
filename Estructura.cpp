//
// Created by ulloc on 17-09-2024.
//

#include "Estructura.h"


// Implementación del constructor
Estructura::Estructura(std::string nickname, std::string fecha, std::string descripcion, Dificultad dificultad)
    : nickname(std::move(nickname)), fecha(std::move(fecha)), descripcion(std::move(descripcion)), dificultad(dificultad) {

}
