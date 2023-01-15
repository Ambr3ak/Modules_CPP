#include "Span.hpp"
#include <list>
#include <vector>

void displayInt(int i)
{
	std::cout << i << ", ";
}

int main()
{
    {
        std::cout << COLOR_YELLOW << "Try with subject main" << COLOR_END << std::endl;
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(45);
        sp.addNumber(7);
        sp.addNumber(8);
        sp.addNumber(12);   

        std::for_each(sp.getArray().begin(), sp.getArray().end(), displayInt);
        std::cout << std::endl;
        std::cout << "Longest = " << sp.longestSpan() << std::endl;
        std::cout << "Shortest = " << sp.shortestSpan() << std::endl;
    }

    {   
        std::cout << COLOR_YELLOW << "Try with vector of 100 000" << COLOR_END << std::endl;
        std::vector<int> l;
        std::vector<int>::iterator begin;
        std::vector<int>::iterator end;
        srand((unsigned) time(0));
        for (int i = 0; i < 100000; i++){
            l.push_back(rand() % 10000000);
        }
        begin = l.begin();
        end = l.end();
        Span sp2 = Span(100000);
        try
        {
            sp2.addNumberFromT<std::vector<int> >(begin, end);
            std::cout << "Longest = " << sp2.longestSpan() << std::endl;
            std::cout << "Shortest = " << sp2.shortestSpan() << std::endl;
        }
        catch (std::exception &e){
            std::cout << e.what();
        }
    }

    {   
        std::cout << COLOR_YELLOW << "Try with list of 100 with full array" << COLOR_END << std::endl;
        std::list<int> l;
        std::list<int>::iterator begin;
        std::list<int>::iterator end;
        srand((unsigned) time(0));
        for (int i = 0; i < 100; i++){
            l.push_back(rand() % 150);
        }
        begin = l.begin();
        end = l.end();
        Span sp2 = Span(100);
        sp2.addNumber(3);
        try{

            sp2.addNumberFromT<std::list<int> >(begin, end);
            std::for_each(sp2.getArray().begin(), sp2.getArray().end(), displayInt);
            std::cout << std::endl;
            std::cout << "Longest = " << sp2.longestSpan() << std::endl;
            std::cout << "Shortest = " << sp2.shortestSpan() << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what();
        }
    }

    {
        std::cout << COLOR_YELLOW << "Try with full array" << COLOR_END << std::endl;
        Span sp = Span(2);
       
        try{
            sp.addNumber(7);
            sp.addNumber(8);
            sp.addNumber(12); 
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }
    {
        std::cout << COLOR_YELLOW << "Try with 1 value" << COLOR_END << std::endl;
        Span sp = Span(2);
       
        try{
            sp.addNumber(7);
            sp.shortestSpan();
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }
     {
        std::cout << COLOR_YELLOW << "Try with empty span" << COLOR_END << std::endl;
        Span sp = Span();
       
        try{
            sp.addNumber(7);
            sp.shortestSpan();
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }
    {
        std::cout << "Deep copy\n";
        Span sp = Span(5);

        sp.addNumber(10);
        sp.addNumber(1);
        sp.addNumber(100);
        sp.addNumber(1000);
        Span sp2(sp);

        sp2.addNumber(8);
        std::cout << &sp << std::endl;
        std::for_each(sp.getArray().begin(), sp.getArray().end(), displayInt);
        std::cout << std::endl;
        std::cout << &sp2 << std::endl;
        std::for_each(sp2.getArray().begin(), sp2.getArray().end(), displayInt);
        std::cout << std::endl;

    }
    return 0;
}