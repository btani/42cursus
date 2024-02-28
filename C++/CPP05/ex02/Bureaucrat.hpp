/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:19 by btani             #+#    #+#             */
/*   Updated: 2024/02/19 16:09:00 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
    std::string const _name;
    int _grade;
    
    public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat(void);

    Bureaucrat& operator=(const Bureaucrat& op);

    std::string getName(void) const;
    int getGrade(void) const;
    void incrementation(int nbr);
    void decrementation(int nbr);
    void signForm(AForm& f) const;
    void executeForm(const AForm& form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
