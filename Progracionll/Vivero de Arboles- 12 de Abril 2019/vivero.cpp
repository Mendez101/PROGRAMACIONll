//HECHO POR ENRIQUE ANTONIO MENDEZ CACERES
//ULTIMA ACTUALIZACION 21/04/2019

#include <iostream>
#include <windows.h>
#include <string.h>
#include <queue>
#include<stdlib.h>

using namespace std;

//funcion menu para pedir las opciones en la consola
void menu ();

class Tallo{
	private:
		float alturaTallo;//altura del tallo
		float grosorTallo;//grosor del tallo;
	public:
		Tallo();
		void setaltTallo(float a){
			this->alturaTallo = a;
		}
		void setgroTallo(float g){
			this->grosorTallo = g;	
		}
		float getaltTallo(){
			return this->alturaTallo;
		}
		float getgroTallo(){
			return this->grosorTallo;
		}
		~Tallo();
};
Tallo::Tallo(){
}
Tallo::~Tallo(){
}


class Hoja{
	private:
		string formHoja;//forma de la hoja
		float tamHoja;//tamanio de la hoja
	public:
		Hoja();
		void setfmHoja(string fH){
			this->formHoja = fH;
		}
		void settmHoja(float tam){
			this->tamHoja = tam;
		}
		string getfmHoja(){
			return this->formHoja;
		}
		float gettmHoja(){
			return this->tamHoja;
		}
		~Hoja();	
};
Hoja::Hoja(){
}
Hoja::~Hoja(){
}

class Arbol:public Hoja, public Tallo{
	private:
		string nomComun;
		string nomCient;
		string familia;
		Hoja *formHoja;
		Hoja *tamHoja;
		Tallo *altTallo;
		Tallo *gTallo;
	public:
		Arbol();
		
		void setnombArbol(string n){
			this->nomComun = n;
		}
		void setnombCienArbol(string nCf){
			this->nomCient = nCf;
		}
		void setfamArbol(string f){
			this->familia = f;
		}

		///////////////////////////////////
		string getnombArbol(){
			return this->nomComun;
		}
		string getnombCienArbol(){
			return this->nomCient;
		}
		string getfamArbol(){
			return this->familia;
		}
		~Arbol();
};
Arbol::Arbol(){
}
Arbol::~Arbol(){
}

int main(){
	queue<Arbol> cola;
	Arbol *punt;
	Arbol a;
	Arbol *ingresoCola = new Arbol();
	Arbol Buscar ;
	string nComun;
	string nCient;
	string familia;
	string formHoja1;
	float tamHoja1;
	float alturaTallo1;
	float grosorTallo1;
	string dato ;
	int opc;
	char resp;
	//do while para que no introduzca un numero incorrecto en el menu
	do{
		//hacemos la llamada al menu
		menu();
		//capturamos la opcion seleccionada en opc
		cin>>opc;
		system("cls");
		//hacemos el debido procesamiento de las opciones el en menu siguiente
		switch(opc){
			//en el caso 1 pedimos los datos
			case 1:
				do 
				{
				cout<<"Ingrese el Nombre Comun del arbol:"<<endl;
				cin>>nComun;
				ingresoCola->setnombArbol(nComun);
				cout<<"Ingrese Nombre Cientifico del arbol:"<<endl;
				cin>>nCient;
				ingresoCola->setnombCienArbol(nCient);
				cout<<"Ingrese la familia a la que pertenece el arbol:"<<endl;
				cin>>familia;
				ingresoCola->setfamArbol(familia);
				cout<<"Introduzca la forma de la hoja: "<<endl;
				cin>>formHoja1;
				ingresoCola->setfmHoja(formHoja1);
				cout<<"Introduzca el tamanio de la hoja: "<<endl;
				cin>>tamHoja1;
				ingresoCola->settmHoja(tamHoja1);
				cout<<"Introduzca la altura del tallo: "<<endl;
				cin>>alturaTallo1;
				ingresoCola->setaltTallo(alturaTallo1);
				cout<<"Introduzca el grosor del tallo: "<<endl;
				cin>>grosorTallo1;
				ingresoCola->setgroTallo(grosorTallo1);
				
				cola.push(*ingresoCola);
				//mensaje que indica que se guardaron satisfactoriamente
				cout<<"Datos almacenados con exito!..."<<endl;
				cout<<"Desea agregar otro arbol? y/n"<<endl;
				cin>>resp;
				system ( "cls" ) ;      //limpiar
			}while (resp == 'y' || resp == 'Y'); 
				system("pause");
				
				system("cls");
			break;

			case 2:
						if(cola.empty() == true){
					cout<<"La lista esta vacia..."<<endl;
				}
				else{
					punt = &cola.front();
					for(int i=1; i<=cola.size(); i++){
						a = *punt;
						cout<<"Nombre del arbol: "<<a.getnombArbol()<<endl;
						cout<<"Nombre cientifico: "<<a.getnombCienArbol()<<endl;
						cout<<"Familia: "<<a.getfamArbol()<<endl;
						cout<<"Forma de la hoja: "<<a.getfmHoja()<<endl;
						cout<<"Tamanio de la hoja: "<<a.gettmHoja()<<" cm"<<endl;
						cout<<"Altura del tallo: "<<a.getaltTallo()<<" mts"<<endl;
						cout<<"Grosor del tallo: "<<a.getgroTallo()<<" cm"<<endl;
						cout<<endl;
						punt++;
					}
				}
				system("pause");
				system("cls");
			break;

			case 3:
				system ("pause");
    			
    			if(cola.empty() == true){
					cout<<"La lista de arboles esta vacia..."<<endl;
				}
				else{
					cout<<"Ingrese Arbol a buscar: "<<endl;
					cin>>dato;
					punt = &cola.front();
					for(int i=1; i<=cola.size(); i++){
				a = *punt;
						if(dato == (a.getnombArbol ()) ){
							cout<<"Encontrado..."<<endl;
							cout<<"El arbol es : "<<endl;
						cout<<"Nombre del arbol: "<<a.getnombArbol()<<endl;
						cout<<"Nombre cientifico: "<<a.getnombCienArbol()<<endl;
						cout<<"Familia: "<<a.getfamArbol()<<endl;
						cout<<"Forma de la hoja: "<<a.getfmHoja()<<endl;
						cout<<"Taman?o de la hoja: "<<a.gettmHoja()<<" cm"<<endl;
						cout<<"Altura del tallo: "<<a.getaltTallo()<<" mts"<<endl;
						cout<<"Grosor del tallo: "<<a.getgroTallo()<<" cm"<<endl;
						cout<<endl;
						}
						else{
							cout<<"No se ha podido encontrar el arbol. "<<endl;
						}
						
					}
					punt++;
				}
				punt = &cola.front(); 
				system ("pause");
			break;
			
			case 4:
				if(cola.empty() == true ){
    				cout<<"La lista esta vacia..."<<endl;
				}
				else{
					cola.pop();
					cout<<"El ultimo cliente ingresado ha sido eliminado exitosamente de la lista..."<<endl;
   				}	
			break;
		}
		system("cls");
	}while(opc!=5);
	
	return 0;
}

void menu(){
	system ("color 0A" );
    cout << "\t\t\t\t|------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t|                     BIENVENIDOS                            |" << endl;
    cout << "\t\t\t\t|------------------------------------------------------------|" << endl;
	cout << "\t\t\t\t|         1 - Agregar nuevo arbol.                           |" << endl;
    cout << "\t\t\t\t|         2 - Listar arboles en existencia.                  |" << endl;
    cout << "\t\t\t\t|         3 - Buscar un arbol.                               |" << endl;
    cout << "\t\t\t\t|         4 - Eliminar un arbol.                             |" << endl;
    cout << "\t\t\t\t|         5 - Salir                                          |" << endl;
    cout << "\t\t\t\t|------------------------------------------------------------|" << endl;
}
