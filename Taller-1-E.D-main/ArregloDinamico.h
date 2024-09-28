//
// Created by Gabriel Briones on 9/27/2024.
//

#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H
#include "Proyecto.h"

class ArregloDinamico {


public:
    ArregloDinamico();
    ~ArregloDinamico();
    void agregar(Proyecto data);
    int obtenerPosicion(const Proyecto &data);
    void insertar(Proyecto data,int index);
    void expandir();
    void shrink();


private:
    int size;
    int amount;
    Proyecto *arr;

};



#endif //ARREGLODINAMICO_H
