// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

//Librerias
#include <iostream> 
#include <windows.h>

using namespace std; // simplificacion del codigo

void mayor(int &, int &); //Funcion de intercambio de numero mayor

int main() {
	system ("color 0A"); // color fondo/texto

	int z; //Variable de primer numero
	int x; //Variable de segundo numero
	
	
	
	cout << "Digite el primer numero (Valor (z): " << endl; //Pedir al usuario primer numero
	cin >> z; 
	

	cout << "Digite el segundo numero (Valor (x): " << endl; //Pedir al usuario segundo numero
	cin >> x; 
	

	mayor(z, x); //Ejecutar funcion 
	cout << "z = " << z << "   x = " << x << endl; //Imprimir valores finales de las variables


	system ("pause"); //Pausar pantalla 
	
	return 0; //Retornar a 0
}

void mayor(int &k, int &c) { //Funcion de intercambio de numero mayor
	int usb; //Variable que almacena temporalmente para hacer el intercambio
	
	if (k > c){ //Si el primer numero ingresado es mayor realizar intercambio
		usb = k; //temp almacena valor de la primera variable
		k = c; //y toma nuevo valor de la segunda variable
		c = usb; //z toma nuevo valor de la variable temporal
		//Imprimir mensaje del resultado del caso es mayor
		cout << "Como el primer numero ingresado es mayor se intercambian " << endl;
	}
	else {
		//Imprimir mensaje del resultado del caso no es mayor
		cout << "Como el primer numero ingresado no es mayor no se intercambian" << endl;
	}
}

