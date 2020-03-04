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
	
	cout<<"Alumnos :"<<contalm<<endl;
	cout<<"Materias :"<<contmtr<<endl;
	cout<<"Inscripciones :"<<contsmtr<<endl;
	
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
					char nombr[80];
					int codigo = 0;
					
					do{
						fflush(stdin);
						cin>>codigo;
						cout<<codigo<<endl;
						if(codigo>999 || codigo<1){
							cout<<"Ingrese un valor valido"<<endl;
						}
					}while(codigo>999 || codigo<1);
					cout<<codigo<<endl;
					int helper = codigo;
					cout<<"Ahora, ingrese el nombre de la materia(máximo 80 caracteres)"<<endl;
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
					cout<<"Codigo"<<codigo;
					j.save(helper,nombr,ucred,matr,contmtr);//Listo
				}else{
					//Alumno
					cout<<"Ingrese la cedula del alumno (8 caracteres)"<<endl;
					int cedula = 0;
					do{
						cin>>cedula;
						if(cedula>99999999 || cedula<10000000){
							cout<<"Ingrese un valor valido"<<endl;
						}
					}while(cedula>99999999 || cedula<10000000);
					cout<<"Ahora, ingrese el nombre del estudiante(30 caracteres)"<<endl;
					char nombr[30];
					fflush(stdin);
					cin.getline(nombr,sizeof(nombr));
					h.save(cedula,nombr,alm,contalm);//listo
				}
			}
				
				
				break;
			case 2://Realizar inscripcion
				{
					cout<<"Ingrese la cedula del alumno(8 caracteres)"<<endl;
					//Hay que verificar si la cedula existe
					int cedula = 0;
					do{
						cin>>cedula;
						if(cedula>99999999 || cedula<10000000){
							cout<<"Ingrese un valor valido"<<endl;
						}
					}while(cedula>99999999 || cedula<10000000);
					
					bool existe = false;
					for(int x = 0;x<contalm;x++){
						if(cedula==alm[x]->ced){
							existe = true;
							cout<<"Fue encontrado"<<endl;
						}
					}
					
					cout<<"Ahora, ingrese el codigo de la materia(3 caracteres)"<<endl;
					
					int codigo = 0;
					
					do{
						cin>>codigo;
						if(codigo>999 || codigo<1){
							cout<<"Ingrese un valor valido"<<endl;
						}
					}while(codigo>999 || codigo<1);
					
					bool codexiste = false;
					for(int x = 0;x<contmtr;x++){
						if(codigo==matr[x]->cod){
							codexiste = true;
							cout<<"Fue encontrad2"<<endl;
						}
					}
					
					if(existe==true && codexiste==true){
						cout<<"Existen"<<endl;
						i.save(codigo,cedula,smtr,contsmtr);
					}else{
						
					}
					
				}
				break;
			case 3://Consultar datos
				{
					cout<<"¿Que desea consultar?"<<endl;
				int value = 0;
				do{
					cout<<"1- Materia"<<endl;
					cout<<"2- Alumno"<<endl;
					
					cin>>value;	
					if(value>2 || value<1){
						cout<<"Ingrese una opcion valida"<<endl;
					}
				}while(value>2 || value<1);
				
					if(value==1){//Materia
						cout<<"Ingrese el codigo de la materia"<<endl;
						int codigo = 0;
						do{
							cin>>codigo;
							if(codigo>999 || codigo<1){
								cout<<"Ingrese un valor valido"<<endl;
							}
						}while(codigo>999 || codigo<1);
						
						bool codexiste = false;
						for(int x = 0;x<contmtr;x++){
							if(codigo==matr[x]->cod){
								codexiste = true;
								matr[x]->print();
							}
						}
						
						if(codexiste == false){
							cout<<"No existe la materia"<<endl;
						}
						
					}else{//Alumno
						cout<<"Ingrese la cedula del alumno(8 caracteres)"<<endl;
						//Hay que verificar si la cedula existe
						int cedula = 0;
						do{
							cin>>cedula;
							if(cedula>99999999 || cedula<10000000){
								cout<<"Ingrese un valor valido"<<endl;
							}
						}while(cedula>99999999 || cedula<10000000);
						
						bool existe = false;
						for(int x = 0;x<contalm;x++){
							if(cedula==alm[x]->ced){
								existe = true;
								alm[x]->print();
							}
						}
						
						if(existe==false){
							cout<<"No existe el alumno"<<endl;
						}
					}	
				
				}
				break;
			case 4://Consultar inscripción
				{
					cout<<"Ingrese la cedula del alumno(8 caracteres)"<<endl;
						//Hay que verificar si la cedula existe
						int cedula = 0;
						do{
							cin>>cedula;
							if(cedula>99999999 || cedula<10000000){
								cout<<"Ingrese un valor valido"<<endl;
							}
						}while(cedula>99999999 || cedula<10000000);
					bool existe = false;
					for(int x = 0;x<contalm;x++){
							if(cedula==alm[x]->ced){
								existe = true;
								alm[x]->print();
							}
						}	
					bool inscribio = false;
					if(existe==false){
						cout<<"No se encuentra el alumno"<<endl;
					}else{
						
						for(int x = 0;x<contsmtr;x++){
							if(cedula==smtr[x]->ced){
								for(int y = 0;y<contmtr;y++){
									if(smtr[x]->cod==matr[y]->cod){
										matr[y]->print();
									}
								}
							}
						}
					}
					
					if(inscribio==false){
						cout<<"Este alumno no inscribio materias"<<endl;
					}
					
				}
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
