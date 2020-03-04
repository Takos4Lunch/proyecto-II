#include <iostream>
#include "Handler.h"
#include "Alumno.h"
#include "Materia.h"
#include "Semestre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	//Empezamos haciendo el menú
	Alumno h;//Utilizaremos estos para guardar los demás
	Materia j;
	Semestre i;
	bool exit = false;
	int opc = 0;
	Handler x;
	Alumno **alm;
	int contalm = 0;
	Materia **matr;
	int contmtr = 0;
	Semestre **smtr;
	int contsmtr = 0;
	
	alm = new Alumno*[100];
	matr = new Materia*[100];
	smtr = new Semestre*[100];
	
	h.load(alm,contalm);
	j.load(matr,contmtr);
	i.load(smtr,contsmtr);
	
	//Con todo cargado, procedemos a hacer todo
	
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
			{
				cout<<"¿Que desea agregar?"<<endl;
				int value = 0;
				do{
					cout<<"1- Materia"<<endl;
					cout<<"2- Alumno"<<endl;
					
					cin>>value;	
					if(value>2 || value<1){
						cout<<"Ingrese una opcion valida"<<endl;
					}
				}while(value>2 || value<1);
				
				if(value==1){
					cout<<"Ingrese el codigo de la materia (3 digitos)"<<endl;
					int codigo = 0;
					char nombr[80];
					do{
						cin>>codigo;
						if(codigo>999 || codigo<100){
							cout<<"Ingrese un valor valido"<<endl;
						}
					}while(codigo>999 || codigo<100);
					cout<<"Ahora, ingrese el nombre de la materia(máximo 80 caracteres"<<endl;
					cin>>nombr;
					cout<<"Por ultimo, ingrese la cantidad de unidades de crédito (de 1 a 4)"<<endl;
					int uncred = 0;
					char ucred[0];
					do{
						cin>>ucred;
						uncred = atoi(ucred);
						if(uncred>4 || uncred<1){
							cout<<"Ingrese un valor valido"<<endl;
						}
					}while(uncred>4 || uncred<1);
				
					//Teniendo todo eso, guardamos
					j.save(codigo,nombr,ucred,matr,contmtr);//Listo
				}else{
					
				}
			}
				
				
				break;
			case 2://Realizar inscripcion
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
