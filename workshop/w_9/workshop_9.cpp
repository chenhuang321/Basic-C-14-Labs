 // Workshop 9 - Smart Pointers
 // w9.cpp

 #include <iostream>
 #include <iomanip>
 #include "Element.h"
 #include "List.h"
 #include <exception>

using namespace w9;

 const int FWC =  5;
 const int FWD = 12;
 const int FWP =  8;

 w9::List<w9::Product> merge(const w9::List<w9::Description>& desc, 
  const w9::List<w9::Price>& price) {
     // complete this part
    w9::List<w9::Product> price_list;
	for(size_t index1 = 0 ; index1 < desc.size(); ++index1) {
		unsigned dec_code = desc[index1].code;
		for(size_t index2 = 0 ; index2 < price.size(); ++index2) {
			unsigned price_code = price[index2].code;
			if(price_code == dec_code){
				std::unique_ptr<Product> product(new Product(desc[index1].desc, price[index2].price));
				/*Does not catch the exception
				try{ product->validate(); }
				catch(std::exception& msg){
					priceList = nullptr;
					std::cerr << msg.what() << std::endl;
				}*/
				price_list += std::move(product);
			}			
		}
	}
	return price_list;
 }

 int main(int argc, char** argv) {
     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 3) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
     }

     try {
         w9::List<w9::Description> desc(argv[1]);
         std::cout << std::endl;
         std::cout << std::setw(FWC) << "Code" <<
          std::setw(FWD) << "Description" << std::endl;
         std::cout << desc << std::endl;
         w9::List<w9::Price> price(argv[2]);
         std::cout << std::endl;
         std::cout << std::setw(FWC) << "Code" <<
          std::setw(FWP) << "Price" << std::endl;
         std::cout << price << std::endl;
         w9::List<w9::Product> priceList = merge(desc, price);
         std::cout << std::endl;
         std::cout << std::setw(FWD) << "Description" <<
          std::setw(FWP) << "Price" << std::endl;
         std::cout << priceList << std::endl;
     }
     catch (const std::string& msg) {
         std::cerr << msg << std::endl;
     }
     catch (const char* msg) {
         std::cerr << msg << std::endl;
     }

     std::cout << "\nPress any key to continue ... ";
     std::cin.get();
}
