/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:08:52 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/10 09:39:01 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array
{
  private:
	T *_array;
	unsigned int _size;

  public:
	Array<T>() : _size(0)
	{
		_array = new T[0]();
	}
	Array<T>(unsigned int n) : _size(n)
	{
		_array = new T[n]();
	}
	Array(const Array &other) : _size(other._size)
	{
		_array = new T[other._size]();
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[other._size]();
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return (*this);
	}
	virtual ~Array<T>()
	{
		delete[] _array;
	}

class	IndexTooLow : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index is too low");
				};
		};
		class	IndexTooHigh : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index is too high");
				};
		};
		class	EmptyArray : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Array is empty");
				};
		};
		T &	operator[]( int index ) {
			if (static_cast< int >(_size) == 0)
				throw	Array::EmptyArray();
			if (index < 0)
				throw	Array::IndexTooLow();
			if (index >= static_cast< int >(_size))
				throw	Array::IndexTooHigh();
			return _array[index];
		}


	unsigned int size() const {
		return (_size);
	}
};
