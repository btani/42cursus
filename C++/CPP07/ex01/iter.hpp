/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:27:22 by btani             #+#    #+#             */
/*   Updated: 2024/02/27 15:48:42 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

//template definition
template <typename T, typename L, typename F>
void iter(T* addrArr, L lenArr, F function)
{
	if (!addrArr)
	{
		std::cout << "Error: check the pointer, it seems to point to NULL" << std::endl;
		return ;
	}
	for (L i = 0; i < lenArr; i++)
		function(addrArr[i]);
};

