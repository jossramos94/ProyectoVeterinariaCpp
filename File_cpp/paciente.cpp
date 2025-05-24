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

void buscar_paciente(){
    // Crear un objeto Pacientes
    Paciente paciente;
    int codigo_buscar;

    cout << "Ingrese el codigo del paciente a buscar: ";
    cin >> codigo_buscar;

    // Abrir el archivo en modo de lectura
    ifstream archivo("pacientes.bin", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    bool encontrado = false;
    // Leer el archivo hasta encontrar el paciente
    while (archivo.read(reinterpret_cast<char*>(&paciente), sizeof(Paciente))) {
        if (paciente.codigo == codigo_buscar) {
            cout << "Paciente encontrado:" << endl;
            cout << "Codigo: " << paciente.codigo << endl;
            cout << "Nombre: " << paciente.nombre << endl;
            cout << "Raza: " << paciente.raza << endl;
            cout << "Tipo: " << paciente.tipo << endl;
            cout << "Fecha de nacimiento: " << paciente.fecha_nacimiento << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Paciente no encontrado." << endl;
    }

    // Cerrar el archivo
    archivo.close();
}
// Función para editar un paciente
// void editar_paciente(){
//     // Crear un objeto Pacientes
