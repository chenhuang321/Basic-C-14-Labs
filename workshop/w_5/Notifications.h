#pragma once
#ifndef _NOTIFICATIONS_H__
#define _NOTIFICATIONS_H__
#include "Message.h"
#include <list>
#include <iostream>
#define MSG_MAX 10
namespace w5 {
	
	class Notifications{
		std::list<Message> _m;
		size_t _size;
	public:	
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		//~Notifications();
		void operator+=(const Message& msg);
		void display (std::ostream& os) const;
	};
}
#endif
