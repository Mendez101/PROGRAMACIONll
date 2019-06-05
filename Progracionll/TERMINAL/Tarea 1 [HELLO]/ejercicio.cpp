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

class Cliente : public Fl_Window{
Fl_Window *window;
Fl_Box *box;
Fl_Button *boton;
Fl_Button *boton2;
Fl_Input *input_Cod;
Fl_Input *input_Nom;
Fl_Input *input_Ape;
Fl_Input *input_Gen;
Fl_Round_Button *botonGenero;
public:
Cliente ():Fl_Window(470,400, "Cliente"){
 	begin(); 
	box = new Fl_Box(100,40,260,100,"Clientes!");
	box->box(FL_ROUNDED_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_NORMAL_LABEL);
	box->labelcolor (FL_MAGENTA);
	boton = new Fl_Button(50, 350, 150, 45, "Guardar");
	boton2 = new Fl_Button(250, 350, 150, 45, "Cancelar");
	boton->labelcolor(FL_MAGENTA);
	boton->color(FL_BLACK);
	boton2->labelcolor(FL_MAGENTA);
	boton2->color(FL_BLACK);
	
	input_Cod = new Fl_Input(156, 150, 150, 20, "  Codigo: ");
	input_Cod->value();
	input_Cod->labelcolor(FL_MAGENTA);
	input_Nom = new Fl_Input(156, 200, 150, 20, "  Nombre: ");
	input_Nom->value();
	input_Nom->labelcolor(FL_MAGENTA);
	input_Ape= new Fl_Input(156, 250, 150, 20, "  Apellido: ");
	input_Ape->value();
	input_Ape->labelcolor(FL_MAGENTA);
	input_Gen= new Fl_Input(156, 325, 0, 0, "  Genero: ");
	input_Gen->labelcolor(FL_MAGENTA);
	botonGenero = new Fl_Round_Button (155,326,40,20,"F");
	botonGenero = new Fl_Round_Button (200,326,40,20,"M");
	
	boton->callback(Guardar_CB,(void*)this);
	boton2->callback(Cancelar_CB,(void*)this);
	end();
}

static void Guardar_CB(Fl_Widget *w,void *data)
{
	Cliente *e = (Cliente*)data;
	if (e->Guardar("temp.txt") == 0)
	{
   	    fl_message( "Datos almacenados");
	}
	else
	{
	   fl_message("Error");
	}

} 
////////////////////////////////////////////
static void Cancelar_CB(Fl_Widget *w,void *data)
{
	Cliente *e = (Cliente*)data;
	e->hide() ;//cerrar formulario 
//limpiar
// input ->value (" ")

}
///////////////////////////////////////////////
void SetCodigo (const char *val)
{
	input_Cod->value (val);
}

const char *GetCodigo () const
{
	return input_Cod->value ();
}
//************************************+++
void SetNombre (const char *val1)
{
	input_Nom->value (val1);
}

const char *GetNombre () const
{
	return input_Nom->value ();
}
//****************************************
void SetApellido (const char *val2)
{
	input_Ape->value (val2);
}

const char *GetApellido () const
{
	return input_Ape->value ();
}
//*************************************
void SetGenero (const char *val2)
{
	input_Gen->value (val2);
}

const char *GetGenero () const
{
	return input_Gen->value ();
}
///////////////////////////////////////////
int Guardar(const char *filename)
 {
        FILE *fp = fopen(filename, "w");
        if ( !fp ) {
            fl_message("%s:  %s", filename, strerror(errno));
            return -1;
        }
        fprintf(fp, "Codigo:  %s \nNombre: %s \nApellido: %s  \nGenero: %s \n\n",
	 input_Cod->value(), input_Nom->value(), input_Ape->value(), (botonGenero ->value()==0)? "F" : "M");
	
       
        fclose(fp);
        return 0;
    }
};

int main(int argc, char** argv){
	Cliente*e=new Cliente();
	
	e->show(argc,argv);
	return Fl::run();
	
}
