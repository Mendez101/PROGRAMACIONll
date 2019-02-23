// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

//Librerias
#include <iostream> 
#include <windows.h>   
#include <stdio.h>
#include <conio.h>
#include <math.h>           

using namespace std; //simplificacion del codigo

void menorsteel() // simplificacion del codigo
{
	int na;  //variable para el primer numero
	int nb;     //variable para el segundo numero
	int *punta; //puntero
	
	cout << "Ingrese el primer numero: " << endl;
	cin >> na ;  //lectura de variable
	cout << "Ingrese el segundo numero: "   << endl ;
	cin >> nb ;    //lectura de variable
	
	if (na < nb )
	{
		 punta = &na ; //almacenamiento de tama;o en memoria del primer numero en el puntero
		 na = *punta ;//el primer numero sera el valor almacenado en el puntero
		 *punta = 0  ;
		 		 /*si el menor es el 1, se imprimira el valor en el puntero
		 y la simplemente impresion del numero mayor*/
		cout << "El numero menor es: " << *punta << endl ;
		cout << "El numero mayor es: " << nb << endl ;
	}
		else 
	{
		 punta = &nb ;//almacenamiento de tama;o en memoria del segundo numero en el puntero
		 nb = *punta ;//el segundo numero sera el valor almacenado en el puntero
		 *punta = 0 ;		 
		 		 /*si el menor es el 2, se imprimira el valor en el puntero
		 y la simplemente impresion del numero mayor*/
		cout << "El numero menor es: " << *punta << endl ;
		cout << "El numero mayor es: " << na << endl ;
	}
}
//Codigo principal
int main ()   

{    
system ("color 0A"); // color fondo/texto

	menorsteel () ; //llamada a funcion
	system ("pause") ;  //pausa
 	return 0;    //retorna 0
}  
		
	
