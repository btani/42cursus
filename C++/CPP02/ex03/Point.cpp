/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:07:07 by btani             #+#    #+#             */
/*   Updated: 2024/02/03 18:19:34 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ): _x(0), _y(0) { };

Point::Point( const float paramX, const float paramY ): _x(paramX), _y(paramY) { };

Point::Point( const Point& src )
{
	*this = src;
};

Point&	Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(_x) = rhs.getX();
		const_cast<Fixed&>(_y) = rhs.getY();
	}
	return *this;
};

Point::~Point( void ) { }; 

float Point::getX( void ) const
{
	return (_x.toFloat());
};

float Point::getY( void ) const
{
	return (_y.toFloat());
};
