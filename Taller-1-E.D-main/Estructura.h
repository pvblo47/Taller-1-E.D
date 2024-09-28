//
// Created by ulloc on 17-09-2024.
//

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include <string>




class  Estructura {



public:    // Constructor
    Estructura(std::string nickname, std::string fecha,std::string descripcion, std::string dificultad);

    [[nodiscard]] std::string getNickname() const {
        return nickname;
    }

    [[nodiscard]] std::string getFecha()  const{
        return fecha;
    }

    [[nodiscard]] std::string getDescripcion() const {
        return descripcion;
    }

    [[nodiscard]] std::string getDificultad() const {
        return dificultad;
    }

    bool operator==(const Estructura & estructura) const = default;

private:
    std::string nickname;
    std::string fecha;
    std::string descripcion;
    std::string dificultad;



};



#endif //ESTRUCTURA_H
