// Creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de Actualizacion: 22/02/2019

	//Ejercicio 1 de la pagina 4

#include <iostream> 

using namespace std; 

void DemoLocal(int valor) {
	cout <<  "Dentro de DemoLocal, valor =" << valor << endl; 
	valor = 75; 
	cout << "Dentro de DemoLocal, valor =" << valor << endl; 
}


int main(void) {
	int n = 10; 
	cout << "Antes de llamar a DemoLocal, n= " << n << endl; 
	DemoLocal(n); 
	cout << "Despues de llamar a DemoLocal, n= " << n << endl; 
	cout << "Pulse Intro para continuar"; 
	cin.get(); 
	
	return 0; 
}
