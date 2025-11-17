#include <iostream>
using namespace std;

struct cliente {
    string nombre;
    cliente* siguientecliente;
};

cliente*  listaclientes=NULL;
string nombreT; 

void atendercliente() {
    if (listaclientes == NULL) {
        cout << "No hay clientes en espera.\n";
        return;
    }
    cliente* atendido = listaclientes;
    cout << "Atendiendo a: " << atendido->nombre << "\n";
    listaclientes = listaclientes->siguientecliente;
    delete atendido;
}

cliente* agregarclientefondo() {
    cliente* ncliente = new cliente;

    cout << "Cliente: ";
    cin >> nombreT;
    ncliente->nombre =nombreT ;
    ncliente->siguientecliente = NULL;

    if (listaclientes == NULL) {  
        listaclientes = ncliente;  
    } else {                       
        cliente* actual = listaclientes; 
        while (actual->siguientecliente != NULL) { 
            actual = actual->siguientecliente;     
        }                                          
        actual->siguientecliente = ncliente;       
    }                                              

    return ncliente; 
} 

void desplegarlista() {
    cliente* actual = listaclientes; //Puntero que apunta al cliente mas nuevo

    while (actual != NULL) { 
        cout << "Nombre: " << actual->nombre <<"\n";
        actual = actual->siguientecliente; //Avanza el puntero al siguiente clienete
    }
}

void liberarmemoria() {
    cliente* actual = listaclientes; //Puntero que apunta al contacto mas nuevo
    cliente* siguiente;

    while (actual != NULL) { 
        siguiente = actual->siguientecliente; //Guarda la direccion del siguiente contacto
        delete actual; //Libera la memoria del contacto actual
        actual = siguiente; //Vuelve el contacto siguiente el contacto actual
    }
    listaclientes = NULL; //Eliminamos el apuntador porque ya no hay contactos
}

int main(){
	int opcion;	
	do {    
		cout << "\n----- Menu----\n";
        cout << "1. Agrega un nuevo cliente a la cola\n";
        cout << "2. Atender al siguiente\n";
        cout << "3. Lista de espera\n";
        cout << "4. Vaciar la lista de espera\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
 	
	 	switch(opcion) {
	 		case 1:
	 			agregarclientefondo();
	 			break;
	 		case 2:
	 			cout << "\n----- Proceso ----\n";
	 			atendercliente();
	 			break;
	 		case 3:
	 			cout << "\n----- Lista de espera ----\n";
	 			if(listaclientes!=NULL) {
	 				desplegarlista();
				}else{
					cout<<"No hay clientes en espera\n";	
				}
	 			
			 	break;
			case 4:
				liberarmemoria();
				cout << "Lista de espera vaciada.\n";
                break;
			case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida\n";	
		}
	} while(opcion != 5);
}
