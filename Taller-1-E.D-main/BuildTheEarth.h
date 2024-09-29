//
// Created by Gabriel Briones on 9/22/2024.
//

#ifndef BUILDTHEEARTH_H
#define BUILDTHEEARTH_H
#include <string>

#include "ArregloDinamico.h"
#include "ListaSolicitudes.h"
#include "Proyecto.h"


class BuildTheEarth{



public:
    BuildTheEarth();


    Proyecto aceptarSolicitud();
    Proyecto rechazarSolicitud();
    Proyecto siguienteSolicitud();
    Proyecto filtroFinalizado();
    Proyecto filtroAñoSeleccion();
    Proyecto filtroMesSeleccion();
    Proyecto filtroPorNick();
    Proyecto filtroPorDificultad();
    void volverEvaluacion(std::string nickname);
    void porcentajesDeDicultad();
    void usuariosMasAceptaciones();
    void masUtilizacionDeFiltro();

private:

};



#endif //BUILDTHEEARTH_H
