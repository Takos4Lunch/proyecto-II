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
		void save();
		void load();
		
		//Vamos a hacer los metodos a ver si sirve njd
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
