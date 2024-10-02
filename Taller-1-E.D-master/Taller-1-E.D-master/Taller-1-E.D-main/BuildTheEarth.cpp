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
    bool aplicarFiltros = false; // controla si se van a aplicar los filtros seleccionados
    bool filtroFinalizado = false;
    bool filtroAnio = false;
    bool filtroMes = false;
    bool filtroNickname = false;
    bool filtroDificultad = false;
    std::string anio;
    std::string mes;
    std::string dificultad;
    std::string nickname;

    do {
        std::cout<<"-------------- Menu de filtro --------------"<<std::endl;
        std::cout<<"[1] Filtro proyecto finalizado"<<std::endl;
        std::cout<<"[2] Filtro proyecto por año ingresado"<<std::endl;
        std::cout<<"[3] Filtro proyecto por mes ingresado"<<std::endl;
        std::cout<<"[4] Filtro proyecto por nickname ingresado"<<std::endl;
        std::cout<<"[5] Filtro proyecto por dificultad"<<std::endl;
        std::cout<<"[6] Aplicar filtros y mostrar proyectos"<<std::endl;
        std::cout<<"[7] Volver al menú principal"<<std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                filtroFinalizado = true;
                std::cout << "Filtro por proyectos finalizados activado." << std::endl;
                break;
            case 2:
                filtroAnio = true;
                std::cout << "Ingrese el año del proyecto que desea buscar: ";
                std::cin >> anio;
                break;
            case 3:
                filtroMes = true;
                std::cout << "Ingrese el mes (como número, 1-12): ";
                std::cin >> mes;
                break;
            case 4:
                filtroNickname = true;
                std::cout << "Ingrese el nickname del proyecto: ";
                std::cin >> nickname;
                break;
            case 5:
                filtroDificultad = true;
                std::cout << "Ingrese la dificultad del proyecto (1-5): ";
                std::cin >> dificultad;
                break;
            case 6:
                // se aplican los filtros seleccionados
                aplicarFiltros = true;
                break;
        }

        if (aplicarFiltros) {
            proyectos.AplicarFiltro(filtroFinalizado, aplicarFiltros, filtroAnio, filtroMes,filtroNickname, filtroDificultad,anio, mes, nickname, dificultad);


            // Reiniciar los filtros para la siguiente vez
            aplicarFiltros = false;
            filtroFinalizado = filtroAnio = filtroMes = filtroNickname = filtroDificultad = false;
        }

    } while (opcion != 7);
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
                // Lógica para la gestión de solicitudes
                listaSolicitudes.gestionarSolicitudes(proyectos);

            break;
            case 2:
                // Lógica para búsqueda de proyectos
                menuDeFiltro();
            break;
            case 3:
                // Lógica para volver a evaluar el proyecto
                    proyectos.volverAEvaluarProyecto();
                    break;
            case 4:
                // Lógica para estadísticas
                    proyectos.Porcentajes();
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


void ArregloDinamico::volverAEvaluarProyecto() {
    std::cout << "Ingrese el ID del proyecto que desea volver a evaluar: ";
    std::string id;
    std::cin >> id;

    // Verificar si el ID es válido
    bool proyectoEncontrado = false;



    for (int i = 0; i < this->amount; i++) {
        Proyecto proyecto = arr[i];
        if (proyecto.getID() == id) {
            proyectoEncontrado = true;

            Solicitud nuevaSolicitud(proyecto.getNickname(), listaSolicitudes.obtenerFechaActual(), proyecto.getDescripcion(), proyecto.getDificultad(), 1000, "");
            listaSolicitudes.addSolicitud(nuevaSolicitud);
            this->eliminar(i);


            break;
        }
    }

    if (!proyectoEncontrado) {
        std::cout << "El ID del proyecto no es válido." << std::endl;
        return; // Regresar al menú si el ID no es válido
    }



    std::cout << "El proyecto ha sido revertido y agregado a la lista de solicitudes." << std::endl;
}