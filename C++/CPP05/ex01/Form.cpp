/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:11:17 by btani             #+#    #+#             */
/*   Updated: 2024/02/23 14:50:18 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void): _name("def"), _signed(false), _signGrade(150), _executionGrade(150)
{
    std::cout << "Form default constructor called" << std::endl;
};

Form::Form(std::string name, int signGrade, int executionGrade): _name(name), _signed(false), _signGrade(signGrade), _executionGrade(executionGrade)
{
    std::cout << "Form name constructor called" << std::endl;
    try
    {
        if (this->_signGrade < 1 || this->_executionGrade < 1)
            throw Form::GradeTooHighException();
        else if (this->_signGrade > 150 || this->_executionGrade > 150)
            throw Form::GradeTooLowException();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return ;
    }
};

Form::Form(const Form& copy): _name(copy._name), _signGrade(copy._signGrade), _executionGrade(copy._executionGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
    try
    {
        if (this->_signGrade < 1 || this->_executionGrade < 1)
            throw Form::GradeTooHighException();
        else if (this->_signGrade > 150 || this->_executionGrade > 150)
            throw Form::GradeTooLowException();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return ;
    }
    *this = copy;
};

Form::~Form(void)
{
    std::cout << "Form destructor constructor called" << std::endl;
};

Form& Form::operator=(const Form& op)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &op)
        this->_signed = op.getSigned();
    return *this;
};

std::string Form::getName(void) const
{
    return this->_name;
};

bool Form::getSigned(void) const
{
    return this->_signed;
};

int Form::getSignGrade(void) const
{
    return this->_signGrade;
};

int Form::getExecutionGrade(void) const
{
    return this->_executionGrade;
};

void	Form::beSigned(const Bureaucrat& bur)
{
	try {
		if (bur.getGrade() <= this->getSignGrade())
			this->_signed = true;
		else
		{
			if (this->_signGrade < 1)
				throw Form::GradeTooHighException();
			else if (this->_signGrade > 150)
				throw Form::GradeTooLowException();
		}
	}
    catch (std::exception& ex)
    {
		std::cout << ex.what() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high: ";
};

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low: ";
};

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << rhs.getName() << ": " << std::endl;
	if (rhs.getSignGrade() >= 1 && rhs.getSignGrade() <= 150)
		os << rhs.getSignGrade() << " sign grade" << std::endl;
	else
		os << "Error invalid sign grade!" << std::endl;
	return os;
}

