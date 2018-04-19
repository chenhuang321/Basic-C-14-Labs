#include "Grades.h"
#include <fstream>
#include <exception>
using namespace std;
namespace w6 {

	string& Student::setLetter() {
		if (_grade < 50 && _grade >= 0)
			_letter = "F";
		else if (_grade < 55 && _grade >= 50)
			_letter = "D";
		else if (_grade < 60 && _grade >= 55)
			_letter = "D+";
		else if (_grade < 65 && _grade >= 60)
			_letter = "C";
		else if (_grade < 70 && _grade >= 65)
			_letter = "C+";
		else if (_grade < 75 && _grade >= 70)
			_letter = "B";
		else if (_grade < 80 && _grade >= 75)
			_letter = "B+";
		else if (_grade < 90 && _grade >= 80)
			_letter = "A";
		else if (_grade >= 90)
			_letter = "A+";
		else
			_letter.clear();
		return _letter;
	}

	Student& Student::clear() {
		_grade = 0;
		_studentNo.clear();
		_letter.clear();
		return *this;
	}

	void Student::print(ostream& os)const {
		if (_studentNo.length() >= 7 && !_letter.empty()) {
			os << _studentNo << ' ' << _grade << ' ' << _letter;
		}
		else
			throw "\n";
	}

	Grades::Grades() {
		if (!_gradeList.empty()) {
			_gradeList.clear();
		}
	}

	Grades::Grades(const Grades& gradeList) {
		_gradeList.clear();
		if (!gradeList._gradeList.empty()) {
			for (auto gradeSymbol : gradeList._gradeList) {
				_gradeList.push_back(gradeSymbol);
			}
		}
		else
			throw "Cannot copy empty object!";
	}

	uint64_t Grades::operator=(const Grades& gradeList) {
		try {
		    *this = Grades(gradeList);
		}
		catch(const char* msg) {
			throw msg;
		}
		return this->_gradeList.size();
	}

	Grades::Grades(Grades&& gradeList) {
		_gradeList.clear();
		if (!gradeList._gradeList.empty()) {
			for (auto gradeSymbol : gradeList._gradeList) {
				_gradeList.push_back(std::move(gradeSymbol));
			}
		}
		else
			throw "Cannot move empty object!";
	}

	uint64_t Grades::operator=(Grades&& gradeList) {
		_gradeList.clear();
		if (!gradeList._gradeList.empty()) {
			_gradeList = std::move(gradeList._gradeList);
		}
		else
			throw "Cannot assign empty pbject!";
		return this->_gradeList.size();
	}

	Grades::Grades(const char* fileName) {
		fstream fileIn;
		fileIn.open(fileName, ios::in);
		if (fileIn.is_open()) {
			while (!fileIn.eof()) {
				string studentNo;
				double studentGrade;
				getline(fileIn, studentNo, ' ');
				fileIn >> studentGrade;
				Student tmpStudent;
				tmpStudent._grade = studentGrade;
				tmpStudent._studentNo = studentNo;
				_gradeList.push_back(tmpStudent);
			}
		}
		else
			throw "Cannot open the file, maybe wrong permission?";
		fileIn.close();
	}

	void Grades::displayGrades(std::ostream& os, std::list<string> letter)const {
		letter.clear();
		if (!_gradeList.empty()) {
			for (auto gradeSymbol : _gradeList) {
				letter.push_back(gradeSymbol.setLetter());
				gradeSymbol.print(os);
			}
		}
	}
}