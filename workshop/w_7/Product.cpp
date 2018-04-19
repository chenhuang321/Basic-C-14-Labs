#include "iProduct.h"
#include <string>
#include <iomanip>
#define HST_RATE 0.13
#define PST_RATE 0.08
#define OUTPUT_WIDTH 10

namespace w7 {
	
	// iProduct class implement start!
    std::ostream& operator<<(std::ostream& os, const iProduct& rhs) {
    	rhs.display(os);
    	return os;
	}
	
	iProduct* readProduct(std::ifstream& fileIn) {
		iProduct* ptr_product;
		if(!fileIn.fail()) {
		    size_t proNo;
		    double proCost;
		    TAXTYPE rate;
		    fileIn >> proNo >> proCost;
		    std::string tmpLine;
		    getline(fileIn, tmpLine);
		    // Make the fileIn into the new line of the current file
		    //std::cout << tmpLine << "\n";
		    if(tmpLine[1] == 'H') {
		    	//std::cout << "It's ok!\n";
		    	rate = HST;
		    	ptr_product = new TaxableProduct(proNo, proCost, rate);
			}
			else if(tmpLine[1] == 'P') {
				rate = PST;
				ptr_product = new TaxableProduct(proNo, proCost, rate);
			}
			else
			    ptr_product = new Product(proNo, proCost);
		}
		return ptr_product;
	}
	
	// Product class impelement start!
	Product::Product() {
		this->productNo = 0;
		this->cost = 0;
		// Default constructor function to set initialization
	}
	
	Product::Product(size_t productNo, double cost) {
		this->productNo = productNo;
		this->cost = cost;
		// Assignment operator to get values from parameters
		if(this->cost < 0) {
			this->cost = 0;
		} // cost validation (cost should be greater equal than 0)
	}
	
	double Product::getCharge() const {
	    return this->cost;
	}
	
	void Product::display(std::ostream& os) const {
	    os << std::setw(OUTPUT_WIDTH) << std::right << this->productNo;
		os << std::setw(OUTPUT_WIDTH) << std::right << std::fixed << std::setprecision(2) << this->cost;
	} // Control the width of the console screen output
	
	// TaxableProduct class implement start!
	TaxableProduct::TaxableProduct() : Product() {
	    // default constructor
	    // Initialize the parent class
	}
	
	TaxableProduct::TaxableProduct(size_t proNo, double proCost, TAXTYPE proType) : Product(proNo, proCost) {
		_type = proType;
	}
	
	double TaxableProduct::getCharge() const {
	    double TaxRate(0.00); // Set default value to zero
	    if(_type == HST) {
	    	TaxRate = HST_RATE;
		}
		else if(_type == PST) {
			TaxRate = PST_RATE;
		}
		return Product::getCharge() * ( 1 + TaxRate); 
		// Calculate the total value
	}
	
	void TaxableProduct::display(std::ostream& os) const {
		//std::cout << "It's ok!\n";
	    Product::display(os);
	    if(_type == HST) {
	    	os << " HST";
		}
		else if(_type == PST) {
			os << " PST";
		}
	}
}
