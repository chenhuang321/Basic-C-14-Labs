#pragma once
#ifndef SICT_SALE_H__
#define SICT_SALE_H__
#include <vector>
#include "iProduct.h"

namespace w7 {
    class Sale {
    	std::vector<iProduct*> vtorProducts;
    public:
    	Sale(const char* src); 
		// c-style null-terminated string constructor
		void display(std::ostream& os)const;
	};
}
#endif
