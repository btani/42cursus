/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:06:30 by btani             #+#    #+#             */
/*   Updated: 2024/02/04 18:42:34 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main (void)
{
    Point in(0.2f, 0.2f);
    Point out(9, 9);
    Point ed(2, 0);

    bool inside = bsp(Point(0, 0), Point(2, 6), Point(4, 0), in);
    bool outside = bsp(Point(0, 0), Point(2, 6), Point(4, 0), out);
    bool edge = bsp(Point(0, 0), Point(2, 6), Point(4, 0), ed);
    
    std::cout << "Point(0.2f, 0.2f) is " << (inside ? "inside" : "outside") << std::endl;
    std::cout << "Point(9, 9) is " << (outside ? "inside" : "outside") << std::endl;
    std::cout << "Point(2, 0) is " << (edge ? "inside" : "outside") << std::endl;

    return 0;
}
