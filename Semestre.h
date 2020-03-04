#ifndef Semestre_H
#define Semestre_H
#include <fstream>

using namespace std;

class Semestre {
	// Private section
	public:
		int cod;
		int ced;
		fstream y;
		Semestre();
		Semestre(int cd,int ce);
		void save(int cd,int ce);
		void load(Semestre **smtr,int contsemst);
		void print();
		//Vamos a hacer los metodos a ver si sirve njd
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
