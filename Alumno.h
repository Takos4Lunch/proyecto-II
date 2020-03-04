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
		Alumno(int x, char z[30]);
		void save(int x, char z[30] );
		void load(Alumno **al,int contalumn);
		void print();
		
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
