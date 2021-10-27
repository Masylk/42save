#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	this->ideas = cpy.ideas;
}

Brain::~Brain()
{
	delete[] this->ideas;
	std::cout << "Brain is dead" << std::endl;
}

		
std::string*	Brain::getIdeas(void) const
{
	return this->ideas;
}
