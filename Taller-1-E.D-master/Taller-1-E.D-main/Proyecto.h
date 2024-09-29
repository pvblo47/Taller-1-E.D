//
// Created by ulloc on 22-09-2024.
//

#ifndef PROYECTO_H
#define PROYECTO_H
#include "Estructura.h"


class Proyecto: public Estructura{

public:
    // Constructor por defecto
    Proyecto()
        : Estructura("default_nickname", "default_fecha", "default_descripcion", "default_dificultad"),
          id("default_id"), finalizado(false) {}

    Proyecto(std::string id, std::string nickname, std::string fecha, std::string descripcion, std::string dificultad, bool finalizado)
        : Estructura(nickname, fecha, descripcion, dificultad), id(id), finalizado(finalizado) {
    }


    [[nodiscard]] std::string getID() const {
        return id;
    }

    [[nodiscard]] bool getFinalizado() const {
        return finalizado;
    }
    // Operador de igualdad
    friend bool operator==(const Proyecto & lhs, const Proyecto & rhs) = default;

private:
    std::string id;
    bool finalizado;

};





#endif //PROYECTO_H
