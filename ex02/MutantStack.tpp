/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:09:21 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 16:16:29 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// type deque

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	std::cout << MAGENTA << "normal! begin" << END << std::endl;
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	std::cout << MAGENTA << "const! begin" << END << std::endl;
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	std::cout << MAGENTA << "normal! end" << END << std::endl;
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	std::cout << MAGENTA << "const! end" << END << std::endl;
	return std::stack<T>::c.end();
}


// type list

// template <typename T, typename Container>
// MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

// template <typename T, typename Container>
// MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) {}

// template <typename T, typename Container>
// MutantStack<T, Container>::~MutantStack() {}

// template <typename T, typename Container>
// MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other)
// {
// 	std::stack<T, Container>::operator=(other);
// 	return *this;
// }

// template <typename T, typename Container>
// typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
// {
// 	return std::stack<T, Container>::c.begin();
// }

// template <typename T, typename Container>
// typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
// {
// 	return std::stack<T, Container>::c.begin();
// }

// template <typename T, typename Container>
// typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
// {
// 	return std::stack<T, Container>::c.end();
// }

// template <typename T, typename Container>
// typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
// {
// 	return std::stack<T, Container>::c.end();
// }

// template <typename T, typename Container>
// MutantStack<T, Container>::operator std::stack<T, Container>() const
// {
// 	return std::stack<T, Container>(*this);
// }
