#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public :
		MutantStack<T>() : std::stack<T>() {};
		MutantStack<T>(const MutantStack &cpy) : std::stack<T>(cpy) {};
		virtual ~MutantStack(){};

		MutantStack<T>	&operator=(const MutantStack &rhf)
		{
			if (this != &rhf)
				*this = new std::stack<T>(rhf);
			return *this;
		};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		//methods
		iterator		begin(){return (std::stack<T>::c.begin());};
		iterator		end(){return (std::stack<T>::c.end());};
		reverse_iterator	rbegin(){return (std::stack<T>::c.rbegin());};
		reverse_iterator	rend(){return (std::stack<T>::c.rend());};
		const_iterator		cbegin(){return (std::stack<T>::c.cbegin());};
		const_iterator		cend(){return (std::stack<T>::c.cend());};
		const_reverse_iterator	crbegin(){return (std::stack<T>::c.crbegin());};
		const_reverse_iterator	crend(){return (std::stack<T>::c.crend());};
};

#endif
