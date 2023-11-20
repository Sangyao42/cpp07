/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:30:17 by sawang            #+#    #+#             */
/*   Updated: 2023/11/20 01:30:17 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
template <typename T>
void	iter(T *array, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	print(T &a)
{
	std::cout << a << " ";
}

template <typename T>
void	increment(T &a)
{
	a++;
}

template <typename T>
void	decrement(T &a)
{
	a--;
}

template <>
void	increment(char &a)
{
	if (a == 'z')
		a = 'a';
	else if (a == 'Z')
		a = 'A';
	else
		a++;
}

template <>
void	decrement(char &a)
{
	if (a == 'a')
		a = 'z';
	else if (a == 'A')
		a = 'Z';
	else
		a--;
}
