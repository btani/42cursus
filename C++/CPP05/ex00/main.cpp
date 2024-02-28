#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat first("First", 65);
    Bureaucrat second("Second", 150);
    //exceptions
    Bureaucrat third("Third", -20);
    Bureaucrat fourth("Fourth", 300);

    std::cout << std::endl;

    std::cout << first;
    std::cout << second;
    std::cout << third;
    std::cout << fourth;

    std::cout << std::endl;

    std::cout << "Incrementation -50: " << std::endl;
    first.incrementation(50);
    second.incrementation(50);
    third.incrementation(50);
    fourth.incrementation(50);
    std::cout << first;
    std::cout << second;
    std::cout << third;
    std::cout << fourth;

    std::cout << std::endl;

    std::cout << "Decrementation +5: " << std::endl;
    first.decrementation(5);
    second.decrementation(5);
    third.decrementation(5);
    fourth.decrementation(5);
    std::cout << first;
    std::cout << second;
    std::cout << third;
    std::cout << fourth;
    std::cout << std::endl;
}