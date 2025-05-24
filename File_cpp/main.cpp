//implementar menu de opciones

#include <iostream>
#include <string>
#include <fstream>
#include "../File_h/paciente.h"
#include "../File_cpp/paciente.cpp"
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;
// Función para mostrar el menú

void mostrar_menu(){
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
        case 2:
            buscar_paciente();
            break;
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
// Función principal
int main() {
    mostrar_menu();
    return 0;
}