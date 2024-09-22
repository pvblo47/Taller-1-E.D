//
// Created by ulloc on 17-09-2024.
//

#ifndef SOLICITUDES_H
#define SOLICITUDES_H
#include "Estructura.h"


class Solicitud: public Estructura{


public:
    Solicitud(std::string nickname, std::string fecha,std::string descripcion, Dificultad dificultad, int puntos, std::string ciudad);

    [[nodiscard]] int getPuntos()  {
        return puntos;
    }

    [[nodiscard]] std::string getCiudad()  {
        return ciudad;
    }

private:
    int puntos;
    std::string ciudad;







};



#endif //SOLICITUDES_H
