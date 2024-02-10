/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:31:45 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:32:36 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iomanip>
# include <iostream>
# include <string>

class Harl
{
    private:

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    public:
    
    Harl( void );
    ~Harl( void );

    void complain( std::string level );
};

#endif
