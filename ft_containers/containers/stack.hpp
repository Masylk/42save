#ifndef STACK_HPP
# define STACK_HPP

namespace ft
{
	template<typename T, typename Container = vector<T> >
	class	stack
	{
		public :

		//---MEMBER TYPES START
		//
			typedef T		value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
		//
		//---MEMBER TYPES END

		//---CONSTRUCTORS START
		//
			explicit stack(const container_type &ctnr = container_type())
			{
				this->container = ctnr;
			};

			~stack(){};
		
		//
		//---CONSTRUCTORS END
	
		//---FUNCTIONS START
		//

			void			pop(void)
			{
				this->container.pop_back();
			};

			void			push(const value_type &val)
			{
				this->container.push_back(val);
			};

			const value_type	top() const
			{
				return (this->container.back());
			};

			bool			empty() const
			{
				return (this->container.empty());
			};

			size_type		size(void) const
			{
				return (this->container.size());
			};

		//
		//---FUNCTIONS END

		//---DECLARATION OF FRIENDS PROTOTYPES START
		//

			template<typename TF, typename ContainerF>
			friend	bool operator==(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs);
		
			template<typename TF, typename ContainerF>
			friend	bool operator!=(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs);

			template<typename TF, typename ContainerF>
			friend	bool operator<=(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs);
		
			template<typename TF, typename ContainerF>
			friend	bool operator<(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs);
		
			template<typename TF, typename ContainerF>
			friend	bool operator>=(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs);
			
			template<typename TF, typename ContainerF>
			friend	bool operator>(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs);

		//
		//--DECLARATION OF FRIENDS PROTOTYPES END
		
		protected :
			container_type	container;
	};


	template<typename TF, typename ContainerF>
	bool operator==(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs)
	{
		return (lhs.container == rhs.container);
	};

	template<typename TF, typename ContainerF>
	bool operator!=(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs)
	{
		return (lhs.container != rhs.container);
	};

	template<typename TF, typename ContainerF>
	bool operator<=(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs)
	{
		return (lhs.container <= rhs.container);
	};

	template<typename TF, typename ContainerF>
	bool operator>=(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs)
	{
		return (lhs.container >= rhs.container);
	};

	template<typename TF, typename ContainerF>
	bool operator<(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs)
	{
		return (lhs.container < rhs.container);
	};

	template<typename TF, typename ContainerF>
	bool operator>(const ft::stack<TF, ContainerF> &lhs, const ft::stack<TF, ContainerF> & rhs)
	{
		return (lhs.container > rhs.container);
	};



};
#endif
