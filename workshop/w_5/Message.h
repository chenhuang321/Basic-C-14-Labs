#pragma once
#ifndef W5_MESSAGE_H__
#define W5_MESSAGE_H__
#include <string>
#include <iostream>

namespace w5 {
	
	struct Tweet {
		std::string _name1;
		std::string _name2;
		std::string _msg;
		bool empty()const { return _name1.empty(); }
	};
	
	class Message {
		Tweet _tweetMsg;
	public:
		Message(); // Empty State
		Message(std::ifstream& fileInput, char ccObj);
		bool empty()const;
		void display(std::ostream& os)const;
	};
}
#endif
