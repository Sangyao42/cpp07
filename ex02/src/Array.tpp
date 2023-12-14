/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:49 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 15:53:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

//Orthodox Canonical Form
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array<T> const &cpy) : _array(new T[cpy._size]), _size(cpy._size)
{
	for (unsigned int i = 0; i < cpy._size; i++)
		this->_array[i] = cpy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (this->_size >= rhs._size)
		{
			for (unsigned int i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
			this->_size = rhs._size;
		}
		else
		{
			delete [] this->_array;
			this->_array = new T[rhs._size];
			this->_size = rhs._size;
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

//operator[] overload
template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw Array<T>::IndexOutOfRangeException();
	return (this->_array[i]);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw Array<T>::IndexOutOfRangeException();
	return (this->_array[i]);
}

//getters
template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
T *Array<T>::getAddress() const
{
	return (this->_array);
}


//exception
template <typename T>
const char *Array<T>::IndexOutOfRangeException::what() const throw()
{
	return ("Index out of range.");
}

//print
template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &rhs)
{
	o << rhs.getAddress();
	return (o);
}
