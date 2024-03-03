/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:27:28 by btani             #+#    #+#             */
/*   Updated: 2024/03/03 11:33:54 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

//template definition
template<typename T>
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main(void)
{ 
  int slot[] = {1, 2, 3, 4, 5};
  const char *arrStr[] = {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi"};
  int slotSize = sizeof(slot) / sizeof(int);
  int arrSize = sizeof(arrStr) / sizeof(const char*);
  
  std::cout << "Iteration of function 'print' on slot's elements" << std::endl;
  iter(slot, slotSize, print<const int>); //implicit instanciation
  std::cout << std::endl;
  iter(arrStr, arrSize, print<const char*>); //implicit instanciation

  return 0;
}

/*class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}*/
