#include "lindenmayer.h"

int main(int argc, char const *argv[])
{

	cout << endl << "running ... ";

	cout << endl;

	lindenmayer l1;

	cout << endl;

	l1.compute_generation();

	cout << endl;

	l1.compute_generation();

	cout << endl;

	l1.compute_generation();

	cout << endl;

	l1.compute_generation();

	cout << endl;

	// l1.list_out();
	l1.interpret();




	cout << "done." << endl << endl;

	return 0;

}
