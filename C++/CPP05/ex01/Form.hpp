/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:11:24 by btani             #+#    #+#             */
/*   Updated: 2024/02/18 15:11:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;
class Form
{
    private:
    std::string const _name;
    bool _signed;
    int const _signGrade;
    int const _executionGrade;

    public:
    Form(void);
    Form(std::string name, int signGrade, int executionGrade);
    Form(const Form& copy);
    ~Form(void);

    Form& operator=(const Form& op);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getSignGrade(void) const;
    int getExecutionGrade(void) const;
    void beSigned(const Bureaucrat& bur);

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
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif
