#ifndef W2_Stations_H__
#define W2_Stations_H__
#include <iostream>
#include "Station.h"
#define SoldNum(num) -num

namespace w2 {

	class Stations {
		Station* _stations;
		int _size;
		void _allocate(int size);
		void _deallocate();
		bool _isAlloc()const;
	public:
		Stations(const char* fileName);
		~Stations();
		void update()const;
		void restock()const;
		void report()const;
	};
}
#endif