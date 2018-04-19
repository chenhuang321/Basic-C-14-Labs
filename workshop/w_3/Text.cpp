#include "Text.h"
#include <fstream>
#include <iostream>
using namespace std;
namespace w3 {
	void Text::_dynamicAlloc(size_t size) {
		_msg = (string*)0;
		_msg = new string[size];
	}

	void Text::_destructor() {
		if (_msg != (string*)0) {
			delete[] _msg;
		}
		_msg = (string*)0;
	}

	void Text::_setSize(const char* fileName) {
		fstream file;
		string line;
		size_t size(0);
		if (fileName[0] != '\0') {
			file.open(fileName, ios::in);
			if (file.is_open()) {
				while (!file.eof()) {
					getline(file, line);
					size += 1;
				}
			}
			else {
				size = 0;
				cout << "Cannot find the file, maybe wrong permission?" << endl;
				*this = Text();
			}
			_size = size;
			file.close();
		}
	}

	Text::Text() : _size(0) {
		_dynamicAlloc(0);
	}

	Text::Text(const char* fileName) {
		ifstream fileIn(fileName);
		size_t i = 0;
	    _setSize(fileName);
		_dynamicAlloc(_size);
		if (fileIn.is_open()) {
			if (_size != 0) {
				while (!fileIn.eof()) {
					cout << "file" << fileName << " contains " << _size << " lines " << endl;
					for (size_t i = 0; i < _size; i++)
						getline(fileIn, _msg[i]);
				}
			}
		}
	}

	Text::Text(const Text& t_copy) {
		size_t i;
		if (t_copy._msg != (string*)0) {
			_dynamicAlloc(t_copy._size);
			_size = t_copy._size;
			for (i = 0; i < _size; i++) {
				_msg[i] = t_copy._msg[i];
			}
		}
		else
			*this = Text();
	}

	Text& Text::operator=(const Text& t) {
		*this = Text(t);
		return *this;
	}

	Text::Text(Text&& t_move) {
		*this = t_move;
	}

	Text& Text::operator=(Text&& t) {
		size_t i;
		if (t._msg != (string*)0) {
			_dynamicAlloc(t._size);
			_size = t._size;
			for (i = 0; i < _size; i++) {
				_msg[i] = t._msg[i];
			}
			t._destructor();
		}
		else
			*this = Text();
		return *this;
	}

	Text::~Text() {
		_destructor();
	}

	size_t Text::size()const {
		return _size;
	}
}