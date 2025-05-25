//variables y funciones

#ifndef CITA_H
#define CITA_H

class Cita{   
// Definición de la clase Cita
// Esta clase representa una cita médica y contiene información relevante sobre ella.

public:
    int codigo;
    char tratamiento[50];
    char fecha[20];
    char hora[10];

};

void agendar_cita();
bool buscar_cita();
void editar_cita();


#endif