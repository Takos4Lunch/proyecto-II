#include "Alumno.h"
#include <iostream>
#include <cstdlib>

Alumno::Alumno(){
	
}

void Alumno::save(int x,char z[30]){
	string jumpsuit = "\r\n";
	y.open("Datos.dat",ios::binary|ios::out|ios::app);
	y.write((char *)&x,sizeof(x));
	y.write((char *)z,30);
	y.write((char *)&jumpsuit,2);
	y.close();
}

void Alumno::load(){//Quizas deber�a pasarle un array de alumnos para que los guarde
	
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
		cout<<sav<<endl;//Aqui ya tengo los valores
		cout<<temp<<endl;//lo que hay que hacer es pasarle a este metodo un arreglo vacio y que lo llene
	}while(!y.fail());
	y.close();
}
