// Registro de mascotas/pacientes 

#include "../File_h/paciente.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

// Función para agregar un nuevo paciente
void agregar_paciente(){
    // Crear un objeto Pacientes
    Paciente paciente;

    cout << "Ingrese el codigo del paciente: ";
    cin>>paciente.codigo;

    cout << "Ingrese el nombre del paciente: "; 
    cin.ignore(); cin.getline(paciente.nombre, 30);

    cout << "Ingrese la raza del paciente: ";
    cin.getline(paciente.raza, 30); 

    cout << "Ingrese el tipo de paciente (perro/gato): ";
    cin.getline(paciente.tipo, 15);

    cout << "Ingrese la fecha de nacimiento del paciente (DD/MM/AAAA): ";
    cin.getline(paciente.fecha_nacimiento, 12);
    cin.ignore();

    // Abrir el archivo en modo de escritura
    ofstream archivo("pacientes.bin", ios::app | ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    // Escribir el objeto Pacientes en el archivo
    archivo.write(reinterpret_cast<char*>(&paciente), sizeof(Paciente));
    if (!archivo) {
        cerr << "Error al escribir en el archivo." << endl;
    } else {
        cout << "Paciente agregado exitosamente." << endl;
    }
    // Cerrar el archivo
    archivo.close();

}
