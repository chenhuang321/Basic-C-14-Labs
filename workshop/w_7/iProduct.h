#pragma once
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>

namespace w7 {

    class iProduct {
      public:
        virtual double getCharge() const = 0;
        virtual void display(std::ostream&) const = 0;
    };

    std::ostream& operator<<(std::ostream&, const iProduct&); 
    iProduct* readProduct(std::ifstream& rhs);
    
    class Product : public iProduct {
		size_t productNo;
		double cost;
	public:
		Product();
		Product(size_t, double);
		double getCharge() const;
		virtual void display(std::ostream&) const;
	};
	
	enum TAXTYPE {HST,PST};
	class TaxableProduct : public Product {
		TAXTYPE _type;
	public:
		TaxableProduct();
		TaxableProduct(size_t, double, TAXTYPE);
		double getCharge() const;
		void display(std::ostream&) const;
	};

}
#endif
