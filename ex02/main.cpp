/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:12:31 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 16:17:10 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main()
{
    // test normal
    std::cout << YELLOW << "test normal " << END << std::endl;
    
    MutantStack<int> mstack;
    std::cout << CYAN << "empty" << END << std::endl;
    mstack.push(5);
    std::cout << CYAN << "中身 5" << END << std::endl;
    mstack.push(17);
    std::cout << CYAN << "中身 5 17" << END << std::endl;
    std::cout << mstack.top() << std::endl;
    
    // 一個消す
    mstack.pop();
    std::cout << CYAN << "after pop 中身 5" << END << std::endl;
    
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    std::cout << CYAN << "中身 5 3" << END << std::endl;
    mstack.push(5);
    std::cout << CYAN << "中身 5 3 5" << END << std::endl;
    mstack.push(737);
    std::cout << CYAN << "中身 5 3 5 737" << END << std::endl;
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    std::cout << CYAN << "after increment begin 中身 3 5 737 0" << END << std::endl;

    // it が先頭の場合はデクリメントしようとすると範囲外になるためセグフォする
    --it;
    std::cout << CYAN << "after decrement begin 中身 5 3 5 737 0" << END << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // const_iterator のテスト
    std::cout << YELLOW << "test const_iterator " << END << std::endl;

    MutantStack<int>::const_iterator const_it = static_cast<const MutantStack<int>&>(mstack).begin();
    MutantStack<int>::const_iterator const_ite = static_cast<const MutantStack<int>&>(mstack).end();

    while (const_it != const_ite)
    {
        std::cout << *const_it << std::endl;
        ++const_it;
    }

    
    std::stack<int> s = mstack;
    // std::stack<int, std::list<int> > s = mstack;

    std::cout << GREEN << "test copy size\n" << s.size() << END << std::endl;
    return 0;
}

// std::stack        メンバ関数
// 名前	                説明	                             対応バージョン
// (constructor)	  コンストラクタ	
// (destructor)	      デストラクタ	
// operator=	        代入	
// top	            次の要素へアクセスする	
// empty	        要素が空であるかを確認する	
// size	            要素数を取得する	
// push	            要素を追加する	
// emplace	        直接構築で要素を追加する	                  C++11
// pop	            次の要素を削除する	
// swap	            他のstackオブジェクトと値を入れ替える	        C++11

// std::stack は反復（iteration）がない
// LIFOアクセスのみに対応している
// last in first out  最後に入ったものが最初に出る 