//
// Created by ulloc on 17-09-2024.
//

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include <string>

#include "Dificultad.h"


class  Estructura {



public:    // Constructor
    Estructura(std::string nickname, std::string fecha,std::string descripcion, Dificultad dificultad);

    [[nodiscard]] std::string GetNickname() const {
        return nickname;
    }

    [[nodiscard]] std::string GetFecha() const {
        return fecha;
    }

    [[nodiscard]] std::string GetDescripcion() const {
        return descripcion;
    }

    [[nodiscard]] Dificultad GetDificultad() const {
        return dificultad;
    }

private:
    std::string nickname;
    std::string fecha;
    std::string descripcion;
    Dificultad dificultad;



};



#endif //ESTRUCTURA_H
