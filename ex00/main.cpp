/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:12:31 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 12:41:08 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    // intのvectorを作成
    std::cout << YELLOW << "test int " << END << std::endl;
    
    std::cout << CYAN << "1 ~ 5 \nassign num = 3" << END << std::endl;
    std::vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    intVec.push_back(4);
    intVec.push_back(5);
    try {
        std::vector<int>::iterator it = easyfind(intVec, 3);
        std::cout << GREEN << "Found: " << *it << END << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << RED <<  e.what() << END << std::endl;
    }
    
    std::cout << "\n------------------------------------\n" << std::endl;
    
    // test out_of_range
    std::cout << YELLOW << "test int out_of_range " << END << std::endl;
    std::cout << CYAN << "1 ~ 5 \nassign num = 100" << END << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(intVec, 100);
        std::cout << GREEN << "Found: " << *it << END << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << RED <<  e.what() << END << std::endl;
    }

    // charのvectorを作成
    std::cout << "\n------------------------------------\n" << std::endl;
    std::cout << YELLOW << "test char  " << END << std::endl;
    std::cout << CYAN << "hello \nassign num = e (ver ascii number)" << END << std::endl;

    std::vector<char> charVec;
    charVec.push_back('h');
    charVec.push_back('e');
    charVec.push_back('l');
    charVec.push_back('l');
    charVec.push_back('o');
    try {
        std::vector<char>::iterator it = easyfind(charVec, 'e');
        std::cout << GREEN << "Found: " << *it << END << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << RED <<  e.what() << END << std::endl;
    }

    std::cout << "\n------------------------------------\n" << std::endl;
    std::cout << YELLOW << "test char no member  " << END << std::endl;
    std::cout << CYAN << "hello \nassign num = z (ver ascii number)" << END << std::endl;

    try {
        std::vector<char>::iterator it = easyfind(charVec, 'z');
        std::cout << GREEN << "Found: " << *it << END << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << RED <<  e.what() << END << std::endl;
    }

    // charのdequeを作成
    std::cout << "\n------------------------------------\n" << std::endl;
    std::cout << YELLOW << "test deque  " << END << std::endl;

    std::deque<char> charDeque;

    charDeque.push_back('h');
    charDeque.push_back('e');
    charDeque.push_back('l');
    charDeque.push_back('l');
    charDeque.push_back('o');
    
    try {
        std::deque<char>::iterator it = easyfind(charDeque, 'e');
        std::cout << GREEN << "Found: " << *it << END << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << RED <<  e.what() << END << std::endl;
    }

    // intのlistを作成
    std::cout << "\n------------------------------------\n" << std::endl;
    std::cout << YELLOW << "test list  " << END << std::endl;
    std::list<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.push_back(4);
    intList.push_back(5);

    try {
        std::list<int>::iterator it = easyfind(intList, 4);
        std::cout << GREEN << "Found: " << *it << END << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << RED <<  e.what() << END << std::endl;
    }

    // test random access
    // std::cout << "\n------------------------------------\n" << std::endl;
    // std::cout << YELLOW << "test random access " << END << std::endl;
    // std::cout << CYAN << "1 ~ 5 \nassign  配列の３番目" << END << std::endl;
    // std::vector<int> Vec;
    // // std::deque<int> Vec;

    // // list はランダムアクセスできない
    // // std::list<int> Vec;

    // Vec.push_back(1);
    // Vec.push_back(2);
    // Vec.push_back(3);
    // Vec.push_back(4);
    // Vec.push_back(5);
    // int value = Vec[2];
    // std::cout << GREEN << value << END << std::endl;
    return 0;
}

// std::vector:
// 内部的には動的配列として実装
// 要素は連続したメモリブロックに格納
// ランダムアクセスが可能
// 末尾への要素の追加や削除は高速ですが、先頭や中間への要素の追加や削除は遅い

// +---+---+---+---+---+
// | 0 | 1 | 2 | 3 | 4 |
// +---+---+---+---+---+


// std::deque (Double Ended Queue):
// 両端キュー
// 内部的には固定サイズの配列のリストとして実装
// ランダムアクセスが可能
// 要素は連続ではないメモリブロックに格納
// 先頭と末尾への要素の追加や削除は高速

// +---+---+       +---+---+       +---+---+
// | 0 | 1 |  ...  | 2 | 3 |  ...  | 4 | 5 |
// +---+---+       +---+---+       +---+---+


// std::list:

// 内部的には双方向連結リストとして実装
// 各要素はそれぞれ前と次の要素へのポインタを保持
// ランダムアクセスはサポートされていない。
// 要素にアクセスするには、リストを通じて反復する必要あり
// 先頭、中間、および末尾への要素の追加や削除は高速ですが、要素のアクセスは遅い

// ランダムアクセス
// std::vector<int> vec = {1, 2, 3, 4, 5};
// int value = vec[2];  // 3番目の要素に直接アクセス

// メモリ上でデータが連続していなければならない

// +---+    +---+    +---+
// | 0 | -> | 1 | -> | 2 |
// +---+    +---+    +---+

// 他にもシーケンスはあるがc＋９８はこれくらい