#include "Materia.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

Materia::Materia(){
	
}

Materia::Materia(int cd,char tt[80], char ucc[0]){
	this->cod = cd;
	strcpy(tit,tt);
	strcpy(uc,ucc);
}

void Materia::save(int cd, char tt[80],char *uc,Materia **mat,int contmater){
	string jumpsuit = "\r\r\n";
	y.open("Materia.dat",ios::binary|ios::out|ios::app);
	y.write((char *)&cd,sizeof(cd));
	y.write((char *)tt,80);
	y.write((char *)uc,1);
	y.write((char *)&jumpsuit,3);
	mat[contmater] = new Materia(cd,tt,uc);
	contmater++;
	y.close();
}

void Materia::load(Materia **mat,int contmater){
	int p = 111;
	int sav = 0;
	char temp[80];
	char uc[0];
	int placeholder;
	y.open("Materia.dat",ios::binary|ios::in);
	contmater = 0;
	int unidades = 0;
	do{
		y.read((char *)&sav,sizeof(p));
		y.read((char *)&temp,sizeof(temp));
		y.read(uc,1);
		y.read((char*)&placeholder,3);
		//unidades = atoi(uc);
		//Gentil recordatorio de que igual sirve con atoi
		mat[contmater] = new Materia(sav,temp,uc);
		contmater++;
	}while(!y.fail());
	y.close();
}

void Materia::print(){
	cout<<"Codigo : "<<cod<<endl;
	cout<<"Titulo : "<<tit<<endl;
	cout<<"U.C. : "<<uc<<endl;
}
