/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:12:36 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 14:15:21 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define  SPAN_HPP

#include <iostream>
#include <vector>
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

class Span {
private:
	unsigned int N;
	std::vector<int> numbers;

public:
	Span(unsigned int N);

	Span();
	~Span();
	Span(const Span&);
	Span& operator=(const Span&);

	void addNumber(int number);

	void addNumbers(int start, int end, int step);
	
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
