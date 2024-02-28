/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:05 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 17:34:57 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <exception>

class Bureaucrat;
class AForm
{
    private:
    std::string const _name;
    bool _signed;
    int const _signGrade;
    int const _executionGrade;

    public:
    AForm(void);
    AForm(std::string name, int signGrade, int executionGrade);
    AForm(const AForm& copy);
    virtual ~AForm(void);

    AForm& operator=(const AForm& op);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getSignGrade(void) const;
    int getExecutionGrade(void) const;
    void beSigned(const Bureaucrat& bur);
    virtual void execute(Bureaucrat const& executor) const = 0;
    void checkExecution(Bureaucrat const& executor) const;

    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    class SignedException : public std::exception
    {
	    public:
		virtual const char* what() const throw();
	};
    
	class NotSignedException : public std::exception
    {
	    public:
		virtual const char* what() const throw();
	};
    
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
