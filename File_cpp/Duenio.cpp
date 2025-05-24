// Registro de duenios/pacientes 

#include "../File_h/Duenio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

// Función para agregar un nuevo duenio
void agregar_duenio(){
    // Crear un objeto duenio
    Duenio duenio;

    cout << "Ingrese el numero de DUI del dueño: ";
    cin >> duenio.dui;

    cout << "Ingrese el nombre del dueño: ";  
    cin.ignore(); cin.getline(duenio.nombre, 30);

    cout << "Ingrese la direccion del dueño: ";
    cin.getline(duenio.direccion, 50);

    cout << "Ingrese el telefono del dueño: ";
    cin >> duenio.telefono;
    cin.ignore();

    // Abrir el archivo en modo de escritura
    ofstream archivo("duenios.bin", ios::app | ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    // Escribir el objeto duenio en el archivo
    archivo.write(reinterpret_cast<char*>(&duenio), sizeof(Duenio));
    if (!archivo) {
        cerr << "Error al escribir en el archivo." << endl;
    } else {
        cout << " Duenio agregado exitosamente." << endl;
    }
    // Cerrar el archivo
    archivo.close();

}

bool buscar_duenio(){
    // Crear un objeto Pacientes
    Duenio duenio;
    // Solicitar el código del duenio a buscar
    int dui_buscar;

    cout << "Ingrese el numero de DUI del duenio a buscar: ";
    cin >> dui_buscar;

    // Abrir el archivo en modo de lectura
    ifstream archivo("duenios.bin", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return false;
    }

    bool encontrado = false;
    // Leer el archivo hasta encontrar el duenio
    while (archivo.read(reinterpret_cast<char*>(&duenio), sizeof(Duenio))) {
        if (duenio.dui == dui_buscar) {
            cout << "Duenio encontrado:" << endl;
            cout << "DUI: " << duenio.dui << endl;
            cout << "Nombre: " << duenio.nombre << endl;
            cout << "Direccion: " << duenio.direccion << endl;
            cout << "Telefono: " << duenio.telefono << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Duenio no encontrado." << endl;
    }

    // Cerrar el archivo
    archivo.close();
    return encontrado;
}

// Función para editar un duenio

void editar_duenio() {

    int codigoBuscado;
    cout << "Ingrese el numero de Dui del duenio a editar: ";
    cin >> codigoBuscado;

    fstream archivo("duenios.bin", ios::in | ios::out | ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Duenio duenio;
    // streampos es una clase de la biblioteca estándar de C++ que representa una posición en un flujo de entrada/salida (stream).
    // Se utiliza para almacenar y manipular posiciones dentro de archivos o flujos, permitiendo operaciones como buscar (seek) o decir (tell) la ubicación actual.
    // Es comúnmente usada con archivos binarios y funciones como seekg, seekp, tellg y tellp en streams de C++.
    streampos pos;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&duenio), sizeof(Duenio))) {
        if (duenio.dui== codigoBuscado) {
            pos = archivo.tellg() - static_cast<streampos>(sizeof(Duenio));
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Duenio no encontrado.\n";
        archivo.close();
        return;
    }

    cout << "Duenio encontrado. Ingrese los nuevos datos:\n";
    cin.ignore();
    cout << "Ingrese el nuevo numero de DUI del dueño: ";
    cin >> duenio.dui;
    cin.ignore();
    cout << "Ingrese el nuevo nombre del dueño: ";
    cin.getline(duenio.nombre, 30);
    cout << "Ingrese la nueva direccion del dueño: ";
    cin.getline(duenio.direccion, 50);
    cout << "Ingrese el nuevo telefono del dueño: ";
    cin >> duenio.telefono;
    cin.ignore();

    // Volver al inicio del archivo para sobrescribir los datos
    archivo.seekp(pos);
    archivo.write(reinterpret_cast<char*>(&duenio), sizeof(Duenio));
    cout << "Datos actualizados con éxito.\n";

    archivo.close();
}
