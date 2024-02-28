/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:30 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 16:06:47 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat bur1("Bureaucrat1", 2);
    Bureaucrat low("Bureaucrat2", 150);

    ShrubberyCreationForm shrub("Shrubbery");
    RobotomyRequestForm robo("Robotomy");
    PresidentialPardonForm pres("President");
    
    std::cout << std::endl;
    std::cout << "\033[1;32mShrubbery OK \033[0m";
    bur1.signForm(shrub);
    std::cout << "\033[1;32mShrubbery OK \033[0m";
    bur1.executeForm(shrub);

    std::cout << "\033[1;35mShrubbery KO \033[0m";
    bur1.signForm(shrub); //alredy signed
    std::cout << "\033[1;32mShrubbery OK \033[0m";
    low.executeForm(shrub); //low grade

    std::cout << std::endl;

    std::cout << "\033[1;32mRobotomy OK \033[0m";
    bur1.signForm(robo);
    std::cout << "\033[1;32mRobotomy OK \033[0m";
    bur1.executeForm(robo);
    std::cout << "\033[1;35mRobotomy KO \033[0m";
    low.signForm(robo); //alredy signed
    std::cout << "\033[1;35mRobotomy KO \033[0m";
    low.executeForm(robo); //low grade

    std::cout << std::endl;

    std::cout << "\033[1;32mPresident OK \033[0m";
    bur1.signForm(pres);
    std::cout << "\033[1;32mPresident OK \033[0m";
    bur1.executeForm(pres);
    std::cout << "\033[1;35mPresident KO \033[0m";
    low.signForm(pres); //alredy signed
    std::cout << "\033[1;35mPresident KO \033[0m";
    low.executeForm(pres); //low grade
    
    std::cout << std::endl;

    return (0);
}
