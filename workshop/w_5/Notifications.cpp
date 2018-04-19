#include "Notifications.h"
using namespace std;
namespace w5 {
	Notifications::Notifications() : _size(0) {}
	
	Notifications::Notifications(const Notifications& n) {
		_size = 0;
		if(n._size != 0) {
			_size = n._size;
			_m.clear();
			for(auto me : n._m) {
				_m.push_back(me);
			}
		}
	}
	
	Notifications& Notifications::operator=(const Notifications& n) {
		*this = Notifications(n);
		return *this;
	}
	
	Notifications::Notifications(Notifications&& nmove) {
		_size = 0;
		if(nmove._size != 0) {
			_size = nmove._size;
			_m.clear();
			for(auto me : nmove._m) {
				_m.push_back(me);
			}
		}
	}
	
	Notifications&& Notifications::operator=(Notifications&& nmove) {
		if(this != &nmove){
			_m=nmove._m;
		    _size=nmove._size;
		    nmove._m.clear();
	        nmove._size=0;
		}	
		return std::move(*this);
	}
	
	void Notifications::operator+=(const Message& msg) {
		_size += 1;
		_m.push_back(msg);
	}
	
	void Notifications::display(std::ostream& os) const {
	    for(auto var : _m) {
	    	var.display(os);
		}
	}
}
