//Hecho por Enrique Antonio Mendez Caceres
		

#include <iostream> //Libreria de funciones de entrada y salida
#include <stdlib.h> //Libreria de funciones agregadas
#include <windows.h> //Libreria de funciones del sistema

using namespace std; 

//Desarrollo de las clases a utilizar en el programa
class Cola { //Clase para formar las coles de los vectores
	private: //Principio de encapsulamiento, las propiedades de una clase son privadas
		//Atributos de la clase
		class Nodo { //Estructura de la clase
			public: //Todos los elementos de la clase con publicos
				float x; //Variable para coordenadas en x
				float y; //Variable para coordenadas en y
				float z; //Variable para coordenadas en z
				Nodo *sig; //Puntero que funciona para apuntar al siguiente nodo
		};
		Nodo *raiz; //Primer elemento de la cola
		Nodo *fondo; //Ultimo elemento de la cola
	//Metodos a utlizar en la clase
	public:
		Cola(); //Costructor, establece los datos iniciales de cada atributo
		~Cola(); //Destructor - Si hay elementos en la cola los va destruyendo poco a poco
		void insertar(float x, float y, float z); //Metodo para insertar coordenadas
		int eliminar(); //Metodo para eliminar - Retorna entero, devuelve el elemento eliminado
		void mostrar(); //Metodo para mostrar
		void promedio(); //Metodo para obtener promedios de las coordenadas
		bool vacia(); //Metodo para evaluar si la cola esta vacia
};
//llamando a la clase :: (los dos puntos son una referencia a la misma clase)
Cola::Cola() { //Setear los elementos de la cola
	raiz = NULL; //Al crearse un elemento se setea a Null
	fondo = NULL; //Al crearse un elemento se setea a Null
}

Cola::~Cola() { //Metodo que destruye la clase, destruye las posiciones en memoria
	Nodo *reco = raiz; //Puntero llamado reco que apunta a la raiz, inicialmente apunta al ultimo elemento
	Nodo *bor; //Puntero bor de tipo nodo que toma momentaneamiente el ultmo elemento para borrar
	
	while(reco != NULL) { //Si hay elementos en la cola
		bor = reco; //Tomar direccion de reco
		reco = reco -> sig; //Ahora el puntero apunta al siguiente, se coloca en el siguiente elemento
		delete bor; //Elimina el elemento en raiz
	}
}

void Cola::insertar(float x, float y, float z) { //Metodo para insertar vectores
	Nodo *nuevo; //Se crea un puntero nuevo, es un auxiliar donde se alamcenan los valores que se colocaran en la pila
	//Etiqueta que parte es para info y que parte es para el puntero
	nuevo = new Nodo(); //Va a ocupar dos porciones en la memoria, en info y en siguiente (para el puntero)
	nuevo->x = x; //Se accede a la parte destinada a guardar coordanada x
	nuevo->y = y; //Se accede a la parte destinada a guardar coordanada y
	nuevo->z = z; //Se accede a la parte destinada a guardar coordanada z
	nuevo->sig = NULL; //El siguiente es nulo, si es el unico dato, el siguiente es nulo
	
	if(vacia()) { //Si la cola esta vacia, si es el unico elemento ambos tienen la misma direccion
		raiz = nuevo; //Raiz es igual a nuevo
		fondo = nuevo; //Fondo es igual a nuevo
	}
	else {
		fondo->sig = nuevo; //Apunta al siguiente, si hay un nodo el siguiente elemento esta arriba
		fondo = nuevo; //Es igual al elemento nuevo, apunta hacia nuevo
	}
}

int Cola::eliminar() { //Metodo para eliminar elementos de la cola
	if(!vacia()) { //Si la cola no esta vacia
		float corx = raiz->x; //El puntero de raiz esta en la coordenada de x
		float cory = raiz->y; //El puntero de raiz esta en la coordenada de y
		float corz = raiz->z; //El puntero de raiz esta en la coordenada de z
		Nodo *bor = raiz; //El primer elemento se coloca en bor
		
		if(raiz == fondo) { //Caso en el que solo hay un nodo en la cola
			raiz = NULL; //Raiz es nuela
			fondo = NULL; //Fundo es nulo
		}
		else { //Si no existe unicamente un elemento
			raiz = raiz->sig; //La raiz sigue al siguiente elemento
		}
		delete bor; //Eliminar elmento de la cola almacenado en bor
		system("color 5F"); //Cambiar colores, rojo, texto blanco
		//Imprimir mensaje para confirmar eliminacion
		cout << "\n\n\n\t\t\t\t//////////////////////////////////////////////////" << endl;
		cout << "\t\t\t\t/ ###  Vector eliminado de la fila con exito ### /" << endl;
		cout << "\t\t\t\t//////////////////////////////////////////////////" << endl << endl;
		return corx, cory, corz; //Retornar informacion de las coordenadas
	}
	else { //Si la cola esta vacia no se extrae nada
		system("color 4F"); //Cambiar colores, rojo, texto blanco
		//Imprimir mensaje para demostrar que no hay datos
		cout << "\n\n\n\t\t\t\t//////////////////////////////////////////////////" << endl;
		cout << "\t\t\t\t/ ###  No existen datos agregados a la cola  ### /" << endl;
		cout << "\t\t\t\t//////////////////////////////////////////////////" << endl << endl;
		return -1;
	}
}

void Cola::mostrar() { //Metodo para mostrar coordenadas de vectores
	int acum = 0; //Variable de c=acumulador para llevar la cuenta de los vectores
	Nodo *reco = raiz; //Obtiene los elementos de la raiz de la cola
	
	//Imprimir cabecera
	cout << "\t\t\t\t\t////////////////////////////////////" << endl;
	cout << "\t\t\t\t\t/Coordenadas almacenadas en la cola/" << endl;
	cout << "\t\t\t\t\t////////////////////////////////////" << endl;
	if(reco != NULL) { //Mientras el recorrido no sea nulo, mientras no este vacio
		system("color 5F"); //Cambiar colores, fondo morado, texto blanco
		while(reco != NULL) {
			system("color 2F"); //Cambiar colores, fondo verde, texto blanco
			//Imprimir elementos del listado
			cout << "\t\t\t\t\t\tCoordenada x: " << reco->x << endl; //Imprime coordenada x
			cout << "\t\t\t\t\t------------------------------------" << endl;
			cout << "\t\t\t\t\t\tCoordenada y: " << reco->y << endl; //Imprime coordenada y
			cout << "\t\t\t\t\t------------------------------------" << endl;
			cout << "\t\t\t\t\t\tCoordenada z: " << reco->z << endl; //Imprime coordenada z
			cout << "\t\t\t\t\t////////////////////////////////////" << endl;
			reco = reco->sig; //Reco avanza al siguiente vector
			acum++; //El acumulador avanza
		}
		cout << endl;
	}
	else {
		system("cls"); //Borrar pantalla de la consola
		system("color 4F"); //Cambiar colores, fondo rojo, texto blanco
		//Imprimir mensaje para demostrar que no hay datos
		cout << "\n\t\t\t\t//////////////////////////////////////////////////" << endl;
		cout << "\t\t\t\t/ ###  No existen datos agregados a la cola  ### /" << endl;
		cout << "\t\t\t\t//////////////////////////////////////////////////" << endl;
	}
	//Imprimir espacio utilizado en memoria
	cout << "\n\t\t\t\t==================================================" << endl;
	cout << "\t\t\t\t\t  Espacio en memoria: " << acum * 12 << " bytes" << endl;
	cout << "\t\t\t\t==================================================" << endl << endl;
}

void Cola::promedio() { //Metodo para obtener promedio de los vectores
	Nodo *reco = raiz; //Puntero reco es igual a la raiz de los nodos
	double cont = 0;
	double promx; //Para almacenar sumatoria de coordenadas en x
	double promy; //Para almacenar sumatoria de coordenadas en y
	double promz; //Para almacenar sumatoria de coordenadas en z
	double resx; //Para obtener promedio de x
	double resy; //Para obtener promedio de y
	double resz; //Para obtener promedio de z
	
	if(reco != NULL) {
		system("color 1F"); //Cambiar colores, fondo azul, texto blanco
		while(reco != NULL) { //Mientras el recorrido no sea nulo
			promx = promx + reco->x; //Acumular sumetoria de coordenadas en x
			promy = promy + reco->y; //Acumular sumetoria de coordenadas en y
			promz = promz + reco->z; //Acumular sumetoria de coordenadas en z
			reco = reco->sig; //Avanza al siguiente espacio
			cont++; //Contador aumenta
		}
		
		resx = promx / cont; //Realiza operacion para promediar x
		resy = promy / cont; //Realiza operacion para promediar y
		resz = promz / cont; //Realiza operacion para promediar z
		
		//Imprimir resultados
		cout << "\n\n\n\n\t\t\t\t   //////////////////////////////////////////" << endl;
		cout << "\t\t\t\t    Promedio de coordenadas de los vectores  " << endl;
		cout << "\t\t\t\t   //////////////////////////////////////////" << endl;
		cout << "\t\t\t\t       Promedio de coordenada x = " << resx << endl; //Imprimir promedio x
		cout << "\t\t\t\t   ------------------------------------------" << endl;
		cout << "\t\t\t\t       Promedio de coordenada y = " << resy << endl; //Imprimir promedio y
		cout << "\t\t\t\t   ------------------------------------------" << endl;
		cout << "\t\t\t\t       Promedio de coordenada z = " << resz << endl; //Imprimir promedio z
		cout << "\t\t\t\t   //////////////////////////////////////////" << endl << endl;
	}
	else {
		system("cls"); //Borrar pantalla de la consola
		system("color 4F"); //Cambiar colores, fondo rojo, texto blanco
		//Imprimir mensaje para demostrar que no hay datos
		cout << "\n\n\n\t\t\t\t//////////////////////////////////////////////////" << endl;
		cout << "\t\t\t\t/ ###  No existen datos agregados a la cola  ### /" << endl;
		cout << "\t\t\t\t//////////////////////////////////////////////////" << endl << endl;
	}
}

bool Cola::vacia() { //Metodo para conocer si la cola esta vacia
	if(raiz == NULL) { //Si la cola esta vacia
		return true; 
	}
	else { //Si no esta vacia
		return false;
	}
}


//Prototipos de funciones a utilizar en el programa
void menu(); //Funcion para mostrar menu
int tomarINT(); //Funcion para tomar enteros
bool validINT(string); //Funcion para validar enteros


//Desarrollo del codigo principa
int main() {
	int opc; //Variable de opciones
	float x; //Variable de coordenada x
	float y; //Variable de coordenada y
	float z; //Variable de coordenada z
	Cola *vect = new Cola(); //Crear nueva cola
	
	do {
		menu(); //Ejecutar funcion de menu visual
		opc = tomarINT(); //Tomar dato de la opcion digitada
		switch(opc){ //Selector de opciones segun caso
			case 1: //Caso 1 para ingresar vectores
				system("cls"); //Borrar pantalla de la consola
				system("color 3F"); //Cambiar colores, fondo celeste, texto blanco
				cout << "\n\n\n\n\t\t\t\t//////////////////////////////////////////////" << endl;
				cout << "\t\t\t\t\tIngrese la cordenada en x: "; //Pedir ingreso de coordenada
				cin >> x; //Toma el dato en la coordenada x
				cout << "\t\t\t\t----------------------------------------------" << endl;
				cout << "\t\t\t\t\tIngrese la cordenada en y: "; //Pedir ingreso de coordenada
				cin >> y; //Toma el dato en la coordenada y
				cout << "\t\t\t\t----------------------------------------------" << endl;
				cout << "\t\t\t\t\tIngrese coordenada en z: "; //Pedir ingreso de coordenada
				cin >> z; //Toma el dato en la coordenada z
				cout << "\t\t\t\t//////////////////////////////////////////////" << endl << endl;
				vect->insertar(x, y, z); //Ejecuta metodo para ingresar coordenadas del vector
				
				system("pause"); //Pausa la pantalla de la consola
				break; //Termina los procesos
			
			case 2: //Caso 2 para mostrar vectores en la cola
				system("cls"); //Borrar pantalla de la consola
				vect->mostrar(); //Ejecutar metodo para mostrar vectores
				system("pause"); //Pausa la pantalla de la consola
				break; //Termina los procesos
			
			case 3: //Caso 3 para eliminar vectores de la cola
				system("cls"); //Borrar pantalla de la consola
				vect->eliminar(); //Ejecutar metodo para elminiar vectores
				system("pause"); //Pausa la pantalla de la consola
				break; //Termina los procesos
			
			case 4: //Caso 4 para obtener promedio de las coordenadas
				system("cls"); //Borrar pantalla de la consola
				vect->promedio(); //Ejecutar metodo para promediar vectores
				system("pause"); //Pausa la pantalla de la consola
				break; //Termina los procesos
			
			case 5: //Caso 5 para salir del programa
				break; //Termina los procesos
		}
	}while(opc!=5); //Mientras sobrepase los 5 casos
	
	system("pause"); //Pausa la pantalla de la consola
	delete vect; //Elimina la cola automaticamente al salir del programa
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//Desarrollo de las funciones
void menu() { //Funcion para mostrar menu
	system("cls"); //Borrar pantalla de la consola
	system("color 02"); 
	cout << endl << endl << endl << endl << endl; //Espacios de linea
	//Imprimir menu de opciones en pantalla

	cout << "            MENU            " << endl;
	
	cout << " 1. Agregar vector a la cola              " << endl;
	cout << " 2. Mostrar vectores en la cola           " << endl;
	cout << " 3. Eliminar vector de la cola            " << endl;
	cout << " 4. Promedio de vectores en cola          " << endl;
	cout << " 5. Salir                                 " << endl;
	
	cout << "Digite una opcion: "; //Mensaje para pedir ingreso de opcion
}

int tomarINT() { //Funcion para tomar enteros
	string numero; //Variable de cadena para el numero
	bool valido = false; //Variable booleana para validar
	
	while(!valido) { //Mientras no sea valido
		try{ //Intentar
			getline(cin, numero); //Obtener numero
			valido = validINT(numero); //Ejecutar funcion de validacion
			if(!valido) { //Si no sigue siendo valido
				throw numero; //Arrojar numero
			}
		}
		catch (string e) { //Capturar dato de la cadena
			break; //Terminar proceso
		}
	}
	
	return atoi(numero.c_str()); //Convertir string a int y regresar numero
}

bool validINT(string numero) { //Funcion para validar enteros
	int inicio = 0; //Variable de inicio de conteo
	
	if(numero.length() == 0) { //Si no hay elementos en la caena
		return 0; //Retornar valor falso
	}
	else if (numero[0] == '+' || numero[0] == '-') { //Si el elemento contiene un signo
		inicio = 1; //Iniciar en 1
		if(numero.length() == 1) { //Si la longitud es uno
			return 0; //Devolver falso
		}
	}
	
	for(int i = inicio; i < numero.length(); i++) { //Ciclo segun el temanio
		if(!isdigit(numero[i])) { //Si no es un digito
			return 0; //Retornar falso
		}
	}
	
	return 1; //Devolver verdadero, cumple los requisitos
}
