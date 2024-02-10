/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:07:16 by btani             #+#    #+#             */
/*   Updated: 2024/02/03 17:31:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
binaryspace partitioning (used to divide a space into regions): recursively partition
space into two halves using a splitting plane; Each side of the plane is then treated as a 
separate region, and the process is repeated for each region until a certain condition is met.
*/
static Fixed calcArea(Point const a, Point const b, Point const c)
{
	Fixed area;

	area = ((a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY()))) / 2;
	if (area < 0)
		area = area * -1;
	return (area);
};

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A0 = calcArea(a, b, c);
	Fixed A1 = calcArea(a, b, point);
	Fixed A2 = calcArea(a, point, c);
	Fixed A3 = calcArea(point, b, c);
	//if sub-triangles area =0, point is on edge
	if (A1 == 0 || A2 == 0 || A3 == 0)
		return false;
	//if the sum of sub-triangles areas is greather than the original area, the point is outside triangle
	if (A0 == (A1 + A2 + A3))	
		return true;
	return false;
};
