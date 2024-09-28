//
// Created by Gabriel Briones on 9/27/2024.
//

#include "ArregloDinamico.h"

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
    free(this->arr);
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


