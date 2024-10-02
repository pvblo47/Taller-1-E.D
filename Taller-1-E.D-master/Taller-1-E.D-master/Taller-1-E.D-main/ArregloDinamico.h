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
    int getAmount();
    void agregar(Proyecto data);
    void eliminar(int index);
    int obtenerPosicion(const Proyecto &data);

    void volverAEvaluarProyecto();

    void AplicarFiltro(bool filtroFinalizado, bool aplicarFiltros, bool filtroAnio, bool filtroMes, bool filtroNickname, bool filtroDificultad, std::string anio, std::string mes, std::string nickname, std::string dificultad);

    void Porcentajes();

    void mostrarInformacion();

    void recorrerArregloDinamico(Proyecto *arr);

    void insertar(Proyecto data,int index);
    void expandir();
    void shrink();
    void leerArchivoProyectos();



private:
    int size;
    int amount;
    Proyecto *arr;


};



#endif //ARREGLODINAMICO_H
