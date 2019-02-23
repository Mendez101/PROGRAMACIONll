// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

//Inversion de cadena

//librerias 
#include <iostream> //Libreria de entradas y salidas
#include <stdio.h>
#include <conio.h>
//Definir variables a utilizar
char cadena [5];
char *punta;//Puntero

using namespace std; //Simplificacion del codigo
//Desarrollo el codigo
int main ()
{
system ("color 0A"); // color fondo/texto

//Solisitar ingresar datos	
printf("ingrese su cadena a invertir : " );
gets(cadena);
//Mostar resultados en pantalla
cout << "---------------------------------- " << endl ;
cout << "Forma Inversa: " << endl ;
//Imprimir la misma cadena por partes
for(int i=4; i>=0 ;i--){
	punta=&cadena[i];
	printf ("%c",*punta);//Impresion de caracter
}
	
	getch(); //retorna el carácter leído desde el teclado
	return 0; //Retorna 0


}
