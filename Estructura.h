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

    [[nodiscard]] std::string getNickname() const {
        return nickname;
    }

    [[nodiscard]] std::string getFecha()  const{
        return fecha;
    }

    [[nodiscard]] std::string getDescripcion() const {
        return descripcion;
    }

    [[nodiscard]] Dificultad getDificultad() const {
        return dificultad;
    }

private:
    std::string nickname;
    std::string fecha;
    std::string descripcion;
    Dificultad dificultad;



};



#endif //ESTRUCTURA_H
