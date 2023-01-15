#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{   
//TEST GRADE OK
    try{
        Form form1 = Form("Form1", 1, 4);
        std::cout << form1;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------\n"; 
//TEST GRADE 0
    try{
        Form form2 = Form("Form2", 0, 0);
        std::cout << form2;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------\n"; 
//TEST GRADE TOO HIGH
    try{
        Form form2 = Form("Form2", 151, 7);
        std::cout << form2;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------\n"; 
//TEST SIGNED
    Form *form3 = new Form("Form3", 15, 100);
    Form *form4 = new Form("Form4", 3, 100);
    Bureaucrat *bob = new Bureaucrat("Bobby", 5);
    Bureaucrat *Rob = new Bureaucrat("Robby", 51);
    std::cout << *form3;
    try{
        bob->signForm(*form3);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << *form3;
//TEST ALREADY SIGNED
    std::cout << "---------\n"; 
    try{
        Rob->signForm(*form3);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------\n"; 
//TEST GRADE TOO LOW TO SIGN
    std::cout << *form4;
    try{
       Rob->signForm(*form4);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << *form4;
    delete bob;
    delete form3;
    delete Rob;
    delete form4;
    return 0;
}