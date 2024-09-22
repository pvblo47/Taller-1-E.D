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

    [[nodiscard]] std::string getNickname()  {
        return nickname;
    }

    [[nodiscard]] std::string getFecha()  {
        return fecha;
    }

    [[nodiscard]] std::string getDescripcion()  {
        return descripcion;
    }

    [[nodiscard]] Dificultad getDificultad()  {
        return dificultad;
    }

private:
    std::string nickname;
    std::string fecha;
    std::string descripcion;
    Dificultad dificultad;



};



#endif //ESTRUCTURA_H
