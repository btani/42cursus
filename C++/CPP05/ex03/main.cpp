/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:30 by btani             #+#    #+#             */
/*   Updated: 2024/02/23 14:49:39 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
   {
        Intern someRandomIntern;
        AForm* rrf;
        AForm* rrf1;
        AForm* rrf2;
        AForm* rrf3;

        std::cout << std::endl;
        std::cout << "\033[1;32mShrubbery OK \033[0m";
        rrf = someRandomIntern.makeForm("shrubbery", "Bender");
        std::cout << std::endl;    
        std::cout << "\033[1;35mRobotomy KO \033[0m";
        rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << std::endl;
        std::cout << "\033[1;32mPresidential OK \033[0m";
        rrf2 = someRandomIntern.makeForm("presidential request", "Bender");
        std::cout << std::endl;
        std::cout << "\033[1;31mForm 'insesitente'\033[0m";
        rrf3 = someRandomIntern.makeForm("inesistente", "Bender");
        std::cout << std::endl;

        delete rrf;
        delete rrf1;
        delete rrf2;
    }
    return (1);
}
