/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:09:21 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 14:25:12 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : N(n) {}

Span::Span() {}

Span::~Span() {}

Span::Span(const Span& another)
{
	*this = another;
}

Span& Span::operator=(const Span& another)
{
	numbers = another.numbers;
	N = another.N;
	return *this;
}

void Span::addNumber(int number)
{
	if (number > INT_MAX || number < INT_MIN)
	{
		throw std::out_of_range("Number is out of range of int");
	}
	if (numbers.size() < N)
		numbers.push_back(number);
	else
		throw std::out_of_range("Span is already full");
}

void Span::addNumbers(int start, int end, int step = 1)
{
	for (int i = start; i < end && numbers.size() < N; i += step)
	{
		if (i + step < i)
			 throw std::overflow_error("Addition overflow detected");
		addNumber(i);
	}
}

unsigned int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");
	std::sort(numbers.begin(), numbers.end());
	int minSpan = INT_MAX;
	for (size_t i = 0; i < numbers.size() - 1; ++i)
	{
		int span = numbers[i + 1] - numbers[i];
		minSpan = std::min(minSpan, span);
	}
	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to calculate span");
	}

	// max min
	int max_value = *std::max_element(numbers.begin(), numbers.end());
	int min_value = *std::min_element(numbers.begin(), numbers.end());

	return max_value - min_value;
}

