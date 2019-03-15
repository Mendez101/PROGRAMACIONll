//Programa desarrollado por Enrique Antonio Mendez Caceres
//MC18082

		
#include <iostream> //Libreria de funciones de entrada y salida
#include <stdlib.h> //Libreria de funciones agregadas
#include <queue> //Libreria de pilas

using namespace std; //Simplificacion del codigo


struct vect { //Estructura para vectores
	float x; //Variable de coordenada en x
	float y; //Variable de coordenada en y
	float z; //Variable de coordenada en z
};


//Prototipos de funciones
void menu(vect n, queue<vect> cola); //Funcion para menu de opciones
int tomarINT(vect n, queue<vect> cola); //Funcion para tomar enteros
bool validINT(string); //Funcion para validar enteros
void ingresar(vect n, queue<vect> cola); //Funcion para ingresar coordenadas
void mostrar(vect n, queue<vect> cola); //Funcion para mostrar coordenadas
void eliminar(vect n, queue<vect> cola); //Funcion para eliminar coordenadas
void promedio(vect n, queue<vect> cola); //Funcion para promedio de coordenadas


int main() {
	vect n; //Crear nueva variable de dvector
	queue<vect> cola; //Crear nueva cola
	
	menu(n, cola); //Ejcutar funcion de menu principal
	
	return 0; //Retornar valores a cero
}


//Desarrollo de las funciones
void menu(vect n, queue<vect> cola) {
	system("cls"); //Limpiar pantalla de consola
	int opc; //Variable para almacenar opciones de menu
	
	do {
		system("color 02"); //Cambiar colores, fondo turquesa, texto blanco
	    cout << endl << endl << endl << endl << endl; //Espacios de linea
	    //Imprimir menu de opciones en pantalla
	
	    cout << "           MENU DE OPERACIONES           " << endl;
	    cout << "        1. Agregar vector a la cola              " << endl;
	    cout << "        2. Mostrar vectores en la cola           " << endl;
	    cout << "        3. Eliminar vector de la cola            " << endl;
	    cout << "        4. Promedio de vectores en cola          " << endl;
	    cout << "        5. Salir                                 " << endl;
	    cout << "-----------------------------------------" << endl << endl;
	    
	    cout << "Digite la opcion: "; //Mensaje para pedir ingreso de opcion
	    opc = tomarINT(n, cola); //Tomar dato y validar entrada
	}while(opc < 1 || opc > 5); //Mientras se ingrese uno de los numeros correspondientes
	
	switch(opc) {
		case 1: //Ingresar vectores
			ingresar(n, cola); //Ejecutar funcion de ingresar vectores
			break; //Terminar proceso
			
		case 2: //Mostrar vectores
			mostrar(n, cola); //Ejecutar funcion de mostrar vectores
			break; //Terminar proceso
			
		case 3: //Eliminar vector
			eliminar(n, cola); //Ejecutar funcion de eliminar vectores
			break; //Terminar proceso
			
		case 4: //Obtener promedio
			promedio(n, cola); //Ejecutar funcion para obtener promedio
			break; //Terminar proceso
			
		case 5: //Salir
			break; //Terminar proceso
	}
}

int tomarINT(vect n, queue<vect> cola) { //Funcion para tomar enteros
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
			menu(n, cola); //Reiniciar menu
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

void ingresar(vect n, queue<vect> cola) { //Desarrollo de funcion para agregar nuevo vector
	system("cls"); //Limpiar pantalla de consola
	
	cout << "\t\t\t\t\tIngrese coordenada en x: "; //Pedir ingreso de coordenada
	cin >> n.x; //Tomar dato y validar entrada
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t\tIngrese coordenada en y: "; //Pedir ingreso de coordenada
	cin >> n.y; //Tomar dato y validar entrada
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t\tIngrese coordenada en z: "; //Pedir ingreso de coordenada
	cin >> n.z; //Tomar dato y validar entrada
	cola.push(n); //Agregar elementos a la cola con respecto a la estructura

	
	system("pause"); //Pausar pantalla
	menu(n, cola); //Ejecutar funcion de menu para regresar
}

void mostrar(vect n, queue<vect> cola) { //Desarrollo de funcion para mostrar vectores
	system("cls"); //Limpiar pantalla de la consola
	vect *puntero; //Crear puntero para recorrer la pila
	float countx;
	float county;
	float countz;
	float countv;
	
	puntero = &cola.front(); //Almacenar diraccion del primer elemento en fila
	if(cola.size() == NULL) { //Si no hay elementos en la pila
		//Imprimir mensaje para demostrar que no hay datos
	
		cout << "\t\t\t\t/ ###  No existen datos agregados a la cola  ### /" << endl;
		
	}
	else {
		for(int i = 1; i <= cola.size(); i++) { //Imprimir mientras existan elemenos
			n = *puntero; //Recopila datos del puntero
		
			cout << "\t\t\t\t\t\tCoordenada x: " << n.x << endl; //Imprime coordenada x
			cout << "\t\t\t\t\t------------------------------------" << endl;
			cout << "\t\t\t\t\t\tCoordenada y: " << n.y << endl; //Imprime coordenada y
			cout << "\t\t\t\t\t------------------------------------" << endl;
			cout << "\t\t\t\t\t\tCoordenada z: " << n.z << endl; //Imprime coordenada z
		
			puntero++; //Pasar al siguiente elemento
		}
		
		countx = sizeof n.x * cola.size(); //Obtener tamano de x y multiplicar por vectores en cola
		county = sizeof n.y * cola.size(); //Obtener tamano de y y multiplicar por vectores en cola
		countz = sizeof n.z * cola.size(); //Obtener tamano de z y multiplicar por vectores en cola
		countv = cola.size() * sizeof n; //Numero de vectores en cola multiplicar por tamanio vect
		//Imprimir resultados del los espacios en memoria
		cout << "\n\t\t\t\t\t| Tamanio total coordenadas x = " << countx << " bytes |" << endl;
		cout << "\t\t\t\t\t| Tamanio total coordenadas y = " << county << " bytes |" << endl;
		cout << "\t\t\t\t\t| Tamanio total coordenadas z = " << countz << " bytes |" << endl;
		cout << "\t\t\t\t\t| Tamanio total vectores = " << countv << " bytes |" << endl;
		cout << endl;
	}
		
	system("pause"); //Pausar pantalla
	menu(n, cola); //Ejecutar funcion de menu para regresar
}

void eliminar(vect n, queue<vect> cola) { //Funcion para eliminar vector
	system("cls"); //Limpiar pantalla de la consola
	if(cola.size() == NULL) { //Si no hay elementos en la pila
		//Imprimir mensaje para demostrar que no hay datos
	
		cout << "\t\t\t\t/ ###  No existen datos agregados a la cola  ### /" << endl;
	
	}
	else {
		cola.pop(); //Elimina primer elemento en fila
		//Imprimir mensaje para confirmar eliminacion
	
		cout << "\t\t\t\t/ ###  Vector eliminado de la fila con exito ### /" << endl;
	
	}
	
	system("pause"); //Pausar pantalla de la consola
	menu(n, cola); //Ejecutar funcion de menu para regresar
}

void promedio(vect n, queue<vect> cola) { //Desarrollo de funcion para obtener promedio de vectores
	system("cls"); //Limpiar pantalla de la consola
	vect *puntero; //Crear puntero para recorrer
	float prox; //Variable pde acumulador x
	float proy; //Variable pde acumulador y
	float proz; //Variable pde acumulador z
	float resx; //Variable de resultado de promedio x
	float resy; //Variable de resultado de promedio y
	float resz; //Variable de resultado de promedio z
			
	puntero = &cola.front(); //Almacenar diraccion del primer elemento en fila
	
	if(cola.size() == NULL) {
		//Imprimir mensaje para demostrar que no hay datos
		
		cout << "\t\t\t\t/ ###  No existen datos agregados a la cola  ### /" << endl;
	
	}
	else {
		for(int i = 1; i <= cola.size(); i++) { //Imprimir mientras existan elemenos
			n = *puntero; //Obtener dato del puntero
	    	prox = prox + n.x; //Acumular x
	    	proy = proy + n.y; //Acumular y
	    	proz = proz + n.z; //Acumulae z
	    			
	    	puntero++; //Pasar al siguiente elemento
		}
		resx = prox / cola.size(); //Promediar x
		resy = proy / cola.size(); //Promediar y
		resz = proz / cola.size(); //Promediar z
				
		//Imprimir resultados
		
		cout << "\t\t\t\t    Promedio de coordenada x = " << resx << endl; //Imprimir promedio x
		cout << "\t\t\t\t------------------------------------------" << endl;
		cout << "\t\t\t\t    Promedio de coordenada y = " << resy << endl; //Imprimir promedio y
		cout << "\t\t\t\t------------------------------------------" << endl;
		cout << "\t\t\t\t    Promedio de coordenada z = " << resz << endl; //Imprimir promedio z
		
	}
			
	system("pause"); //Pausar pantalla
	menu(n, cola); //Ejecutar funcion de menu para regresar
}
