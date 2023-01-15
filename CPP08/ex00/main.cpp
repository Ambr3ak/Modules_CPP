#include "easyfind.hpp"

void displayInt(int i)
{
	std::cout << i << ", ";
}

int main()
{
    {
        std::vector<int> v;
        std::vector<int>::iterator it;

        v.push_back(10);
        v.push_back(90);
        v.push_back(20);
        v.push_back(40);
        v.push_back(60);
        v.push_back(1);

        std::for_each(v.begin(), v.end(), displayInt);
        try{
            it = easyfind(v, 20);
            std::cout << "Value found is = "<< (*it)  << std::endl;
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }

    {
        std::list<int> l;
        std::list<int>::iterator it;

        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        l.push_back(5);
        l.push_back(6);

        std::for_each(l.begin(), l.end(), displayInt);
        try{
            it = easyfind(l, 2);
            std::cout << "Value found is = " << *it << std::endl;;
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }
    {
        std::deque<int> d;
        std::deque<int>::iterator it;

        d.push_back(113);
        d.push_back(7064);
        d.push_back(322);
        d.push_back(9063);
        d.push_back(552);
        d.push_back(434);

        std::for_each(d.begin(), d.end(), displayInt);
        try{
            it = easyfind(d, 113);
            std::cout << "Value found is = " << *it << std::endl;;
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }
    {
        std::deque<int> d;
        std::deque<int>::iterator it;

        d.push_back(113);
        d.push_back(7064);
        d.push_back(322);
        d.push_back(9063);
        d.push_back(552);
        d.push_back(434);

        std::for_each(d.begin(), d.end(), displayInt);
        try{
            it = easyfind(d, 0);
            std::cout << "Value found is = " << *it << std::endl;;
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
    }
    return 0;
}