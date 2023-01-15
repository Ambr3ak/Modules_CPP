#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    AAnimal *objs[4];

    for (int i = 0; i < 4; i++)
    {
        if (i < 5)
            objs[i] = new Dog;
        else
            objs[i] = new Cat;
        objs[i]->makeSound();
    }
    
    for (int i = 0; i < 4; i++)
    {
        std::cout << objs[i]->getType() << std::endl;
        objs[i]->getBrain()->setIdea("attack human");
        objs[i]->getBrain()->setIdea("eat food");
        objs[i]->getBrain()->setIdea("play");
        objs[i]->getBrain()->setIdea("sleep");
        objs[i]->getBrain()->getIdeas();
    }


    std::cout << "CREATING NEW ORIGINAL DOG" << std::endl;
    Dog *originalDog = new Dog;

    std::cout << originalDog->getType() << std::endl;
    originalDog->getBrain()->setIdea("bark");
    originalDog->getBrain()->getIdeas();


    std::cout << "MODIF ORIGINAL DOG" << std::endl;
    originalDog->getBrain()->setIdea("bark again");

    std::cout << "CREATING COPY CONSTRUCTOR DOG" << std::endl;
    
    Dog copyDog2(*originalDog);

    std::cout << copyDog2.getType() << std::endl;
    copyDog2.getBrain()->setIdea("sleep");
    copyDog2.getBrain()->getIdeas();

    std::cout << "MODIF ORIGINAL DOG" << std::endl;
    originalDog->getBrain()->setIdea("play");

    std::cout << "PRINT COPY OF DOG" << std::endl;
    copyDog2.getBrain()->getIdeas();

    std::cout << "PRINT ORGINAL DOG" << std::endl;
    originalDog->getBrain()->getIdeas();


    for (int i = 0; i < 4; i++)
    {
        delete objs[i];
    }
    delete originalDog;
    return 0;
}