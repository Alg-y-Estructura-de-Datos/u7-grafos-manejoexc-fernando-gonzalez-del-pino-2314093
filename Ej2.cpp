#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

/*En una comisión de un colegio o universidad, los profesores o estudiantes son nodos, y las
colaboraciones o relaciones entre ellos, como trabajar en un proyecto, son aristas. Este grafo
puede ser dirigido si una colaboración tiene una jerarquía (por ejemplo, un profesor dirige a
varios estudiantes).
Descripción del problema:
● Cada persona en la comisión es un nodo en el grafo.
● Las colaboraciones o trabajos en conjunto son las aristas.
● Puedes buscar si dos personas están colaborando en algún proyecto.
● Agregar o eliminar miembros y colaboraciones.
● Mostrar todas las relaciones de colaboración dentro de la comisión.
Operaciones:
● Agregar Miembro: Añadir un nodo al grafo representando a un nuevo miembro de la
comisión.
● Agregar Colaboración: Crear una arista dirigida entre dos nodos (miembros) para
representar una relación de trabajo o supervisión.
● Eliminar Colaboración: Eliminar la relación de trabajo entre dos miembros.
● Buscar Miembro: Buscar un miembro en el grafo de la comisión.
● Imprimir Comisión: Mostrar todos los miembros y sus relaciones de trabajo.
*/

void menu() {
    cout << "\n---Comision de Colegio/Universidad---" << endl;
    cout << "1. Agregar miembro" << endl;
    cout << "2. Establecer colaboracion" << endl;
    cout << "3. Buscar miembro" << endl;
    cout << "4. Eliminar miembro" << endl;
    cout << "5. Mostrar estructura de la comision" << endl;
    cout << "6. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    Grafo<string> grafo;
    int opcion;
    string miembro, colaborador;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Nombre del miembro: ";
                cin >> miembro;
                grafo.agregarNodo(miembro);
                break;
            case 2:
                cout << "Nombre del miembro: ";
                cin >> miembro;
                cout << "Nombre del colaborador: ";
                cin >> colaborador;
                grafo.agregarArista(miembro, colaborador);
                break;
            case 3:
                cout << "Nombre del miembro a buscar: ";
                cin >> miembro;
                if (grafo.buscarNodo(miembro)) {
                    cout << "El miembro " << miembro << " esta en la comision.\n";
                } else {
                    cout << "Miembro no encontrado.\n";
                }
                break;
            case 4:
                cout << "Nombre del miembro a eliminar: ";
                cin >> miembro;
                grafo.eliminarNodo(miembro);
                break;
            case 5:
                cout << "Estructura de la comision:\n";
                grafo.imprimir();
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}
