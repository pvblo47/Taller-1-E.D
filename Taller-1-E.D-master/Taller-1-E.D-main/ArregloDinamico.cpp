//
// Created by Gabriel Briones on 9/27/2024.
//

#include "ArregloDinamico.h"

#include <codecvt>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Proyecto.h"
#include "Solicitud.h"

int size;
int amount;
Proyecto* arr;

ArregloDinamico::ArregloDinamico() {
    this->size = 1;
    this->amount = 0;
    this->arr = new Proyecto[this->size];
}

ArregloDinamico::~ArregloDinamico() {
    delete[] this->arr;
}


void ArregloDinamico::agregar(Proyecto data) {
    if (this->amount == this->size) {
        this->expandir();
    }
    this->arr[this->amount] = data;
    this->amount++;
}



void ArregloDinamico::eliminar(int index) {
    if (index < 0 || index >= amount) {
        std::cout << "Índice fuera de rango." << std::endl;
        return;
    }

    for (int i = index; i < amount - 1; i++) {
        arr[i] = arr[i + 1];
    }
    amount--;
}

int ArregloDinamico::obtenerPosicion(const Proyecto& data) {
    for (int i = 0; i < this->amount; i++) {
        if(this->arr[i] == data) {
            return i;
        }
    }
    return -1;
}

std::string cambioDeDificultad(Proyecto proyecto) {
    if (proyecto.getDificultad() == "PRINCIPIANTE") {
        return "O";
    }
    if (proyecto.getDificultad() == "FACIL") {
        return "OO";
    }
    if (proyecto.getDificultad() == "INTERMEDIO") {
        return "OOO";
    }
    if (proyecto.getDificultad() == "DIFICIL") {
        return "OOOO";
    }
    if (proyecto.getDificultad() == "MUY_DIFICIL") {
        return "OOOOO";
    }


}

void ArregloDinamico::filtroPorFinalización() {
    std::cout<< "------------------Proyectos Encontrados-----------------" << std::endl;
    for (int i = 0; i < this->amount; i++) {
        Proyecto proyecto = arr[i];
        if(proyecto.getFinalizado()==true) {
            std::cout<< "-----------------------------------------------" << std::endl;
            std::cout<< "Nickname: " << proyecto.getNickname() << std::endl;
            std::cout<< "Proyecto: " << (cambioDeDificultad(proyecto)) << std::endl;
            //std::cout<< "Proyecto: " << proyecto.getSemanas() << std::endl;//
            std::cout<< "Proyecto: " << proyecto.getDescripcion() << std::endl;
            std::cout<< "-----------------------------------------------" << std::endl;
        }

    }

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
    Proyecto* nuevoArr = new Proyecto[this->size * 2];


    for (int i = 0; i < this->amount; i++) {
        nuevoArr[i] = this->arr[i];
    }

    delete[] this->arr;
    this->arr = nuevoArr;
    this->size *= 2;
}

int ArregloDinamico::getAmount() {
    return this->amount;
}


void ArregloDinamico::leerArchivoProyectos() {
    std::ifstream file1("proyectos.csv");

    if (file1.fail()) {
        std::cout << "Error al abrir el archivo 'proyectos.csv'." << "\n";
        return;
    }

    std::string line;

    while (std::getline(file1, line)) {
        if (line.empty()) {
            continue; // Ignora líneas vacías
        }

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