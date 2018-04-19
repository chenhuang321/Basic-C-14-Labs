#pragma once
#ifndef _SCTRING_H__
#define _SCTRING_H__
#include <iostream>
#define MAX 3
namespace w1 {
	class CString {
		char cstring[MAX + 1];
	public:
		CString();
		CString(const char*);
		void display(std::ostream&)const;
	};
	std::ostream& operator<<(std::ostream&, CString&);
}
#endif