#include "CString.h"
using namespace std;
namespace w1 {
	CString::CString() {
		cstring[0] = '\0';
	}

	CString::CString(const char* cs) {
		int i;
		if (cs == (char*)0)
			cstring[0] = '\0';
		else {
			for (i = 0; i < MAX; i++) {
				if (cs[i] != '\0') {
					cstring[i] = cs[i];
					continue;
				}
			}
			cstring[MAX] = '\0';
		}
	}

	void CString::display(std::ostream& os)const {
		os << cstring;
	}

	ostream& operator<<(ostream& os, CString& cs) {
		cs.display(os);
		return os;
	}
}