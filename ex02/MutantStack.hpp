/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:12:36 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 16:08:47 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define  MUTANSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <list>
#include <iterator>
#include <exception>
#include <algorithm>
#include <stdexcept>

// color
#define END             "\033[0m"
#define BOLD            "\033[1m"
#define BLACK           "\033[30m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define WHITE           "\033[37m"
#define UNDERLINE       "\033[4m"
#define BOLD_UNDERLINE  "\033[1;4m"


// type deque

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack& operator=(const MutantStack& other);

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
};

// type list

// template <typename T, typename Container = std::list<T> >
// class MutantStack : public std::stack<T, Container> {
// public:
// 	typedef typename Container::iterator iterator;
// 	typedef typename Container::const_iterator const_iterator;

// 	MutantStack();
// 	MutantStack(const MutantStack& other);
// 	~MutantStack();
// 	MutantStack& operator=(const MutantStack& other);

// 	operator std::stack<T, Container>() const;

// 	iterator begin();
// 	const_iterator begin() const;
// 	iterator end();
// 	const_iterator end() const;
// };

#include "MutantStack.tpp"

#endif
