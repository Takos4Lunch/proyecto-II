#ifndef MateriaH
#define MateriaH
#include <fstream>

using namespace std;

class Materia {
	// Private section
	public:
		int cod=0;//Codigo
		char tit[80],uc[1] ;//titulo de la materia, unidades de credito
		fstream y;
		Materia();
		Materia(int cd, char tt[80],char *ucc);
		void save(int cd, char tt[80],char *uc,Materia **mat,int& contmater);
		void load(Materia **mat,int& contmater);
		void print();
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
