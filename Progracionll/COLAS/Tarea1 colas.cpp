//Hecho por Enrique Antonio Mendez
 
//librerias
#include <iostream>
#include <conio.h>
#include <stdlib.h>//Libreria para poder usar new y delete 

using namespace std;

struct ICO{
	char tk[5];
	char nc[5];
	int edad;
};

struct Nodo{
	ICO banca;
	Nodo *siguiente;
};
//Insertar elementos a l cola 
void menu();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&,Nodo *&,ICO);
bool c_vacia(Nodo *);

int main(){
	ICO banca;
	Nodo *frente=NULL;
	Nodo *fin=NULL;
	char opcion;
	
	do{
		retorno:
		menu();
		cin>>opcion;
		fflush(stdin);
		Nodo *aux=frente;
		switch(opcion){
			case '1':
				system("cls");
				agregarDatos(banca);
				insertarDatos(frente,fin,banca);
				goto retorno;
			case '2':
				cout<<"TiKet"<<"\tNumeroCuenta\t\t\t"<<"Edad "<<endl;
				while(aux !=NULL){
					cout<<aux->banca.tk<<"\t"<<aux->banca.nc<<"\t\t\t"<<aux->banca.edad<<endl;
					aux=aux->siguiente;
				}
				break;
			case '3':
				cout<<"\nSalio del programa..."<<endl;
				break;
			default:
				cout<<"\nOpcion invalida "<<endl;
				break;
		}
		cout<<"Presionar una tecla para continuar"<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
	return 0;
}

void menu(){
	cout<<"MENU"<<endl
	    <<"1.Agregar datos del Ahorrante"<<endl
	    <<"2.Mostrar datos de los ahorrantes"<<endl
	     <<"3.Salir del programa"<<endl
	    <<"Ingresar el numero de opcion que desea: ";
}

void agregarDatos(ICO &banca){
	cout<<"Ingresar tiket del ahorrante: "; cin.getline(banca.tk,5,'\n');
    
	cout<<"Ingresar numero de cuenta del ahorrante: "; cin.getline(banca.nc,5,'\n');
	 
	cout<<"Ingresar edad: "; cin>>banca.edad;
}

//Insertando elementos a ala cola
void insertarDatos(Nodo *&frente, Nodo *&fin,ICO banca){
	Nodo *n_nodo=new Nodo();//declarando un nuevo nodo 
	
	n_nodo->banca=banca;//asignando al nuevo nodo el dato a insertar en la cola
	//siguiente apunta directamente hacia null
	n_nodo->siguiente=NULL;
	
	if(c_vacia(frente)){
		frente = n_nodo;//si la cola esta vacia frente = nuevo nodo
	}
	else{
		fin->siguiente=n_nodo;//si la cola no esta vacia 
	}
	
	fin=n_nodo;
}
//determina si la cola esta vacia 
bool c_vacia(Nodo *frente){
	//si frente igual a null cola vacia retornar true
	return (frente==NULL)? true : false;
}
