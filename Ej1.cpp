#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

/*En una red social, los usuarios son representados como nodos, y las relaciones de amistad o
conexión entre ellos son aristas. Este grafo es no dirigido, ya que, si dos usuarios son amigos,
la relación es bidireccional. También puedes almacenar atributos adicionales, como el
número de interacciones entre ellos, que podrían ser ponderaciones en las aristas.
Descripción del problema:
● Cada usuario de la red social es un nodo en el grafo.
● Las amistades entre usuarios son las aristas.
● Puedes buscar si dos usuarios son amigos.
● Puedes agregar nuevas amistades.
● Eliminar amistades o usuarios de la red.
Operaciones:
1. Insertar Usuario: Añadir un nodo al grafo representando a un nuevo usuario.
2. Agregar Amistad: Añadir una arista entre dos nodos (usuarios) para representar una
amistad.
3. Eliminar Amistad: Quitar la conexión entre dos usuarios.
4. Buscar Usuario: Ver si un usuario está en la red social.
5. Imprimir la Red Social: Mostrar todos los usuarios y sus amigos (las conexiones en el
grafo)*/

void menu() {
    cout << "\n---Red Social---" << endl;
    cout << "1. Insertar Usuario" << endl;
    cout << "2. Agregar Amistad" << endl;
    cout << "3. Eliminar Amistad" << endl;
    cout << "4. Buscar Usuario" << endl;
    cout << "5. Imprimir la Red Social" << endl;
    cout << "6. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    Grafo<string> redSocial;
    int opcion;
    string persona, amigo;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Nombre de la persona: ";
                cin >> persona;
                try {
                    redSocial.agregarNodo(persona);
                    cout << "Se agrego el usuario " << persona << endl;
                } catch (int e) {
                    cerr << "Error, el usuario ya existe o la opcion es invalida" << endl;
                }
                break;
            case 2:
                cout << "Nombre de la persona: ";
                cin >> persona;
                cout << "Nombre del amigo: ";
                cin >> amigo;
                redSocial.agregarArista(persona, amigo);
                cout << "Se agrego la amistad entre " << persona << " y " << amigo << endl;
                break;
            case 3:
                cout << "Nombre de la persona: ";
                cin >> persona;
                cout << "Nombre del amigo: ";
                cin >> amigo;
                redSocial.eliminarArista(persona, amigo);
                cout << "Se elimino la amistad entre " << persona << " y " << amigo << endl;
                break;
            case 4:
                cout << "Nombre de la persona: ";
                cin >> persona;
                if (redSocial.buscarNodo(persona)) {
                    cout << "El usuario " << persona << " esta en la red social" << endl;
                } else {
                    cout << "El usuario " << persona << " no esta en la red social" << endl;
                }
                break;
            case 5:
                cout << "Red Social:" << endl;
                redSocial.imprimir();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default :
                cerr << "Opcion invalida" << endl;
        }
    } while (opcion != 6);

    return 0;
}
