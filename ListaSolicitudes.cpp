//
// Created by ulloc on 17-09-2024.
//

#include "ListaSolicitudes.h"
#include <sstream>
#include <bits/random.h> // Para generar Ids Aleatorios
#include <ctime>
#include <iomanip>

#include "Proyecto.h"

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

void ListaSolicitudes::addSolicitud(const Solicitud& nuevaSolicitud) {
    Nodo* nuevoNodo = new Nodo(nuevaSolicitud); // Crear un nuevo nodo con la solicitud
    if (!head) { // Si la lista está vacía
        head = nuevoNodo; // El nuevo nodo es la cabeza
        cola = nuevoNodo; // también es la cola
    } else { // Si ya hay nodos en la lista
        cola->next = nuevoNodo; // Enlazar el último nodo con el nuevo nodo
        cola = nuevoNodo;  // Actualizar la cola al nuevo nodo
    }
}

void ListaSolicitudes::mostrarSolicitudActual() const {
    if (!nodoActual) {  // Verifica si hay una solicitud actual
        std::cout << "No hay solicitudes en la lista o ya no hay más solicitudes." << std::endl;
        return;
    }

    const Solicitud& solicitud = nodoActual->solicitud;

    std::cout << "Nickname: " << solicitud.getNickname() << std::endl;
    std::cout << "Dificultad: " << solicitud.getDificultad() << std::endl;
    std::cout << "Puntos: " << solicitud.getPuntos() << std::endl;
    std::cout << "Descripción: " << solicitud.getDescripcion() << std::endl;
    // cálculo de días
}

void ListaSolicitudes::eliminarPrimeraSolicitud() {
    if (!head) {
        return; // No hay nada que eliminar
    }
    Nodo* nodoEliminar = head;
    head = head->next; // Ahora la cabeza es el siguiente
    delete nodoEliminar; //Se elimina el nodo seleccionado al inicio

    // Si se eliminó el único nodo, actualizar la cola a nullptr
    if (!head){
        cola = nullptr;
    }
}

bool ListaSolicitudes::estaVacia() const {
    return head == nullptr; //Si esta vacía retorna True
}

void ListaSolicitudes::reiniciarLista() {
    nodoActual = head;  // Reinicia el puntero al principio de la lista
}

void ListaSolicitudes::mostrarSiguienteSolicitud() {
    if (!nodoActual) {  // Si nodoActual es nulo, comenzamos desde el principio
        nodoActual = head;
    } else if (nodoActual->next) {  // Si hay un siguiente nodo
        nodoActual = nodoActual->next;  // Avanzar al siguiente nodo
    } else {
        std::cout << "Ya no hay más solicitudes." << std::endl;
        return;
    }

    mostrarSolicitudActual();  // Mostrar la solicitud actual
}
// Metodo que crea un submenú para gestionar las soliciutedes
void ListaSolicitudes::gestionarSolicitudes(std::vector<Proyecto>& proyectos) {
    // Usa "this" para acceder a los métodos de la instancia actual
    while (!this->estaVacia()) {
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
                if (this->getHead()) { // Se asegura de que haya una solicitud
                    const Solicitud& solicitud = this->getHead()->solicitud; // Usa "this"
                    std::string id = generarIDAleatorio(); // Genera un ID
                    std::string fechaActual = obtenerFechaActual(); // Obtiene la fecha actual

                    // Crea y agrega un nuevo proyecto al vector
                    Proyecto nuevoProyecto(solicitud.getNickname(), fechaActual, solicitud.getDescripcion(), solicitud.getDificultad(), id, false);
                    proyectos.push_back(nuevoProyecto); // Agrega el proyecto al vector

                    std::cout << "Solicitud aceptada y convertida en proyecto." << std::endl;
                    this->eliminarPrimeraSolicitud(); // Elimina la solicitud
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;
                }
                break;
            }
            case 2: {
                if (this->getHead()) { // Asegúrate de que haya una solicitud
                    this->eliminarPrimeraSolicitud(); // Elimina la primera solicitud
                    std::cout << "Solicitud rechazada y eliminada de la lista." << std::endl;

                    // Mostrar la siguiente solicitud, si existe
                    if (!this->estaVacia()) {
                        this->mostrarSolicitudActual(); // Mostrar la siguiente solicitud
                    } else {
                        std::cout << "No hay solicitudes en la lista." << std::endl;
                    }
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;
                }
                break;
            }
            case 3: {
                if (!this->estaVacia()) {
                    this->mostrarSiguienteSolicitud();
                } else {
                    std::cout << "No hay solicitudes en la lista." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Saliendo al menú principal..." << std::endl;
                return; // Sale del bucle y regresa al menú principal
            }
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    }
    std::cout << "No hay más solicitudes que gestionar. Intente más tarde." << std::endl;
}

