#include "Semestre.h"
#include <iostream>

using namespace std;

Semestre::Semestre(){
	
}

void Semestre::save(int cd,int ce){
	//Probar si el jumpsuit sirve aquí
	y.open("Inscritos.dat",ios::binary|ios::out|ios::app);
	y.write((char *)&cd,sizeof(cd));//3
	y.write((char *)&ce,sizeof(ce));//8
	y.close();
}

void Semestre::load(){
	int p = 111;
	int q = 11111111;
	int ph;
	int sav = 0;
	int sev = 0;
	y.open("Inscritos.dat",ios::binary | ios::in);
	do{
		y.read((char *)&sav,sizeof(p));
		y.read((char *)&sev,sizeof(q));
		y.read((char *)&ph,0);
		cout<<sav<<endl;
		cout<<sev<<endl;
	}while(!y.fail());
	y.close();
}
