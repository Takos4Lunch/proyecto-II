#include <iostream>
#include "Handler.h"
#include "Alumno.h"
#include "Materia.h"
#include "Semestre.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	//Empezamos haciendo el menú
	Alumno h;
	Materia j;
	Semestre i;
	bool exit = false;
	int opc = 0;
	Handler x;
	cout<<"Bienvenido al programa"<<endl;
	cout<<"Ingrese la opción que desee ejecutar"<<endl;
	do{
		cout<<"1- Agregar materias o alumnos"<<endl;
		cout<<"2- Realizar inscripción"<<endl;
		cout<<"3- Consultar datos"<<endl;
		cout<<"4- Consultar inscripcion"<<endl;
		cout<<"5- Listado de inscritos en el semestre"<<endl;
		cout<<"6- Salir"<<endl;
		cin>>opc;
		switch(opc){
			case 1://Agregar materias o alumno
				h.load();
				j.load();
				i.load();
				break;
			case 2://Realizar inscripcion
			h.save(11112222,"Epale mi pana");
			j.save(777,"Momazaos momo","2");
			i.save(666,12345678);
				break;
			case 3://Consultar datos
				break;
			case 4://Consultar inscripción
				break;
			case 5://Listado de inscritos en el semestre
				break;
			case 6://Salir
				exit = true;
				break;
			default:
				cout<<"Debe ingresar un valor valido del 1 al 6"<<endl;
				opc = 0;
				break;
		}	
		system("pause");
		system("cls");
	}while(exit == false);
	return 0;
}
