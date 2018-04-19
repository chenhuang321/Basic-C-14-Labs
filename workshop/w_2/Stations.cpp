#include "Stations.h"
#include <iomanip>
using namespace std;
namespace w2 {
	void Stations::_allocate(int size) {
		if (_isAlloc())
			_stations = (Station*)0;
		_stations = new Station[size];
		_size = size;
	}

	void Stations::_deallocate() {
		if (_isAlloc())
			delete[] _stations;
		_stations = (Station*)0;
	}

	bool Stations::_isAlloc()const {
		return (_stations != (Station*)0);
	}

	Stations::Stations(const char* fileName) {
		ifstream fileIn(fileName);
		int lineNum;
		if (fileIn.is_open()) {
			fileIn >> lineNum;
			fileIn.ignore(1, ';');
			_allocate(lineNum);
			for (int i = 0; i < lineNum; i++) {
				_stations[i].getStation(fileIn);
			}
		}
	}

	Stations::~Stations() {
		_deallocate();
	}

	void Stations::update()const {
		int i;
		const string status("sold");
		int s, a; // Tmp value of student and adult
		cout << "Passes Sold :" << endl 
			<< "-------------";
		for (i = 0; i < _size; i++) {
			cout << _stations[i].getName() << endl;
			cout << " Student Passes sold : ";
			cin >> s;
			cout << " Adult   Passes sold : ";
			cin >> a;
			_stations[i].update(Student, SoldNum(s));
			_stations[i].update(Adult, SoldNum(a));
		}
		cout << endl;
	}

	// Restoke function implement here
	void Stations::restock()const {
		int i;
		const string status("added");
		int s, a; // Tmp value of student and adult
		cout << "Passes Added :" << endl
			<< "-------------";
		for (i = 0; i < _size; i++) {
			cout << _stations[i].getName() << endl;
			cout << " Student Passes added : ";
			cin >> s;
			cout << " Adult   Passes added : ";
			cin >> a;
			_stations[i].update(Student, s);
			_stations[i].update(Adult, a);
		}
		cout << endl;
	}

	// Report function implement  here
	void Stations::report()const {
		cout << "Passes in Stock : Student Adult" << endl;
		cout << "-------------------------------" << endl;
		int i;
		for (i = 0; i < _size; i++) {
			cout.width(22);
			cout << left << _stations[i].getName();
			cout << _stations[i].inStock(Student);
			cout.width(6);
			cout << right << _stations[i].inStock(Adult);
		}
		cout << endl;
	}
}
