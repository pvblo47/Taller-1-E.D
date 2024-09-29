//
// Created by Gabriel Briones on 9/27/2024.
//

#include "ArregloDinamico.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Proyecto.h"
#include "Solicitud.h"

int size;
int amount;
Proyecto* arr;

ArregloDinamico::ArregloDinamico() {
    this->size = 1;
    this->amount = 0;
    this->arr = (Proyecto*) malloc(this->size * sizeof(int));
}

ArregloDinamico::~ArregloDinamico() {
    delete[] this->arr; // Cambia free() a delete[]
}

void ArregloDinamico::agregar(Proyecto data) {
    if (this->amount == this->size) {
        this->expandir();
    }
    this->arr[this->amount] = data;
    this->amount++;
}

int ArregloDinamico::obtenerPosicion(const Proyecto& data) {
    for (int i = 0; i < this->amount; i++) {
        if(this->arr[i] == data) {
            return i;
        }
    }
    return -1;
}

void ArregloDinamico::insertar(Proyecto data, int index) {
    if(index<0||index>this->amount) {
        return;
    }
    if (index == this->amount) {
        this->agregar(data);
    }
    if (this->amount == this->size) {
        this->expandir();
    }

    for (int i =this->amount; i > index; i--) {
        this->arr[i] = this->arr[i-1];
    }
    this->arr[index] = data;
    this->amount++;

}

void ArregloDinamico::expandir() {
    this->size *= 2;

}

void ArregloDinamico::leerArchivoProyectos() {
    std::fstream file1("proyectos.csv");

    if (file1.fail()) {
        std::cout << "Error al abrir el archivo 'proyectos.csv'." << "\n";
        return;
    }

    std::string line;

    while (std::getline(file1, line)) {
        if (line.empty()) {
            continue; // Ignora líneas vacías
        }

        std::cout << "Leyendo línea: " << line << std::endl; // Línea de depuración
        std::stringstream ss(line);
        std::string id, nickname, fecha, descripcion, dificultad, finalizado;

        std::getline(ss, id, ';');
        std::getline(ss, nickname, ';');
        std::getline(ss, fecha, ';');
        std::getline(ss, descripcion, ';');
        std::getline(ss, dificultad, ';');
        std::getline(ss, finalizado, ';');

        // Verifica que todos los campos estén llenos
        if (id.empty() || nickname.empty() || fecha.empty() || descripcion.empty() || dificultad.empty() || finalizado.empty()) {
            std::cout << "Línea incompleta encontrada, saltando: " << line << std::endl;
            continue;
        }

        bool finalizadoBool = (finalizado == "Si");

        // Crear nueva instancia de Proyecto
        try {
            Proyecto proyecto(id, nickname, fecha, descripcion, dificultad, finalizadoBool);
            this->agregar(proyecto);
        } catch (const std::exception& e) {
            std::cout << "Error al crear proyecto: " << e.what() << std::endl;
        }
    }
}