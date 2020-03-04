#include "Materia.h"
#include <iostream>

using namespace std;

Materia::Materia(){
	
}

void Materia::save(int cd, char tt[80],char *uc){
	string jumpsuit = "\r\r\n";
	y.open("Materia.dat",ios::binary|ios::out|ios::app);
	y.write((char *)&cd,sizeof(cd));
	y.write((char *)tt,80);
	y.write((char *)uc,1);
	y.write((char *)&jumpsuit,3);
	y.close();
}

void Materia::load(){
	int p = 111;
	int sav = 0;
	char temp[80];
	char uc;
	int placeholder;
	y.open("Materia.dat",ios::binary|ios::in);
	do{
		y.read((char *)&sav,sizeof(p));
		y.read((char *)&temp,sizeof(temp));
		y.read((char *)&uc,sizeof(uc));
		y.read((char*)&placeholder,3);
		cout<<sav<<endl;
		cout<<temp<<endl;
		cout<<uc<<endl;
	}while(!y.fail());
	y.close();
}
