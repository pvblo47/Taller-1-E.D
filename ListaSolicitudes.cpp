//
// Created by ulloc on 17-09-2024.
//

#include "ListaSolicitudes.h"
#include <sstream>
#include <bits/random.h> // Para generar Ids Aleatorios
#include <ctime>
#include <iomanip>

#include "Proyecto.h"

class Proyecto;
// Metodo para generar un ID aleatorio de 6 letras mayúsculas
std::string generarIDAleatorio() {
    const int longitud = 6;
    std::string id;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('A', 'Z');

    for (int i = 0; i < longitud; ++i) {
        id += static_cast<char>(dis(gen));
    }
    return id;
}

// Función para obtener la fecha actual en formato DD-MM-YYYY
std::string obtenerFechaActual() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");
    return oss.str();
}

// Metodo que crea un submenú para gestionar las soliciutedes
void gestionarSolicitudes(ListaSolicitudes& lista, std::vector<Proyecto>& proyectos) {


    while (!lista.estaVacia()) {

        // Mostrar opciones del submenú
        std::cout << "\nOpciones:" << std::endl;
        std::cout << "1. Aceptar solicitud" << std::endl;
        std::cout << "2. Rechazar solicitud" << std::endl;
        std::cout << "3. Siguiente solicitud" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                if(lista.getHead()) { // Condición para asegurar que exista una solicitud
                    const Solicitud solicitud = lista.getHead()->solicitud;
                    std::string id = generarIDAleatorio(); // Genera un id
                    std::string fechaActual = obtenerFechaActual(); // Obtiene la fecha actual

                    // Crea y agrega un nuevo proyecto al arreglo dinámico
                    Proyecto nuevoProyecto(solicitud.getNickname(),fechaActual,solicitud.getDescripcion(),solicitud.getDificultad(),id,false);
                    // Empujo el proyecto como ultimo elemento del arreglo dinámico
                    proyectos.push_back(nuevoProyecto);

                    std::cout << "Solicitud aceptada y convertida en proyecto." << std::endl;
                    //Elimina la solicitud
                    lista.eliminarPrimeraSolicitud();
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;

                }
                break;


            }
            case 2:{

            }
            case 3: {

            }
            case 4: {

            }
            default:
                std::cout << "Opción no valida. Intente denuevo" << std::endl;
                break;
        }

    }
    std::cout << "No hay más solicitudes que gestionar. Intente más tarde." << std::endl;






}

