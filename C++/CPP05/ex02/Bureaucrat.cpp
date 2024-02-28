/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:14 by btani             #+#    #+#             */
/*   Updated: 2024/02/19 16:17:59 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("def"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << "Bureaucrat param constructor called" << std::endl;
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

void Bureaucrat::signForm(AForm& f) const
{
    try
    {
        f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
    catch (const AForm::SignedException& ex)
    {
		std::cout << ex.what() << std::endl;
        std::cout << this->getName() << " couldn't sign the " << f.getName() << " because the printer isn't working!" << std::endl;
	}
    catch (const AForm::GradeTooLowException& ex)
    {
		std::cout << ex.what() << std::endl;
	}
};

void Bureaucrat::executeForm(AForm const &f) const
{
	try
    {
		f.execute(*this);
		std::cout << this->_name << " executed " << f.getName() << std::endl;
    } 
    catch (const AForm::NotSignedException &ex)
    {
		std::cout << this->_name << " couldn't execute " << f.getName() << ", because it's not signed" << std::endl;
	}
    catch (const Bureaucrat::GradeTooLowException &ex)
    {
		std::cout << this->_name << " couldn't execute " << f.getName() << ", because the grade of " << this->_name << " is too low" << std::endl;
    }
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high in Bureauacrat";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low in Bureauacrat";
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return os;
};

