#pragma once
#ifndef _PROCESS_H__
#define _PROCESS_H__
#include "CString.h"
namespace w1 {
	void process(const char* s) {
		CString cs(s);
		std::cout << cs << std::endl;
	}
}
#endif