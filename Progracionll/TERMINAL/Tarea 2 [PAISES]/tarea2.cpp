#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Input.H>
#include<FL/fl_message.H>
#include<string.h>
#include <FL/Fl_Round_Button.H>
#include <stdio.h>
#include <errno.h>
#include<time.h>
#include <cstdlib>
#include<string.h>


	const char* Pais [16] = {"Canada", "Arabia Saudita", "Belice", "Bulgaria", 
                                "Colombia", "Cuba", "Ecuador", "España", 
                                "Estados Unidos", "Francia", "Israel", "Japon","Peru",
				"Republica Dominicana","Rusia"};
	
	const char* Capi [16] = {"Ontario", "Riad", "Belmopan", "Sofia", 
                                "Bogota", "La Habana", "Quito", "Madrid", 
                                "Washington D. C.", "Paris", "Jerusalen","Tokio","Lima",
				"Santo Domingo", "Moscu"};
int tamaPais = 16;
////////////////////////////////////////////////
class Cliente : public Fl_Window{
Fl_Window *window;
Fl_Box *box;
Fl_Button *boton1;
Fl_Button *boton2;
Fl_Button *boton3;
Fl_Button *boton4;
Fl_Button *boton5;


public:
Cliente ():Fl_Window(475,400, "Paises y sus capitales"){
 	begin(); 
	box = new Fl_Box(100,40,260,100,"Bienvenidos");
	box->box(FL_ROUNDED_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_NORMAL_LABEL);
	box->labelcolor (FL_MAGENTA);
///////////////////////////////////////////////////77
	srand(time(0));
////////////////////////////////////////////////////
	int primeroPais = rand () %tamaPais-1 ;
	const char* Pais1 = Pais[primeroPais];
	const char* Capi1 = Capi[primeroPais];
	boton1= new Fl_Button(40, 100, 150, 45, Pais1);
//+++++++++++++++++++++++++++++++++++++++++++++++++++
	int segundoPais = rand () %tamaPais-2 ;
	const char* Pais2 = Pais[segundoPais];
	//const char* Capi1 = Capi[primer
	boton2 = new Fl_Button(300, 100, 150, 45, Pais2);
//+++++++++++++++++++++++++++++++++++++++++++++++++++
	int tercerPais = rand () %tamaPais-3 ;
	const char* Pais3 = Pais[tercerPais];
	//const char* Capi1 = Capi[primero];
	boton3= new Fl_Button(175, 200, 150, 45, Pais3);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int cuartoPais = rand () %tamaPais-4 ;
	const char* Pais4 = Pais[cuartoPais];
	//const char* Capi1 = Capi[primero];
	boton4 = new Fl_Button(40, 300, 150, 45, Pais4);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int quintoPais = rand () %tamaPais-5 ;
	const char* Pais5 = Pais[quintoPais];
	//const char* Capi1 = Capi[prime	
	boton5= new Fl_Button(300, 300, 150, 45, Pais5);
//++++++++++++++++++++++++++++++++++++++++++++++++++++
	boton1->labelcolor(FL_MAGENTA);
	boton1->color(FL_WHITE);
	boton2->labelcolor(FL_MAGENTA);
	boton2->color(FL_WHITE);
	boton3->labelcolor(FL_MAGENTA);
	boton3->color(FL_WHITE);
	boton4->labelcolor(FL_MAGENTA);
	boton4->color(FL_WHITE);
	boton5->labelcolor(FL_MAGENTA);
	boton5->color(FL_WHITE);
	boton1->callback(Pais_CB,(void*)this);
	boton2->callback(Pais_CB,(void*)this);
	boton3->callback(Pais_CB,(void*)this);
	boton4->callback(Pais_CB,(void*)this);
	boton5->callback(Pais_CB,(void*)this);
	end();
//++++++++++++++++++++++++++++++++++++++++++++++++++++
}
static void Pais_CB(Fl_Widget *w,void *data)
{
	
   	 if(strcmp(w->label(), "Canada") == 0)
	{
          fl_message("Ontario");
     	 }
	else if (strcmp(w->label(), "Arabia Saudita") == 0)
	{
		fl_message("Riad");
	}
	else if (strcmp(w->label(), "Belice") == 0)
	{
		fl_message("Belmopan");
	}
	else if (strcmp(w->label(), "Bulgaria") == 0)
	{
		fl_message("Sofia");
	}
	else if (strcmp(w->label(), "Colombia") == 0)
	{
		fl_message("Bogota");
	}
	else if (strcmp(w->label(), "Cuba") == 0)
	{
		fl_message("La Habana");
	}
	else if (strcmp(w->label(), "Ecuador") == 0)
	{
		fl_message("Quito");
	}
	else if (strcmp(w->label(), "España") == 0)
	{
		fl_message("Madrid");
	}
	else if (strcmp(w->label(), "Estados Unidos") == 0)
	{
		fl_message("Washington D. C.");
	}
	else if (strcmp(w->label(), "Francia") == 0)
	{
		fl_message("Pais");
	}
	else if (strcmp(w->label(), "Israel") == 0)
	{
		fl_message("Jerusalen");
	}
	else if (strcmp(w->label(), "Japon") == 0)
	{
		fl_message("Tokio");
	}
	else if (strcmp(w->label(), "Peru") == 0)
	{
		fl_message("Lima");
	}
	else if (strcmp(w->label(), "Republica Dominicana") == 0)
	{
		fl_message("Santo Domingo");
	}
	else if (strcmp(w->label(), "Rusia") == 0)
	{
		fl_message("Moscu");
	}
} 
////////////////////////////////////////////

};



int main(int argc, char** argv){
	Cliente*e=new Cliente();
	e->show(argc,argv);
	e->color(FL_BLACK);
	return Fl::run();
	
}
