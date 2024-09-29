//
// Created by ulloc on 17-09-2024.
//
#define LISTASOLICITUDES_H
#include "ArregloDinamico.h"
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <sstream>
#include <random>


#include "Proyecto.h"
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
    [[nodiscard]] Nodo * getHead() const {
        return head;
    }



    // Constructor que inicializa la lista vacía
    ListaSolicitudes() : head(nullptr), cola(nullptr),nodoActual(nullptr){}

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
    void addSolicitud(const Solicitud& nuevaSolicitud);

    int cantidadSolicitudes() const;

    // Metodo para mostrar la solicitud actual
    void mostrarSolicitudActual() const;

    // Eliminar la primera solicitud en la lista
    void eliminarPrimeraSolicitud();

    // Verificar si la lista está vacía
    bool estaVacia() const;

    // Metodo para reiniciar la lista al inicio
    void reiniciarLista();

    // Metodo para mostrar la siguiente solicitud en la lista
    void mostrarSiguienteSolicitud();

    // Metodo para gestionar las solicitudes
    void gestionarSolicitudes(ArregloDinamico& proyectos);

    void leerArchivoSolicitudes();

    // Metodo para leer el Archivo de Solicitudes
    void LeerArchivoSolicitudes();

    void RevertirUnProyecto(ListaSolicitudes& listaSolicitudes);




    private:
    Nodo* head;        // Puntero a la cabeza de la lista
    Nodo* cola;        // Puntero a la cola de la lista
    Nodo* nodoActual;  // Puntero para rastrear la solicitud actual





};



#endif //NODE_H
