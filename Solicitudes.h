//
// Created by ulloc on 17-09-2024.
//

#ifndef SOLICITUDES_H
#define SOLICITUDES_H
#include "Estructura.h"


class Solicitudes: public Estructura{


public:
    Solicitudes(std::string nickname, std::string fecha,std::string descripcion, Dificultad dificultad, int puntos, std::string ciudad);

    [[nodiscard]] int puntos1() const {
        return puntos;
    }

    [[nodiscard]] std::string ciudad1() const {
        return ciudad;
    }

private:
    int puntos;
    std::string ciudad;







};



#endif //SOLICITUDES_H
