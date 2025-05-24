//variables y funciones

#ifndef DUENIO_H
#define DUENIO_H

class Duenio{   
// Definición de la clase Duenio
// Esta clase representa a un dueño de una mascota y contiene información relevante sobre él.

public:
    int dui;
    char nombre[30];
    char direccion[50];
    int telefono;
};

void agregar_duenio();
bool buscar_duenio();
void editar_duenio();


#endif