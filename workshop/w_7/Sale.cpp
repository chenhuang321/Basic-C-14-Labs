#include "Sale.h"
#include <iomanip>

namespace w7 {
	
	Sale::Sale(const char* fileName) {
	    this->vtorProducts.clear();
	    std::ifstream fileIn;
	    try {		
		    fileIn.open(fileName);
		    if(!fileIn.fail()) {
		    	while(!fileIn.eof()) {
		    		vtorProducts.push_back(readProduct(fileIn));
				}
			}
			else {
				throw "Failed to access the file, maybe the wrong permission?";
			}
	    }
	    catch(const char* error_msg) {
	    	std::cout << error_msg << "\n";
		}
	}
	
	void Sale::display(std::ostream& os)const {
	    double total(0.00);
		os << "Product No      Cost Taxable\n";
		for(auto product : vtorProducts) {
			total += product->getCharge();
			if(product->getCharge() > 10) {
		        product->display(os);
			    os << "\n";
		    }
		}
		os << "     " << "Total" << std::setw(10) << std::right << total;
	}
	
}
