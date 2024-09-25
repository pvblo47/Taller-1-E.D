//
// Created by Gabriel Briones on 9/22/2024.
//

#include "BuildTheEarth.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Solicitud.h"

void menu() {
 std::cout<<"1. Add Earth"<<std::endl;

}

BuildTheEarth::BuildTheEarth() {

    menu();

}

void leerArchivo(){

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
            auto dificultad = static_cast<Dificultad>(std::stoi(dificultadStr));;

            Solicitud *solicitud1 = new Solicitud(nickname, fecha, descripcion, dificultad, puntos, ciudad);
                
        }

    }

    std::fstream file1("solicitudes.csv");

    if (file1.fail()) {
        std::cout << "Error opening file"<<"\n";
        exit(1);
    }

    std::string line1;
    while (file1.good()) {
        std::getline(file1, line1);
        std::string new_line;
        std::stringstream input_ss(line1);
        while (std::getline(input_ss, new_line, ';')) {

        }
    }

}



/*
Proyecto aceptarSolicitud() {
    return;
}

Proyecto rechazarSolicitud() {
    return;
}
Proyecto siguienteSolicitud() {
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
}*/
void volverEvaluacion(std::string nickname) {

}
void porcentajesDeDicultad() {

}
void usuariosMasAceptaciones() {

}
void masUtilizacionDeFiltro() {

}


