#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750



int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << "Address of Array<int>(numbers): " << Array<int>(numbers) << std::endl;
	std::cout << "Address of int Array mirror: " << mirror << std::endl;
	std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp); // copy constructor
		std::cout << "Address of Array<int>(numbers): " << Array<int>(numbers) << std::endl;
		std::cout << "Address of Array<int>(tmp): " << Array<int>(tmp) << std::endl;
		std::cout << "Address of Array<int>(test): " << Array<int>(test) << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "size" << numbers.size() << std::endl;
    delete [] mirror;
	std::cout << std::endl;

	Array<int> test;
	std::cout << test << std::endl;
	std::cout << std::endl;
	
	Array<struct s_test> test2(2);
	for (int i = 0; i < 2; i++)
	{
		test2[i].a = i;
		test2[i].b = i + 1;
	}
	for (int i = 0; i < 2; i++)
		std::cout << test2[i].a << ' ' << test2[i].b << std::endl;
	std::cout << "size of test 2: " << test2.size() << std::endl;
    return 0;
}