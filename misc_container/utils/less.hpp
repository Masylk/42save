#ifndef LESS_HPP
# define LESS_HPP

namespace ft
{
	template<typename T>
	struct less
	{
		bool	operator()(const T& x, const T&y) const
		{
			return (x < y);
		};
	};
};

#endif
