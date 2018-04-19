#pragma once
#ifndef _TEXT_H__
#define _TEXT_H__
#include <string>
namespace w3 {
	class Text {
		std::string* _msg;
		size_t _size;
		void _dynamicAlloc(size_t size);
		void _destructor();
		void _setSize(const char* fileName);
	public:
		Text();
		Text(const char* fileName);
		Text(const Text& t_copy);
		Text& operator=(const Text& t);
		Text(Text&& t_move);
		Text& operator=(Text&& t);
		~Text();
		size_t size()const;
	};
}
#endif