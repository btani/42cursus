/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:35:28 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 18:35:30 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("def"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << "Bureaucrat name constructor called" << std::endl;
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch (std::exception& ex)
    {
        this->_grade = 150;
        std::cout << ex.what() << std::endl;
        std::cout << this->_name << " re-set to the grade value " << this->_grade << std::endl;
        return ;
    }
    this->_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = copy;
};

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor constructor called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& op)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    if (this != &op)
        this->_grade = op.getGrade();
    return *this;
};

std::string Bureaucrat::getName(void) const
{
    return this->_name;
};

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
};

void Bureaucrat::incrementation(int nbr)
{
    try
    {
        if (this->_grade - nbr < 1)
            throw Bureaucrat::GradeTooHighException();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    this->_grade -= nbr;
}; 

void Bureaucrat::decrementation(int nbr)
{
    try
    {
        if (this->_grade + nbr > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    this->_grade += nbr;
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high: ";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low: ";
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return os;
};
