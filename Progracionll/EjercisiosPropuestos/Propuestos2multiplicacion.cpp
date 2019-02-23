// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

//librerias
#include <iostream> 
#include <windows.h>
#include <math.h>

using namespace std; //simplificacion del codigo

//funcion a utilisar
void axb(float &); 

//inicio del programa
int main() 
{
	system ("color 0A"); // color fondo/texto

	float a; //Variable de numero 
	
	
	//Pedir ingreso de numero a multiplicar por 10
	cout << "Ingrese un numero para multiplicar por 10:" << endl;
	cin >> a; //Agregar dato ingresado a la variable
	
	axb(a); //Ejecutar funcion de multiplicacion
	
	//Imprimir  resultados
	cout << "Resultado de la multiplicacion por 10:" << endl;
	cout << a << endl; //Mostrar variable modificada por la multiplicacion
	
	
	system("pause"); //Pausar 
	
	return 0; //Retornar 0
}

//Funcion axb
void axb(float &b) {
	float x = 10; //Variable para almacenar valor con el que se multiplicara
	 
	b = b * x; //Realizar multiplicacion y almacenar en variable
}
