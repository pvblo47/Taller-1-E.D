//
// Created by Gabriel Briones on 9/22/2024.
//

#include "BuildTheEarth.h"

#include <fstream>
#include <iostream>


#include "ArregloDinamico.h"
#include "ListaSolicitudes.h"
ListaSolicitudes listaSolicitudes;
ArregloDinamico proyectos;

void menu() {
    int opcion;
    do {
        std::cout << "\nMenú Principal:\n";
        std::cout << "1. Revisar Solicitudes\n";
        std::cout << "2. Búsqueda de Proyectos\n";
        std::cout << "3. Volver a Evaluar el Proyecto\n";
        std::cout << "4. Estadísticas\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                listaSolicitudes.gestionarSolicitudes(proyectos);

            break;
            case 2:
                // Lógica para búsqueda de proyectos
                    break;
            case 3:
                // Lógica para volver a evaluar el proyecto
                    break;
            case 4:
                // Lógica para estadísticas
                    break;
            case 5:
                std::cout << "Saliendo del programa...\n";
            break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);

}



BuildTheEarth::BuildTheEarth() {

   // proyectos.leerArchivoProyectos();
    listaSolicitudes.leerArchivoSolicitudes();

    menu();






}





/*
Proyecto aceptarSolicitud() {
    return;
}

Proyecto rechazarSolicitud() {
    return;
}
Proyecto siguienteSolicitud(){
    return;
}
Proyecto filtroFinalizado() {
    return;
}
Proyecto filtroAñoSeleccion() {
    return;
}
Proyecto filtroMesSeleccion() {
    return;
}
Proyecto filtroPorNick() {
    return;
}
Proyecto filtroPorDificultad() {
    return;
}
*/
void volverEvaluacion(std::string nickname) {

}
void porcentajesDeDicultad() {

}
void usuariosMasAceptaciones() {

}
void masUtilizacionDeFiltro() {

}


