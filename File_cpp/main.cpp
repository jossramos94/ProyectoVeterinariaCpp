//implementar menu de opciones

#include <iostream>
#include <string>
#include <fstream>
#include "../File_h/paciente.h"
#include "../File_cpp/paciente.cpp"
#include "../File_h/Duenio.h"
#include "../File_cpp/Duenio.cpp"
#include "../File_h/Cita.h"
#include "../File_cpp/Cita.cpp"
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

// Función para mostrar el menú de pacientes
void mostrar_menuPacientes(){
    int opcion=0;

do{
    cout << "=" << setw(50) << "=" << endl;
    cout << "Bienvenido al sistema de registro de pacientes" << endl;
    cout << "1. Agregar paciente" << endl;
    cout << "2. Buscar paciente" << endl;
    cout << "3. Editar paciente" << endl;
    cout << "4. Salir" << endl;
    cout << "=" << setw(50) << "=" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

 
   switch(opcion){
        case 1:
            agregar_paciente();
            break;
        case 2:{
            int codigo_buscar;
            cout << "Ingrese el codigo del paciente a buscar: ";
            cin >> codigo_buscar;
            buscar_paciente(codigo_buscar);
            break;
        }
        case 3:
            editar_paciente();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
    }  
    }
    while (opcion != 4);
    cout << "Gracias por usar el sistema."<<endl;

};

// Función para mostrar el menú de dueños
void mostrar_menuDuenios(){
    int opcion=0;

do{
    cout << "=" << setw(50) << "=" << endl;
    cout << "Bienvenido al sistema de registro de duenios" << endl;
    cout << "1. Agregar duenio" << endl;
    cout << "2. Buscar duenio" << endl;
    cout << "3. Editar duenio" << endl;
    cout << "4. Salir" << endl;
    cout << "=" << setw(50) << "=" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

 
   switch(opcion){
        case 1:
            agregar_duenio();
            break;
        case 2:
            buscar_duenio();
            break;
        case 3:
            editar_duenio();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
    }  
    }
    while (opcion != 4);
    cout << "Gracias por usar el sistema."<<endl;

};

// Función para agendar una cita
void menu_agendarCita(){
    int opcion=0;

do{
    cout << "=" << setw(50) << "=" << endl;
    cout << "Bienvenido al sistema de registro de citas" << endl;
    cout << "1. Agendar cita" << endl;
    cout << "2. Buscar cita" << endl;
    cout << "3. Editar cita" << endl;
    cout << "4. Salir" << endl;
    cout << "=" << setw(50) << "=" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

 
   switch(opcion){
        case 1:
            agendar_cita();
            break;
        case 2:
            buscar_cita();
            break;
        case 3:
            editar_cita();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
    }  
    }
    while (opcion != 4);
    cout << "Gracias por usar el sistema."<<endl;

};
// Función principal
int main() {
    // Mostrar el menú al usuario
    int opcion=0;
    cout << "Bienvenido a clínica VET.SV " << endl;

    do{
        cout << "1. Pacientes" << endl;
        cout << "2. Dueños" << endl;
        cout << "3. Agendar cita" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        
        switch (opcion)
        {
        case 1:
            mostrar_menuPacientes();
            break;
        case 2:
            mostrar_menuDuenios();
            break;
        case 3:
            menu_agendarCita();
            break;
        
        default:
            break;
        }
    }
    while (opcion != 4);
    cout << "Gracias por usar el sistema."<<endl;

    return 0;
}