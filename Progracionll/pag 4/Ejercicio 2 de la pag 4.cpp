// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

	//Ejercicio 2 de la pag 4/5

#include <stdio.h> 
#include <conio.h> 


void Intercambio(int, int); 
void Intercambio(int *, int *); 
void Intercambio(int, int &, int &); 

int main() {
	int x = 22, y = 33; 
	printf("x = %d\t y = %d\n", x, y);
	Intercambio(x,y); 
	printf("x = %d\t y = %d\n", x, y); 
	Intercambio(1, x, y); 
	printf("x = %d\t y = %d\n", x, y); 
	Intercambio(&x, &y);
	printf("x = %d\t y = %d\n", x, y); 
	getch(); 
	return 0; 
}


void Intercambio(int a, int b) { 
	int aux; 
	aux = a; 
	a = b; 
	b = aux; 
}

void Intercambio(int *a, int *b) { 
	int aux; 
	aux = *a; 
	*a = *b; 
	*b = aux; 
}

void Intercambio(int i, int &a, int &b) { 
	int aux = i; 
	aux = a; 
	a = b; 
	b = aux; 
}
