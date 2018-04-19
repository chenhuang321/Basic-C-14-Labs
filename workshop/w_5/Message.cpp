#include "Message.h"
#include <fstream>
using namespace std;

namespace w5 {
	
	Message::Message() {}
	
	Message::Message(std::ifstream& fileInput, char ccObj) {
        string tweetLine;
        getline(fileInput, tweetLine, ccObj);
        if(!tweetLine.empty()) {
        	_tweetMsg._name1 = tweetLine.substr(0, tweetLine.find(' '));
        	tweetLine = tweetLine.substr(tweetLine.find(' ') + 1);
        	if(tweetLine[0] == '@') {
        		_tweetMsg._name2 = tweetLine.substr(1, tweetLine.find(' '));
        		_tweetMsg._msg = tweetLine.substr(tweetLine.find(' ') + 1);
			}
			else {
				_tweetMsg._msg = tweetLine;
			}
		}
	}
	
	bool Message::empty()const {
	    return _tweetMsg.empty(); 
	}
	
	void Message::display(std::ostream& os)const {
	    if(!empty()) {
			if(!_tweetMsg.empty() && !(_tweetMsg._msg == _tweetMsg._name1)) {
				cout << "Message" << endl;
				cout << " User  : " <<  _tweetMsg._name1 << endl;
				if(!_tweetMsg._name2.empty()) {
				    cout << " Reply : " << _tweetMsg._name2 << endl;
				}
				if(!_tweetMsg._msg.empty()) {
				    cout << " Tweet : " << _tweetMsg._msg << endl;
				}
				cout << endl;
			}
		} 
	}
}
