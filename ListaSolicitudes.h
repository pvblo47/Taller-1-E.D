//
// Created by ulloc on 17-09-2024.
//

#ifndef NODE_H
#define NODE_H
#include <iostream>

#include "Solicitud.h"

// Nodo de la lista enlazada
struct Nodo {

    Solicitud solicitud ; // Cada nodo contiene un objeto de tipo Solicitud
    Nodo * next; // Puntero al siguiente nodo de la lista
    // Constructor del nodo que inicializa con una solicitud
    Nodo(const Solicitud& solicitud) : solicitud(solicitud), next(nullptr) {}

};
// Clase que maneja la lista enlazada de solicitudes
class ListaSolicitudes {


    public:
    // Constructor que inicializa la lista vacía
    ListaSolicitudes() : head(nullptr), cola(nullptr) {}

    // Destructor para liberar la memoria de todos los nodos (por si acaso)
    ~ListaSolicitudes() {
        Nodo * aux = head; // Comenzar desde el primer nodo
        while (aux) {  // Recorrer todos los nodos

            Nodo* next = aux->next; // Guardar el puntero al siguiente nodo
            delete aux;  // Liberar la memoria del nodo actual
            aux = next; // Moverse al siguiente nodo
        }
    }

    // Metodo para insertar una solicitud al final de la lista
    void addSolicitud(const Solicitud& nuevaSolicitud) {

        Nodo* nuevoNodo = new Nodo(nuevaSolicitud); // Nuevo nodo con la solicitud
        if (!head) { // Si la lista está vacía
            head = nuevoNodo; // El nuevo nodo es la cabeza
            cola = nuevoNodo; // también la cola
        } else { // Si ya hay nodos en la lista
            cola->next = nuevoNodo;// Enlazar el último nodo con el nuevo nodo
            cola = nuevoNodo;  // Actualizar la cola al nuevo nodo
        }
    }

    // Metodo para mostrar la solicitud
    void mostrarPrimeraSolicitud() const {
        if (!head) { // Verificar si la lista está vacía
            std::cout << "No hay solicitudes en la lista." << std::endl;
            return;
        }

    }


    private:
    Nodo* head;
    Nodo* cola;




};



#endif //NODE_H
