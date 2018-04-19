#include "process.h"
using namespace std;

int main(int argc, char* argv[], char* env[]) {
	int arg;
	cout << "Command Line: ";
	for (arg = 0; arg < argc; arg++)
		cout << argv[arg] << ' ';
	cout << endl;
	if (argc == 1) {
		cerr << "Insufficient number of arguments (min 1)" << endl;
		return 1;
	}
	cout << " Maximum number of characters stored : " << MAX << endl;
	for (arg = 1; arg < argc; arg++) {
		cout << arg - 1 << ": ";
		w1::process(argv[arg]);
	}
	return 0;
}