//
// Created by ulloc on 22-09-2024.
//

#include "Proyecto.h"


Proyecto::Proyecto(std::string nickname, std::string fecha, std::string descripcion, std::string dificultad, std::string id, bool finalizado): Estructura(nickname, fecha, descripcion, dificultad),id(id),
      finalizado(finalizado) {
}
