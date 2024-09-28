//
// Created by Gabriel Briones on 9/22/2024.
//

#include "BuildTheEarth.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Solicitud.h"

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
                lista.gestionarSolicitudes(proyectos);
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

    menu();

}

void leerArchivosolicitudes(){

    std::fstream file("solicitudes.csv");

    if (file.fail()) {
        std::cout << "Error opening file"<<"\n";
        exit(1);
    }

    std::string line;
    while (file.good()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string nickname;
            std::string dificultadStr;
            std::string puntosStr;
            std::string fecha;
            std::string ciudad;
            std::string descripcion;

            std::getline(ss, nickname,';');
            std::getline(ss, dificultadStr,';');
            std::getline(ss, puntosStr,';');
            std::getline(ss, fecha,';');
            std::getline(ss, ciudad,';');
            std::getline(ss, descripcion,';');

            int puntos = std::stoi(puntosStr);

            Solicitud *solicitud = new Solicitud(nickname, fecha, descripcion, dificultadStr, puntos, ciudad);
                
        }

    }

    std::fstream file1("proyectos.csv");

    if (file1.fail()) {
        std::cout << "Error opening file"<<"\n";
        exit(1);
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id;
        std::string nickname;
        std::string fecha;
        std::string descripcion;
        std::string dificultad;
        std::string finalizado;

        std::getline(ss, id,';');
        std::getline(ss, nickname,';');
        std::getline(ss, fecha,';');
        std::getline(ss, dificultad,';');
        std::getline(ss, finalizado,';');

        bool finalizadoBool;
        if(finalizado == "Si") {
            finalizadoBool = true;
        }
        else {
            finalizadoBool = false;
        }

        Proyecto *proyecto = new Proyecto(id, nickname, fecha, descripcion, dificultad, finalizadoBool);
    }
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


