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

    [[nodiscard]] std::string nickname1() const {
        return nickname;
    }

    [[nodiscard]] std::string fecha1() const {
        return fecha;
    }

    [[nodiscard]] std::string descripcion1() const {
        return descripcion;
    }

    [[nodiscard]] Dificultad dificultad1() const {
        return dificultad;
    }

private:
    std::string nickname;
    std::string fecha;
    std::string descripcion;
    Dificultad dificultad;



};



#endif //ESTRUCTURA_H
