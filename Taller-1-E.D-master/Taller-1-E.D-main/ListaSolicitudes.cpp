//
// Created by ulloc on 17-09-2024.
//

#include "ListaSolicitudes.h"
#include <sstream>
#include <bits/random.h> // Para generar Ids Aleatorios
#include <ctime>
#include <fstream>
#include <iomanip>

#include "ArregloDinamico.h"
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
int ListaSolicitudes::cantidadSolicitudes() const {
    int count = 0;
    Nodo* current = this->head; // Suponiendo que tienes un puntero a la cabeza de la lista
    while (current) {
        count++;
        current = current->next; // Avanza al siguiente nodo
    }
    return count;
}
void ListaSolicitudes::mostrarSolicitudActual() const {
    std::cout << "Número de solicitudes: " << this->cantidadSolicitudes() << std::endl;
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
    if (head == nullptr) {
        std::cout << "No hay solicitudes para eliminar." << std::endl;
        return;
    }

    Nodo* aux = head; // Guardar el nodo a eliminar
    head = head->next; // Mover la cabeza al siguiente nodo

    // Si la lista se vuelve vacía, actualiza `nodoActual` a nullptr
    if (head == nullptr) {
        nodoActual = nullptr;
        cola = nullptr;
    } else {
        nodoActual = head; // Actualizar a la nueva cabeza
    }

    delete aux; // Liberar la memoria del nodo eliminado
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
void ListaSolicitudes::gestionarSolicitudes(ArregloDinamico&  proyectos) {
    nodoActual = head; // Iniciar con el primer nodo
    // Usa "this" para acceder a los métodos de la instancia actual
    while (!this->estaVacia()) {

        mostrarSolicitudActual();

        // Mostrar opciones del submenú
        std::cout << "\nOpciones:" << std::endl;
        std::cout << "1. Aceptar solicitud" << std::endl;
        std::cout << "2. Rechazar solicitud" << std::endl;
        std::cout << "3. Siguiente solicitud" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: { // Aceptar solicitud
                if (nodoActual) { // Se asegura de que haya una solicitud
                    const Solicitud& solicitud =nodoActual->solicitud; // Usa "this"
                    std::string id = generarIDAleatorio(); // Genera un ID
                    std::string fechaActual = obtenerFechaActual(); // Obtiene la fecha actual

                    // Crea y agrega un nuevo proyecto al vector
                    Proyecto nuevoProyecto(solicitud.getNickname(), fechaActual, solicitud.getDescripcion(), solicitud.getDificultad(), id, false);
                    proyectos.agregar(nuevoProyecto);

                    std::cout << "Solicitud aceptada y convertida en proyecto." << std::endl;
                    this->eliminarPrimeraSolicitud(); // Elimina la solicitud
                    nodoActual = head; // Actualiza nodoActual al siguiente nodo
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

void ListaSolicitudes::leerArchivoSolicitudes() {
    std::fstream file("solicitudes.csv");

    if (file.fail()) {
        std::cout << "Error opening file" << "\n";
        return; // Cambia exit(1) a return
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // Ignora líneas vacías
        }

        std::stringstream ss(line);
        std::string nickname;
        std::string dificultadStr;
        std::string puntosStr;
        std::string fecha;
        std::string ciudad;
        std::string descripcion;

        // Leer los datos del archivo
        std::getline(ss, nickname, ';');
        std::getline(ss, dificultadStr, ';');
        std::getline(ss, puntosStr, ';');
        std::getline(ss, fecha, ';');
        std::getline(ss, ciudad, ';');
        std::getline(ss, descripcion, ';');

        // Validar que puntosStr no esté vacío antes de convertir
        if (puntosStr.empty()) {
            std::cout << "Puntos no válidos para la solicitud: " << line << std::endl;
            continue; // Saltar esta línea si puntosStr está vacío
        }

        // Intentar convertir puntosStr a int y manejar posibles errores
        int puntos;
        try {
            puntos = std::stoi(puntosStr);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error convirtiendo puntos: '" << puntosStr << "' en la línea: " << line << std::endl;
            continue; // Saltar esta línea si hay un error en la conversión
        } catch (const std::out_of_range& e) {
            std::cout << "Número fuera de rango en la línea: " << line << std::endl;
            continue; // Manejo adicional para el rango
        }

        Solicitud solicitud(nickname, fecha, descripcion, dificultadStr, puntos, ciudad);
        addSolicitud(solicitud);
    }
}
