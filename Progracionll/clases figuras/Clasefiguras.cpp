//Hecho por Enrique Antonio Mendez Caceres

#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
class Figura  {

	private :
		float base ;
		float altura ; 
	public:
		Figura(){
				this ->base = 0;
				this ->altura = 0; 			
				}
		Figura (float a, float b) {
			this -> base =a;
			this ->altura = b;
}		
		void setbase (float b)//para la base 
		{
			this->base=b;
		}
		float getbase ()
		{
		 return this ->base;
		}
		
		void setaltura (float a)//para la altura
		{
		 this ->altura =a;
		}
		float getaltura ()
		{
		 return this ->altura;
		}
		
		virtual float area () = 0;
		virtual float perimetro () = 0;
		
};
/*class Color 
{
	public:
		void Colorear ()
		{
			cout << "estoy pintando" <<endl;
		}	
};*/
class Rectangulo: public Figura
{
	public :
	float area ()
	{
	 return getbase()*getaltura();
	}	
	float perimetro ()
	{
	 return 2*getbase ()+2*getaltura ();
	}
	void imprimirR ()
	{
	for (int i=0 ; i<getaltura (); i++)
	{
	cout << endl ;
	for (int j=0 ; j<getbase (); j++)
	cout << ("---\t") ;
	}
	}
};
class Cuadrado: public Figura
	{
		public :
		float area ()
		{
		 return getbase()*getaltura();
		}	
		float perimetro ()
		{ 
		 return 2*getbase ()+2*getaltura ();
		}
		void imprimirC ()
		{
			for (int i=0 ; i<getaltura (); i++)
			{
				cout << endl ;
				for (int j=0 ; j<getbase (); j++)
				cout << ("*") ;
			}
		}
	};
class Triangulo: public Figura
{
	public :
		float area ()
		{
		 return (getbase()*getaltura())/2;
		}	
		float perimetro ()
		{
		 return (getbase()*getaltura())/2; 
		}
		void imprimirT ()
		{
		 for (int i=1 ; i<=getaltura (); i++)
			{        
			for (int j=1 ; j<=getaltura()-1; j++)
			cout <<" " ;
		 	for (int j=1 ; j<=2*i-1 ; j++)
			cout << ("*") ;
			
			cout << endl ;
			}     
		}  
};
	

class Principal
{
	public:
	Principal ()
	{  
		   
		Rectangulo *r = new Rectangulo ();
		r->setbase (6);
		r->setaltura(4);
		cout <<r->getbase()<<" "<<r->getaltura()<<endl;
		cout <<"area:"<<r->area()<<endl;
		cout << "Rectangulo"<< endl;
		r-> imprimirR();
		cout << endl ;
		cout << endl ;
		/*******************************/
		Cuadrado *c = new Cuadrado ();
		c->setbase (7);
		c->setaltura(4);
		cout <<c->getbase()<<" "<<c->getaltura()<<endl;
		cout <<"area:"<<c->area()<<endl;
		cout << "Cuadrado"<< endl;
		c-> imprimirC();
		cout << endl ;
		cout << endl;
		/*******************************/
		Triangulo *t = new Triangulo ();
		t->setbase (5);
		t->setaltura(4);  
		cout <<t->getbase()<<" "<<t->getaltura()<<endl;
		cout <<"area:"<<t->area()<<endl;
		cout << "Triangulo"<< endl;
		t-> imprimirT();
		cout << endl ;
	}		
	
		
} ;

int main() {


	Principal *pro= new Principal();  
	getch(); 
	return 0;
}
//figura *t =new figura(0,0);
//t->setbase(4);
//cout<<t->getbase();

