#pragma once
#ifndef _KVLIST_H__
#define _KVLIST_H__
namespace w4 {
	template <typename K, typename V, int N>
	class KVList {
		K _key[N];
		V _value[N];
		size_t _totalNum;
	public:
		KVList() : _totalNum(0) {}
		
		size_t size()const {
			return _totalNum;
		}
		
		const K& key(size_t i) const {
			if (i < _totalNum)
				return _key[i];
			else
				return _key[0];
		}
		
		const V& value(size_t i) const {
			return i < _totalNum ? _value[i] : _value[0];
		}
		
		KVList& add(const K& more_key, const V& more_value) {
			if(_totalNum < N) {
				_key[_totalNum] = more_key;
				_value[_totalNum] = more_value;
				_totalNum += 1;
			}
			return *this;
		}
		
		int find(const K& k) const {
		    size_t i;
		    size_t result = 0;
		    for(i = 0; i < _totalNum; i++) {
		    	if(_key[i] == k)
		    	    result = i;
			}
			return result;
		}
		
		KVList& replace(size_t i, const K& k, const V& v) {
		    if (i < _totalNum){
			    _key[i] = k;
			    _value[i] = v;
		    }
		    return *this;
		}
		
	};
}
#endif
