#ifndef MateriaH
#define MateriaH
#include <fstream>

using namespace std;

class Materia {
	// Private section
	public:
		int cod;//Codigo
		char tit[80],uc;//titulo de la materia, unidades de credito
		fstream y;
		Materia();
		void save(int cd, char tt[80],char *uc);
		void load();
		
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
