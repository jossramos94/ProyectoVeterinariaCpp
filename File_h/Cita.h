//variables y funciones

#ifndef CITA_H
#define CITA_H

class Cita{   
// Definición de la clase Duenio
// Esta clase representa a un dueño de una mascota y contiene información relevante sobre él.

public:
    char tratamiento[50];
    char fecha[20];
    char hora[10];

};

void agregar_cita();
bool buscar_cita();
void editar_editar();


#endif