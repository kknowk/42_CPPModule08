/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:12:31 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 14:26:28 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "Span.hpp"
#include <iostream>

int main()
{
    // test normal
    std::cout << YELLOW << "test normal " << END << std::endl;
    
    std::cout << CYAN << "6 3 17 9 11" << END << std::endl;
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // test short long 
    std::cout << YELLOW << "test short long Span " << END << std::endl;
    try {
        std::cout << GREEN << sp.shortestSpan() << END << std::endl;
        std::cout << GREEN << sp.longestSpan() << END << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n------------------------------------\n" << std::endl;
    // test only one
    std::cout << YELLOW << "test only one " << END << std::endl;
    
    std::cout << CYAN << "6" << END << std::endl;
    Span sp1 = Span(4294967295);
    try {
        sp1.addNumber(6);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    // test short long
    std::cout << YELLOW << "test Not enough" << END << std::endl;
    try {
        std::cout << GREEN << sp1.shortestSpan() << END << std::endl;
        // std::cout << GREEN << sp1.longestSpan() << END << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << "\n------------------------------------\n" << std::endl;
    // test only one
    std::cout << YELLOW << "test over full " << END << std::endl;
    
    Span sp2 = Span(2);
    std::cout << CYAN << "6 3 5" << END << std::endl;
    try {
        sp2.addNumber(6);
        sp2.addNumber(3);
        sp2.addNumber(5);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    // test nokori
    std::cout << YELLOW << "test nokori" << END << std::endl;
    try {
        std::cout << GREEN << sp2.shortestSpan() << END << std::endl;
        // std::cout << GREEN << sp2.longestSpan() << END << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << "\n------------------------------------\n" << std::endl;

    // test continue numbers
    std::cout << YELLOW << "continue numbers " << END << std::endl;

    Span sp3 = Span(100);
    std::cout << CYAN << "0 ~ 99" << END << std::endl;
    sp3.addNumbers(0, 100, 1);
    try {
        std::cout << GREEN << sp3.shortestSpan() << END << std::endl;
        std::cout << GREEN << sp3.longestSpan() << END << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

        std::cout << "\n------------------------------------\n" << std::endl;

    // test continue numbers int max int min
    std::cout << YELLOW << "continue numbers int max min" << END << std::endl;

    Span sp4 = Span(4294967295);
    std::cout << CYAN << "-2147483648 ~ 2147483647 1000間隔" << END << std::endl;
    try {
        sp4.addNumbers(-2147483648, 2147483647, 1000);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    try {
        std::cout << GREEN << sp4.shortestSpan() << END << std::endl;
        std::cout << GREEN << sp4.longestSpan() << END << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    return 0;
}
