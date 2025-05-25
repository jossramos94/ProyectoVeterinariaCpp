// Registro de citas/pacientes 

#include "../File_h/Cita.h"
#include "../File_h/Duenio.h"
#include "../File_h/paciente.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

// Función para agregar una nuevo cita
void agendar_cita(){

    // Crear un objeto Cita
    Cita cita;
   
    int codigo_buscar;
    
    cout <<"Ingrese en codigo del paciente: "<<endl;
    cin >> codigo_buscar;

    // Verificar si el paciente existe
    if (!buscar_paciente(codigo_buscar)) {
        cout << "Paciente no encontrado." << endl;
        return;
    }

    cita.codigo = codigo_buscar; // Asignar el código del paciente a la cita
    cin.ignore();
    cout<< "Cita para el paciente con codigo: " << cita.codigo << endl;
    cout << "Ingrese el tratamiento: "<<endl;
    cin.getline(cita.tratamiento, 50);
    cout << "Ingrese la fecha (DD/MM/AAAA): "<<endl;
    cin.getline(cita.fecha, 20);
    cout << "Ingrese la hora (HH:MM): ";
    cin.getline(cita.hora, 10);

    // Abrir el archivo en modo de escritura
    ofstream archivo("citas.bin", ios::app | ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    // Escribir el objeto cita en el archivo
    archivo.write(reinterpret_cast<char*>(&cita), sizeof(Cita));
    if (!archivo) {
        cerr << "Error al escribir en el archivo." << endl;
    } else {
        cout << " Cita agendada exitosamente." << endl;
    }
    // Cerrar el archivo
    archivo.close();
}
 
bool buscar_cita(){
    // Crear un objeto cita
    Cita cita;
    // Solicitar el código del paciente a buscar
    int codigo_buscar;
    int cita_codigo;
    cout << "Ingrese el codigo del paciente a buscar: ";
    cin >> codigo_buscar;

    // Verificar si el paciente existe
    if (!buscar_paciente(codigo_buscar)) {
        cout << "Paciente no encontrado." << endl;
        return false;
    }
    // Abrir el archivo en modo de lectura
    ifstream archivo("citas.bin", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return false;
    }
    bool encontrado = false;
    // Leer el archivo hasta encontrar la cita
    while (archivo.read(reinterpret_cast<char*>(&cita), sizeof(Cita))) {
        if (cita.codigo == codigo_buscar) {
            cout << "Cita encontrada:" << endl;
            cout << "Codigo del paciente: " << cita.codigo << endl;
            cout << "Tratamiento: " << cita.tratamiento << endl;
            cout << "Fecha: " << cita.fecha << endl;
            cout << "Hora: " << cita.hora << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Cita no encontrada." << endl;
    }
    return encontrado; 
}

// Función para editar un duenio

void editar_cita() {

    int codigo_buscar;
    cout << "Ingrese el codigo del paciente a editar: ";
    cin >> codigo_buscar;

    fstream archivo("citas.bin", ios::in | ios::out | ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Cita cita;

    streampos pos;
    // Verificar si el paciente existe
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&cita), sizeof(Cita))) {
        if (buscar_paciente(codigo_buscar) && cita.codigo == codigo_buscar) {
            pos = archivo.tellg() - static_cast<streampos>(sizeof(Cita));
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cita no encontrada.\n";
        archivo.close();
        return;
    }

    cout << "\nCita encontrada.\n"<<endl;
    cout<<"Tratamiento actual: "<<cita.tratamiento<<endl;
    cout<<"fecha programada: "<<cita.fecha<<endl;
    cout<<"Hora actual: "<<cita.hora<<endl;
    cin.ignore();
    cout<<"\nIngrese los nuevos datos:"<<endl;
    cout << "\nIngrese el nuevo tratamiento: ";
    cin.getline(cita.tratamiento, 50);
    cout << "Ingrese la nueva fecha (DD/MM/AAAA): ";
    cin.getline(cita.fecha, 20);
    cout << "Ingrese la nueva hora (HH:MM): ";
    cin.getline(cita.hora, 10);

    // Volver al inicio del archivo para sobrescribir los datos
    archivo.seekp(pos);
    archivo.write(reinterpret_cast<char*>(&cita), sizeof(Cita));
    cout << "Datos actualizados con éxito.\n";

    archivo.close();
}
