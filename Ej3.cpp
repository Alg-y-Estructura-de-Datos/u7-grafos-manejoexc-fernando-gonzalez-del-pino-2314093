#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

/*En una ciudad, se está implementando un sistema de gestión de rutas de transporte entre
distintas estaciones. Cada estación se representa como un nodo, y las rutas directas entre
estaciones se representan como aristas. Tu tarea es diseñar este sistema de rutas utilizando
grafos, donde los ciudadanos puedan interactuar con el sistema para realizar varias
operaciones.
1. Agregar estaciones: El sistema debe permitir agregar nuevas estaciones al mapa. Cada
estación tiene un nombre único.
2. Conexión de rutas entre estaciones: Las estaciones pueden estar conectadas
mediante rutas directas. El sistema debe permitir agregar una conexión entre dos
estaciones, indicando que existe una ruta entre ellas.
3. Eliminar estaciones: Si una estación deja de funcionar, debe ser posible eliminarla del
sistema. Al eliminar una estación, también deben eliminarse todas las rutas que
conectan a dicha estación.
4. Eliminar rutas: En caso de que una ruta deje de ser operativa entre dos estaciones, el
sistema debe poder eliminar esa conexión sin afectar al resto de las estaciones.
5. Consulta de conectividad: Los ciudadanos podrán consultar si existe una ruta directa
entre dos estaciones específicas. El sistema debe devolver si esas estaciones están
conectadas por una ruta.
6. Verificar si una estación existe: El sistema debe proporcionar una función para
verificar si una estación específica existe en el mapa.
7. Imprimir el mapa completo: Finalmente, el sistema debe poder imprimir un listado de
todas las estaciones y sus conexiones directas, mostrando el estado actual de todas
las rutas en la ciudad*/

void menu() {
    cout << "\n---Sistema de Rutas---" << endl;
    cout << "1. Agregar estacion" << endl;
    cout << "2. Agregar ruta" << endl;
    cout << "3. Eliminar estacion" << endl;
    cout << "4. Eliminar ruta" << endl;
    cout << "5. Consultar conectividad" << endl;
    cout << "6. Verificar existencia de estacion" << endl;
    cout << "7. Imprimir mapa de rutas" << endl;
    cout << "8. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    Grafo<string> sistemaRutas;
    int opcion;
    string estacion1, estacion2;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre de la estacion: ";
            cin >> estacion1;
            try {
                sistemaRutas.agregarNodo(estacion1);
                cout << "Se agrego la estacion " << estacion1 << endl;
            } catch (int e) {
                cerr << "Error, la estacion ya existe o la opcion es invalida" << endl;
            }
            break;
            case 2:
                cout << "Ingrese la estacion de origen: ";
            cin >> estacion1;
            cout << "Ingrese la estacion de destino: ";
            cin >> estacion2;
            sistemaRutas.agregarArista(estacion1, estacion2);
            cout << "Se agrego la ruta entre " << estacion1 << " y " << estacion2 << endl;
            break;
            case 3:
                cout << "Ingrese el nombre de la estacion a eliminar: ";
            cin >> estacion1;
            sistemaRutas.eliminarNodo(estacion1);
            cout << "Se elimino la estacion " << estacion1 << endl;
            break;
            case 4:
                cout << "Ingrese la estacion de origen: ";
            cin >> estacion1;
            cout << "Ingrese la estacion de destino: ";
            cin >> estacion2;
            sistemaRutas.eliminarArista(estacion1, estacion2);
            cout << "Se elimino la ruta entre " << estacion1 << " y " << estacion2 << endl;
            break;
            case 5:
                cout << "Ingrese la estacion de origen: ";
            cin >> estacion1;
            cout << "Ingrese la estacion de destino: ";
            cin >> estacion2;
            if (sistemaRutas.estanConectados(estacion1, estacion2)) {
                cout << "Las estaciones " << estacion1 << " y " << estacion2 << " estan conectadas" << endl;
            } else {
                cout << "Las estaciones " << estacion1 << " y " << estacion2 << " no estan conectadas" << endl;
            }
            break;
            case 6:
                cout << "Ingrese el nombre de la estacion a buscar: ";
            cin >> estacion1;
            if (sistemaRutas.buscarNodo(estacion1)) {
                cout << "La estacion " << estacion1 << " esta en el sistema" << endl;
            } else {
                cout << "La estacion " << estacion1 << " no esta en el sistema" << endl;
            }
            break;
            case 7:
                cout << "Mapa de rutas:" << endl;
            sistemaRutas.imprimir();
            break;
            case 8:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 8);

    return 0;
}
