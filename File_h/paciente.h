//variables y funciones

#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente{

public:
    int codigo;
    char nombre[30];
    char raza[30];
    char tipo[15];
    char fecha_nacimiento[10];
};

void agregar_paciente();
bool buscar_paciente(int codigo_buscar);
void editar_paciente();


#endif