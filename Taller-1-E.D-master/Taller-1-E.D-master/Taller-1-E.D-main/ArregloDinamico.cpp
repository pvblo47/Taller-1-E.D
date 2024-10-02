//
// Created by Gabriel Briones on 9/27/2024.
//

#include "ArregloDinamico.h"

#include <codecvt>
#include <fstream>
#include <iostream>
#include <sstream>

#include "ListaSolicitudes.h"
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



void ArregloDinamico::AplicarFiltro(bool filtroFinalizado, bool aplicarFiltros, bool filtroAnio, bool filtroMes, bool filtroNickname, bool filtroDificultad, std::string anio, std::string mes, std::string nickname, std::string dificultad) {
    std::cout << "Aplicando los filtros seleccionados..." << std::endl;

    for (int i = 0; i < this->amount; i++) {
        Proyecto proyecto = arr[i];

        // Aplica todos los filtros que estén activados
        bool mostrar = true;

        if (filtroFinalizado && !proyecto.getFinalizado()) {
            mostrar = false;
        }
        if (filtroAnio && proyecto.getFecha().substr(6,4) != anio) {
            mostrar = false;
        }
        if (filtroMes && proyecto.getFecha().substr(3,2) != mes) {
            mostrar = false;
        }
        if (filtroNickname && proyecto.getNickname() != nickname) {
            mostrar = false;
        }
        if (filtroDificultad && proyecto.getDificultad() != dificultad) {
            mostrar = false;
        }

        if (mostrar) {
            std::cout<< "-----------------------------------------------" << std::endl;
            std::cout<< "Nickname: " << proyecto.getNickname() << std::endl;
            std::cout<< "Proyecto: " << (cambioDeDificultad(proyecto)) << std::endl;
            //std::cout<< "Proyecto: " << proyecto.getSemanas() << std::endl;//
            std::cout<< "Proyecto: " << proyecto.getDescripcion() << std::endl;
            std::cout<< "-----------------------------------------------" << std::endl;
        }
    }


}


void ArregloDinamico::Porcentajes() {
    int contadorPrincipiante = 0;
    int contadorFacil = 0;
    int contadorIntermedio = 0;
    int contadorDificil = 0;
    int contadorMuyDificil = 0;
    int totalProyectos = this->amount;

    // Contar proyectos por dificultad
    for (int i = 0; i < totalProyectos; i++) {
        Proyecto proyecto = arr[i];
        std::string dificultad = proyecto.getDificultad(); // Obtiene la dificultad del proyecto

        // Incrementa el contador correspondiente según la dificultad
        if (dificultad == "PRINCIPIANTE") {
            contadorPrincipiante++;
        } else if (dificultad == "FACIL") {
            contadorFacil++;
        } else if (dificultad == "INTERMEDIO") {
            contadorIntermedio++;
        } else if (dificultad == "DIFICIL") {
            contadorDificil++;
        } else if (dificultad == "MUY_DIFICIL") {
            contadorMuyDificil++;
        }
    }

    // Mostrar porcentajes
    std::cout << "Estadísticas de Proyectos por Dificultad:" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    if (totalProyectos == 0) {
        std::cout << "No hay proyectos disponibles para calcular estadísticas." << std::endl;

    }

    // Calculo y mostrar porcentajes
    std::cout << "Dificultad: PRINCIPIANTE | Cantidad: " << contadorPrincipiante
              << " | Porcentaje: " << (static_cast<double>(contadorPrincipiante) / totalProyectos) * 100 << "%" << std::endl;
    std::cout << "Dificultad: FACIL       | Cantidad: " << contadorFacil
              << " | Porcentaje: " << (static_cast<double>(contadorFacil) / totalProyectos) * 100 << "%" << std::endl;
    std::cout << "Dificultad: INTERMEDIO  | Cantidad: " << contadorIntermedio
              << " | Porcentaje: " << (static_cast<double>(contadorIntermedio) / totalProyectos) * 100 << "%" << std::endl;
    std::cout << "Dificultad: DIFICIL     | Cantidad: " << contadorDificil
              << " | Porcentaje: " << (static_cast<double>(contadorDificil) / totalProyectos) * 100 << "%" << std::endl;
    std::cout << "Dificultad: MUY_DIFICIL | Cantidad: " << contadorMuyDificil
              << " | Porcentaje: " << (static_cast<double>(contadorMuyDificil) / totalProyectos) * 100 << "%" << std::endl;
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