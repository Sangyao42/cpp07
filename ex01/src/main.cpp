/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:30:25 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 15:40:32 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void)
{
	int array[] = {0, 1, 2, 3, 4};

	iter(array, 5, print<const int>);
	std::cout << std::endl;
	iter(array, 5, increment<int>);
	iter(array, 5, print<int>);
	std::cout << std::endl;
	iter(array, 5, decrement<int>);
	iter(array, 5, print<int>);
	std::cout << std::endl;

	char array2[] = {'a', 'b', 'c', 'd', 'e'};

	iter(array2, 5, print<char>);
	std::cout << std::endl;
	iter(array2, 5, increment<char>);
	iter(array2, 5, print<char>);
	std::cout << std::endl;
	iter(array2, 5, decrement<char>);
	iter(array2, 5, print<char>);
	std::cout << std::endl;
	iter(array2, 5, decrement<char>);
	iter(array2, 5, print<char>);
	std::cout << std::endl;
	iter(array2, 5, increment<char>);
	iter(array2, 5, print<char>);
	std::cout << std::endl;

	float array3[] = {0.1f, 1.1f, 2.1f, 3.1f, 4.1f};
	iter(array3, 5, print<float>);
	std::cout << std::endl;
	iter(array3, 5, increment<float>);
	iter(array3, 5, print<float>);
	std::cout << std::endl;
	iter(array3, 5, decrement<float>);
	iter(array3, 5, print<float>);

	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// // template< typename T >
// // void print( T& x )
// // {
// //   std::cout << x << std::endl;
// //   return;
// // }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
