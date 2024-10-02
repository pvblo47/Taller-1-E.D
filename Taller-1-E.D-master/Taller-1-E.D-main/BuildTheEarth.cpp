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



void menuDeFiltro() {
    int opcion;
    do {
        std::cout<<"-------------- Menu de filtro --------------"<<std::endl;
        std::cout<<"[1]Filtro proyecto finalizado"<<std::endl;
        std::cout<<"[2]Filtro proyecto por año ingresado"<<std::endl;
        std::cout<<"[3]Filtro proyecto por mes ingresado"<<std::endl;
        std::cout<<"[4]Filtro proyecto por nickname ingresado"<<std::endl;
        std::cout<<"[5]Filtro proyecto por dificultad"<<std::endl;
        std::cout<<"[6]Volver al menu principal"<<std::endl;
        std::cin >> opcion;
        switch (opcion) {

            case 1:
                proyectos.filtroPorFinalización();

                break;
        }
    } while (opcion != 6);

}

void menu(){
    int opcion;
    do {
        std::cout << "\nMenu Principal:\n";
        std::cout << "1. Revisar Solicitudes\n";
        std::cout << "2. Busqueda de Proyectos\n";
        std::cout << "3. Volver a Evaluar el Proyecto\n";
        std::cout << "4. Estadisticas\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                listaSolicitudes.gestionarSolicitudes(proyectos);

            break;
            case 2:
                // Lógica para búsqueda de proyectos
                menuDeFiltro();
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
    proyectos.leerArchivoProyectos();
    listaSolicitudes.leerArchivoSolicitudes();

    menu();
}



/*
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


