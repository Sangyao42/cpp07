/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:27:49 by sawang            #+#    #+#             */
/*   Updated: 2023/12/15 16:05:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

struct s_test
{
	int a;
	int b;
};

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &cpy);
		Array	&operator=(Array const &rhs);
		~Array();

		//operator overload
		T		&operator[](unsigned int i);
		T		&operator[](unsigned int i) const;

		//getters
		unsigned int	size() const;
		T *getAddress() const;

		class IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		T				*_array;
		unsigned int	_size;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &rhs);

#include "../src/Array.tpp"