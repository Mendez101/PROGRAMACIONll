//Programa desarrollado por Enrique Antonio Mendez Caceres
//MC18082
	

#include <iostream> //Libreria de entradas y salidas
#include <stdlib.h> //Libreria de funciones agregadas

using namespace std; //Simplificacion del codigo


class Paciente{ //Case para pacientes
    private: //Parametro privados
    	     int cor; //Numero de correlativo
    	     char nom[20]; //Nombre del paciente
    	     char ape[20]; //Apellido del paciente
			 int edad; //Edad del paciente
			 char s[2]; //Sexo del paciente
			 char ec[50]; //Enfermedad cronica
    public: //Parametros publicos
    	  Paciente(); //Entidad del paciente
    	  void Mostrar(); //Funcion de mostrar pacientes
    	  void Pedir(); //Funcion para pedir datos de paciente
    	  ~Paciente(); //Destructor
    	
};

Paciente::Paciente() //Crear entidad de paciente
{

}
Paciente::~Paciente() //Destruir entidad de paciente
{

}

void Paciente::Mostrar() { //Funcion para mostrar pacientes
	system("cls"); //Limpiar pantalla de la consola
	cout << "\t\t\t\t//////////////////////////////////////////////" << endl;
	cout << "\t\t\t\t\tCorrelativo: " << cor << endl; //Imprimir
	cout << "\t\t\t\t\tNombre:" << nom << endl; //Imprimir
	cout << "\t\t\t\t\tApellido:" << ape << endl; //Imprimir
	cout << "\t\t\t\t\tEdad:" << edad << endl; //Imprimir
	cout << "\t\t\t\t\tSexo:" << s << endl; //Imprimir
	cout << "\t\t\t\t\tEnfermedad cronica:" << ec << endl; //Imprimir
	cout << "\t\t\t\t//////////////////////////////////////////////" << endl << endl;
}

void Paciente::Pedir() { //Funcion para pedir datos de paciente
	system("cls"); //Limpiar pantalla de la consola

	cout << "\t\t\t\t Ingrese Correlativo: ";
	cin >> cor;
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t Ingrese nombre: ";
	cin >> nom;
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t Ingrese apellido: ";
	cin >> ape;
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t Ingrese edad: ";
	cin >> edad;
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t Ingrese sexo: ";
	cin >> s;
	cout << "\t\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t\t Ingrese enfermedad c: ";
	cin >> ec;

	system("pause");
}

int tomarINT(); //Funcion para tomar enteros
bool validINT(string); //Funcion para validar enteros
void menu(); //Funcion para menu de opciones

int main(int argc, char** argv) {
	menu();
	
	return 0;
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
			menu(); //Reiniciar menu
		}
	}
	
	return atoi(numero.c_str()); //Convertir string a int y regresar numero
}

void menu() { //Funcion de menu
	retorno:
	system("cls"); //Limpiar pantalla de consola
	int opc; //Variable para almacenar opciones de menu
	Paciente *p1;
	Paciente *p2;
	
	do {
		system("color 02"); //Cambiar colores, fondo turquesa, texto blanco
	    cout << endl << endl << endl << endl << endl; //Espacios de linea
	    //Imprimir menu de opciones en pantalla
		
	    cout << "                     MENU              " << endl;
	    cout << "                                       " << endl;
	    cout << "        1. Agregar datos de pacientes  " << endl;
	    cout << "        2. Mostrar datos de pacientes  " << endl;
	    cout << "        3. Salir                       " << endl;
	    
		cout << "Digite la opcion: "; //Mensaje para pedir ingreso de opcion
	    opc = tomarINT(); //Tomar dato y validar entrada
	}while(opc < 1 || opc > 3); //Mientras se ingrese uno de los numeros correspondientes
	
	switch(opc) {
		case 1: //Ingresar pacientes
			p1=new Paciente();
			p1->Pedir();
			p2=new Paciente();
			p2->Pedir();
			p1->Mostrar();
			p2->Mostrar();
			goto retorno; //Regrsar al menu
			
		case 2: //Mostrar pacientes
			
			goto retorno; //Regrsar al menu
			
		case 3: //Salir del menu
			break; //Terminar proceso
	}
}
