/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:09:21 by khorike           #+#    #+#             */
/*   Updated: 2023/09/27 12:40:09 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T container, int num)
{
	// search num
	typename T::iterator it = std::find(container.begin(), container.end(),num);
	if (it != container.end())
		return it;
	else
	{
		// コンパイル時にはわからない
		// プログラム実行時にのみ検出可能なエラー（実行時エラー）を示す
		throw std::runtime_error("Number not found");
	}
}

// イテレータは、コンテナの要素を順に走査する際に非常に重要な役割を果たします。
// イテレータは基本的には「ポインタのようなもの」
// と考えることができ、特定の位置の要素を指す能力を持っています。


// associative containers と　Sequence Containers の違い

// シーケンスコンテナは要素を明確な順序で保持し、
// 要素への位置に基づくアクセスを提供します。
// これらのコンテナは、要素が挿入された順序を保持するため、
// インデックスまたはイテレータを使用して要素にアクセスできます。

// 連想コンテナ（Associative Containers）は、
// キーに基づいて要素を保持し、キーを使用して要素にアクセスします。
// 連想コンテナの例としては、
// std::set, std::map, std::multiset, std::multimap 
// などがあります。これらのコンテナは、要素への高速なキーに基づくアクセスを提供するために、
// 内部でバランスの取れた二分木やハッシュテーブルなどのデータ構造を使用することがあります。