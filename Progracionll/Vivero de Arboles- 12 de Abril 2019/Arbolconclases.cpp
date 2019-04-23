//HECHO POR ENRIQUE ANTONIO MENDEZ CACERES
//ULTIMA ACTUALIZACION 21/04/2019

#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

class Hoja 
{
	private:
		string forma ;
		float longitud ;
	public:
		Hoja()
		{
		this->forma= " ";
		this->longitud=0;
		}
		void setforma (string f)// forma
		{
		 this ->forma = f;
		}
		string getforma ()
		{
		 return this ->forma;
		}
		//////////////////////////////////////////
		void setlongitud (float l)//altura
		{
		 this ->longitud = 0;
		}
		float getlongitud ()
		{
		 return this ->longitud;
		}
};
/******************************************************************/
class Tallo 
{
	public :
		float longitud ;
		
		void setlongitud (float lo)
		{
			this -> longitud = 0;
		}
		float getlongitud ()
		{
			return this -> longitud ;
		}
};

class Arbol 
{     
	private :
		string nomComun ;
		string nomCient ;
		string familia ;
		Hoja hoja;  //agregacion
		Tallo *tallo; //composicion
	
	public  :
		~Arbol();
		

		Arbol ()      //constructor
		{
			this ->  nomComun ;
			this -> nomCient ;
			this -> familia ;
			this -> hoja ;
			this -> tallo = new Tallo ();
		}
	/******************************************************/
		Arbol (string a, string b, string c, Hoja d, Tallo e)
		{
			this ->  nomComun=a ;
			this -> nomCient=b ;
			this -> familia=c ;
			this -> hoja=d ;
			this -> tallo = new Tallo ();	
		}
	/**********************************************************/	
		void setnomComun (string a)//para nombre comun
		{
			this->nomComun=a;
		}
		string getnomComun ()
		{
		 return this ->nomComun;
		}
		/**********************************************************/
		void setnomCient (string b)//para nombre cientifico
		{
		 this ->nomCient =b;
		}
		string getnomCient ()
		{
		 return this ->nomCient;
		}
	/**********************************************************/
		void setfamilia (string c)//para la familia
		{
		 this ->familia =c;
		}
		string getfamilia ()
		{
		 return this ->familia;
		}
		
		/**********************************************************/
		void sethoja (Hoja d)//para la altura
		{
		 this ->hoja = d;
		}
		Hoja gethoja ()
		{
		 return this ->hoja;
		}
	  		

};	 
///////////destructor///////////////////
 

Arbol::~Arbol()
{
}
/////////////////////////////////////////////////////////////////	
class ArbolFrutal : public Arbol
{       
	void contarFrutos ()
	{
		cout << "Fruticas" << endl ;
	}
};
	
////////////////////////////////////////////////////////////////	
class ArbolOrnamental  : public Arbol
{      
	
};
//**************************************************************/

class Principal{
	public:
		Principal(){
		 
			cout<<"--------------ARBOL FRUTAL-------------"<<endl;
			ArbolFrutal *af=new ArbolFrutal;
			//af->setnomComun("TAMARINDO");
			cout<<"Nombre Comun: "<<af->getnomComun()<<endl;
			cout<<"Nombre cientifico: "<<af->getnomCient()<<endl;
			cout<<"Familia: "<<af->getfamilia()<<endl;
	

			cout<<"--------------ARBOL ORNAMENTAL-------------"<<endl;
			ArbolOrnamental *AO = new ArbolOrnamental;
			cout<<"Nombre comun: "<<AO<<endl;
			cout<<"Nombre cientifico: "<<AO<<endl;
			cout<<"Familia: "<<AO<<endl;
	
			
		}
};
/*******************************************************************************/
class Fabrica
{
	public:
		Arbol *crearArbol (int opc)      
		{ 
		switch (opc)
		{
		case 1:
		return new ArbolFrutal ();
		break;
		case 2:
			return new ArbolOrnamental ();
		}
		}
};

int main ()
{

	Fabrica *fab=new Fabrica();
	Arbol *a= fab->crearArbol(1);
	a->setnomComun("Tamarindo");
	cout<<a->getnomComun();
	Arbol *o= fab->crearArbol(2);
	o->setnomComun("Pino");
	cout<<endl <<"SISTEMA FUNCIONANDO"<<endl;
	system ("pause");
	return 0;

}
