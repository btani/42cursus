/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:06:58 by btani             #+#    #+#             */
/*   Updated: 2024/02/03 17:14:08 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	private:
	
	const Fixed _x;
	const Fixed _y;

	public:
	
	Point( void ); //defalut constructor
	Point( const float parmaX, const float paramY);
	Point( const Point& src ); //canonical form copy constructor	

	Point&	operator=(const Point& rhs);	
	
	~Point( void ); //destructor

	float getX( void ) const;
	float getY( void ) const;	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
