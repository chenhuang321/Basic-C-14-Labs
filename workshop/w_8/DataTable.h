#pragma once
#ifndef SICT_DATATABLE_H__
#define SICT_DATATABLE_H__
#define HALF(A)    A/2
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <cmath>

namespace w8 {
	
	template <class T>
	struct Data {
		T x;
		T y;
	};
	
	template <class T>
	class DataTable {
		std::vector<Data<T>> data; 
		size_t width;
		size_t num;
		T _mean;
		T _sigma;
		T _median;
		// private functions for calculating
		void set_mean() {
			std::vector<T> y; 
			for(auto& ddd : data) {
				T tmp_y = ddd.y;
				y.push_back(tmp_y);
			}
			T sum = std::accumulate(y.begin(), y.end(), (T)0);
			_mean = sum / data.size();
		}
		void set_sigma() {
			T sum(0);
			for(auto& ddd : data) {
				sum += pow((ddd.y - _mean), 2);
			}
			_sigma = std::sqrt(sum / (data.size() - 1));
		}
		void set_median() {
			std::vector<T> data_t;
			for (size_t i = 0; i < data.size(); i++) {
				data_t.push_back(data[i].y); // Get the vector of Data( x and y )
			}
			std::sort(data_t.begin(), data_t.end()); // Sort the result array
			_median = data_t[HALF(data.size())];
		}
	public:
		DataTable(std::ifstream& fileIn, const int width, const int num) {
            Data<T> data_j;
            if(fileIn.is_open()) {
            	while(!fileIn.eof()) {
            		fileIn >> data_j.x >> data_j.y;
            		data.push_back(data_j);
				}
				this->width = width;
				this->num   = num;
				set_mean();
				set_sigma();
				set_median();
			}
		} /* a DataTable object receives a reference to the file stream that holds the data values, 
		the field width for displaying the data and the number of decimals to display */

		T mean()const {
			return _mean;
		} // returns the mean value of the dependent coordinate
		T sigma()const {
			return _sigma;
		}  // returns the standard deviation of the dependent coordinates
		T median()const {
			return _median;
		} // returns the median value of the dependent coordinate
		void regression(T& slope, T& y_intercept)const {
			std::vector<T> x_value;
			std::vector<T> y_value;
			for(auto& value_data : data) {
				x_value.push_back(value_data.x);
				y_value.push_back(value_data.y);
			}
			T xiyi = std::inner_product(x_value.begin(), x_value.end(), y_value.begin(), (T)0);
		    T xi = std::accumulate(x_value.begin(), x_value.end(), (T)0);
		    T y_side = std::accumulate(y_value.begin(), y_value.end(), (T)0);
		    T new_xSide = std::inner_product(x_value.begin(), x_value.end(), x_value.begin(), (T)0);
		    T size = y_value.size();
		    slope = (size * xiyi - xi * y_side) / (size * new_xSide - xi * xi);
		    y_intercept = (y_side - slope * xi) / size;
		}
		// returns the slope and intercept for the data set
		void display(std::ostream& os)const {
			os << std::setprecision(num) << std::fixed << std::right;
		    for(auto& ddd : data) {
		    	os << std::setw(width) << ddd.x 
				   << std::setw(width) << ddd.y
				   << std::endl;
			}
		}
		// displays the data pairs as shown below
	};

    template <class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& table) {
		table.display(os);
		return os;
	}
	// inserts the data generated by display() into the output stream
}
#endif
