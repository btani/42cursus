/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:41:26 by btani             #+#    #+#             */
/*   Updated: 2024/02/27 16:01:27 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

//template definition
template<typename T>
T min(T& a, T& b)
{
	return (a < b ? a : b); //if a<b return a, else return b
};

template<typename T>
T max(T& a, T& b)
{
	return (a > b ? a : b);
};

template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
};

#endif
