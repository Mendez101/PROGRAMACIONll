// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

//librerias
#include <iostream> 
#include <windows.h>   
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

//Funcion
int Diva ()
{
	system ("color 0A"); // color fondo/texto

	//Definir variables
     
	double t ;   //Total 
	double *x ; //Resultado
	double y ;  //base  
	int F ;     //Numero   
	
	x = &y ;    ////almacenamiento e el puntero de la memoria de la variable 
	y = *x ; //bas igualada al puntero
	
	cout << "Ingrese base: ";
	cin >> y ; //lectura de variable
	cout << endl << "Ingrese la potencia:";
	cin >> F ;   //lectura de variable

	/*la variable total hacemos el proceso
	matematico que se nos pide*/
	t = pow (y, F);
	
	cout << "El resultado de " << y << " elevado a la " << F << " es: " << t << endl;
 	return t ;              //retorna el valor total
}

//principal funcion
//inicio del codigo
int main ()   

{           
		Diva ();   //llamada de funcion
	
	system ("pause");  //pausa
 	return 0;         //no retorna ningun valor
}  	
	
