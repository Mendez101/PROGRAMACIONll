// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019


//Librerias
#include <iostream> 
#include <conio.h> 
#include <math.h> 

using namespace std; // simplificacion del codigo

//Funciones
void area(float *, float *, float *); 

//Inicio codio principal
int main()
{
	system ("color 0A"); // color fondo/texto

    
	//Definicion de variables
	float arista; //Variable de almacenar arista
    float a; //Variable para almacenar area del cuadrado
    float b; //Variable para almacenar area del cubo
    


    cout << "Digite la  arista (lado): " << endl; //Pedir ingreso de un valor a la arista
    cin >> arista; //Agregar dato a la variable indicada
    
    
    //Inicar condicion de no permitir numeros iguales o menores de cero
	while(arista <= 0) {
		cout << "Error, la arista debe ser mayor a cero" << endl; //Mostrar mensaje de error
		cout << "Intentelo de nuevo arista: " << endl; //Pedir ingreso de un valor a la arista
		cin >> arista; //Ingresar dato a la variable
		
	}
    area(&arista, &a, &b); //Ejecutar funcion
   
   
    //Imprimir resultado del area de un cuadrado
    cout << "El area de un cuadrado segun el lado ingresado es: " << a << endl;
   
   
   
    //Imprimir resultado del area de un cubo
	cout << "El area de un cubo segun el lado ingresado es: " << b << endl << endl;
	
    system("pause"); //Pausar pantall de la consola

    return 0; //Retornar valores a cero
}


//funciones
void area(float *lado, float*x, float *y) {
	*x = *lado * *lado; //Operacion para obtener area del cuadrado
	
	*y = 6 * (*lado * *lado); //Operacion para obtener el area de un cubo
}
