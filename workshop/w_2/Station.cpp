#include "Station.h"
using namespace std;
namespace w2 {
	Station::Station() : _name(string()), _student(0), _adult(0) {}
	
	void Station::set(const std::string& name, unsigned student, unsigned adult) {
		_name = name;
		_student = student;
		_adult = adult;
	}

	void Station::update(PassType tp, int modify_value) {
		if (tp == Student)
			_student += modify_value;
		else if (tp == Adult)
			_adult += modify_value;
	}

	unsigned Station::inStock(PassType tp)const {
		return (tp == Student)? _student : _adult;
	}

	const std::string& Station::getName()const {
		return _name;
	}

	void Station::getStation(std::ifstream& fileIn) {
		string name;
		int s, a; // The tmp value of student and adult
		getline(fileIn, name, ';');
		fileIn >> s;
		fileIn >> a;
		set(name, s, a); // Set function
	}
}