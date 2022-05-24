#include "easyfind.hpp"
#include <time.h>

#include <list>
#define MAX_LST 10

int		main() {

	srand(time(NULL));
	std::cout << "\033[1;33m#########   MAIN TEST   #########\033[0m\n";
	{
		int								i(0);
		int			toFind( rand() % MAX_LST);
		std::list<int> 					lst;

		for (; i < MAX_LST; i++ )
			lst.push_back( i );
		std::cout << "\033[0;33m------- Test T::iterator\033[0m\n";
		{
			std::list<int>::iterator		it;
			int		out( rand() % MAX_LST + 10);

			for ( it = lst.begin(); it != lst.end(); it++)
				std::cout << *it << " --- " << &*it << std::endl;
			try {
				it = easyfind(lst, toFind);
				std::cout << "found     " << *it << " - " << &*it << std::endl;
			}
			catch(const std::exception& e) {
				std::cout << "not found " << toFind << " - " << e.what() << std::endl;
			}
			try {
				it = easyfind(lst, out);
				std::cout << "found     " << *it << " - " << &*it << std::endl;
			}
			catch(const std::exception& e) {
				std::cout << "not found " << out << " - " << e.what() << std::endl;
			}
		}
		std::cout << "\033[0;33m------- Test T::const_iterator\033[0m\n";
		{
			std::list<int>::const_iterator	itConst;
			int			out( rand() % MAX_LST + 10);

			for ( itConst = lst.begin(); itConst != lst.end(); itConst++)
				std::cout << *itConst << " --- " << &*itConst << std::endl;
			try {
				itConst = easyfind(lst, toFind);
				std::cout << "found     " << *itConst << " - " << &*itConst << std::endl;
			}
			catch(const std::exception& e) {
				std::cout << "not found " << toFind << " - " << e.what() << std::endl;
			}
			try {
				itConst = easyfind(lst, out);
				std::cout << "found     " << *itConst << " - " << &*itConst << std::endl;
			}
			catch(const std::exception& e) {
				std::cout << "not found " << out << " - " << e.what() << std::endl;
			}
		}
	}
}
