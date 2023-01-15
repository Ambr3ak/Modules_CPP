#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() : _type("Base"){
    std::cout << COLOR_GREEN << "[Base] Constructor called." << COLOR_END << std::endl;
}

Base::Base(std::string type) : _type(type){
    std::cout << COLOR_GREEN << "[Base] Param Constructor called." << COLOR_END << std::endl;
}


Base::~Base(void){
    std::cout << COLOR_RED << "[Base] Destructor called" << COLOR_END << std::endl;
}


Base * Base::generate(void){
    srand((unsigned) time(0));
    int classNumber = 1 + (rand() % 3);
    std::cout <<"random class number = " << classNumber << std::endl;
    switch(classNumber){
        case 1 :
            return new A("A");
        case 2 :
            return new B("B");
        case 3 :
            return new C("C");
        default :
            std::cout << "Error" << std::endl;
        break ;
    }
    return NULL;
}

void Base::identify(Base* p){
    A * castTest = dynamic_cast<A *>(p);
    if (castTest == NULL)
        std::cout << "Conv not ok" << std::endl;
    else
    {
        std::cout << castTest->_type << std::endl;
        return;
    }
    B * castTest1 = dynamic_cast<B *>(p);
    if (castTest1 == NULL)
        std::cout << "Conv not ok" << std::endl;
    else
    {
        std::cout << castTest1->_type << std::endl;
        return;
    }
    C * castTest2 = dynamic_cast<C *>(p);
    if (castTest2 == NULL)
        std::cout << "Conv not ok" << std::endl;
    else
    {
        std::cout << castTest2->_type << std::endl;
        return;
    }
    return ;
}

void Base::identify(Base& p){
    try{
        A & castTest = dynamic_cast<A &>(p);
        std::cout << castTest._type << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        B & castTest = dynamic_cast<B &>(p);
        std::cout << castTest._type << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        C & castTest = dynamic_cast<C &>(p);
        std::cout << castTest._type << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}