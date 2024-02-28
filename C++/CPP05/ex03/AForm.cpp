/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:11:59 by btani             #+#    #+#             */
/*   Updated: 2024/02/23 14:52:13 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void): _name("def"), _signed(false), _signGrade(150), _executionGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
};

AForm::AForm(std::string name, int signGrade, int executionGrade): _name(name), _signed(false), _signGrade(signGrade), _executionGrade(executionGrade)
{
    std::cout << "AForm param constructor called" << std::endl;
    try
    {
        if (this->_signGrade < 1 || this->_executionGrade < 1)
            throw AForm::GradeTooHighException();
        else if (this->_signGrade > 150 || this->_executionGrade > 150)
            throw AForm::GradeTooLowException();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
};

AForm::AForm(const AForm& copy): _name(copy._name), _signGrade(copy._signGrade), _executionGrade(copy._executionGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
    *this = copy;
};

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
};

AForm& AForm::operator=(const AForm& op)
{
    std::cout << "AForm assignation operator called" << std::endl;
    if (this != &op)
        this->_signed = op.getSigned();
    return *this;
};

std::string AForm::getName(void) const
{
    return this->_name;
};

bool AForm::getSigned(void) const
{
    return this->_signed;
};

int AForm::getSignGrade(void) const
{
    return this->_signGrade;
};

int AForm::getExecutionGrade(void) const
{
    return this->_executionGrade;
};

void	AForm::beSigned(const Bureaucrat& bur)
{
		if (!this->_signed && (bur.getGrade() <= this->_signGrade))
			this->_signed = true;
		else if (this->_signed)
            throw AForm::SignedException();
        else if(bur.getGrade() > this->getSignGrade())
            throw AForm::GradeTooLowException();
}

void AForm::checkExecution(Bureaucrat const& executor) const
{
		if (!this->_signed)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > this->_executionGrade)
			throw Bureaucrat::GradeTooLowException();
        else 
            return ;
};

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high in AForm";
};

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low in AForm";
};

const char* AForm::SignedException::what() const throw()
{
    return "Form is signed, if you sign it again it will be invalid!";
};

const char*	AForm::NotSignedException::what() const throw()
{
		return "Form not signed, whitout the sign it will be invalid!";
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << rhs.getName() << ": " << std::endl;
	if (rhs.getSignGrade() >= 1 && rhs.getSignGrade() <= 150)
		os << rhs.getSignGrade() << " sign grade" << std::endl;
	else
		os << "Error invalid sign grade!" << std::endl;
	return os;
}

