#include <iostream>

#include "Base.hpp"

int main()
{
    Base *random = new Base();
    Base *newRandom = random->generate();

    random->identify(newRandom);
    random->identify(*newRandom);

    delete random;
    delete newRandom;
    return 0;
}