#ifndef W2_STATION_H__
#define W2_STATION_H__
#include <string>
#include <fstream>
typedef unsigned int numPass;
namespace w2 {
	enum PassType { Student = 120, Adult = 121};
	class Station {
		std::string _name;
		numPass _student;
		numPass _adult;
	public:
		Station();
		void set(const std::string&, unsigned, unsigned);
		void update(PassType, int);
		unsigned inStock(PassType)const;
		const std::string& getName()const;
		void getStation(std::ifstream& fileIn);
	};
}
#endif