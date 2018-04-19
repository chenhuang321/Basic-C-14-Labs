#pragma once
#ifndef _GRADES_H__
#define _GRADES_H__
#include <iostream>
#include <list>
#include <string>
namespace w6 {

	struct Student {
		double _grade;
		std::string _letter;
		std::string _studentNo;
		std::string& setLetter();
		Student& clear();
		void print(std::ostream& os)const;
	};

	class Grades {
		std::list<Student> _gradeList;
		Grades();
		Grades(const Grades& gradeList);
		uint64_t operator=(const Grades& gradeList);
		Grades(Grades&& gradeList);
		uint64_t operator=(Grades&& gradeList);
	public:
		Grades(const char* fileName);
		void displayGrades(std::ostream&, std::list<std::string>)const;
	};
}
#endif