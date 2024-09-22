//
// Created by ulloc on 22-09-2024.
//

#ifndef PROYECTO_H
#define PROYECTO_H
#include "Estructura.h"


class Proyecto: public Estructura{

public:
    Proyecto(std::string nickname, std::string fecha,std::string descripcion, Dificultad dificultad, std::string id, bool finalizado );

    [[nodiscard]] std::string getID() const {
        return id;
    }

    [[nodiscard]] bool getFinalizado() const {
        return finalizado;
    }

private:
    std::string id;
    bool finalizado;

};





#endif //PROYECTO_H
