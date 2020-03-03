#include "Alumno.h"
#include <iostream>
#include <cstdlib>

Alumno::Alumno(){
	
}

void Alumno::save(){
	char x[8];
	y.open("Datos.dat",ios::binary | ios::out);
	y.read(x,8);
	for(int i = 0; i < 8; i++){
		cout<<x[i];	
	}
	cout<<endl;
	y.close();
}

void Alumno::load(){//Quizas debería pasarle un array de alumnos para que los guarde
	
	int p = 11111111;
	char x[sizeof(p)];
	char temp[30];
	int sav = 0;
	int placeholder;
	y.open("Datos.dat",ios::binary | ios::in);
	do
	{
		y.read((char *)&sav,sizeof(p));
		y.read((char *)&temp,sizeof(temp));
		y.read((char *)&placeholder,2);//Despues de cada salto de linea hay 2 bytes
		cout<<sav<<endl;
		cout<<temp<<endl;	
	}while(!y.fail());
	y.close();
}
