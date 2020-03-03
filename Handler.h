#ifndef Handler_H
#define Handler_H
#include <fstream>

using namespace std;

class Handler {
	// Private section
	fstream x;
	public:
		// Public Declarations
		Handler();
		void openmat();
		void writemat();
		void openalumn();
		void writealumn();
		void openinscritos();
		void writeinscritos();
	protected:
		// Protected Declarations
};

#endif
