#ifndef Alumno_H
#define Alumno_H
#include <fstream>

using namespace std;

class Alumno {
	// Private section
	public:
		int ced;//Cedula
		char nom[30];//Nombre del estudiante
		fstream y;
		Alumno();
		void save();
		void load();
		
		
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
