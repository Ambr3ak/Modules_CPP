#include "MutantStack.hpp"

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        std::cout <<  "Last stack = " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size = " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::list<int> lstack;
        lstack.push_back(1);
        lstack.push_back(2);
        std::cout << "Last stack = " << lstack.back() << std::endl;
        lstack.pop_back();
        std::cout << "Size = " << lstack.size() << std::endl;
        lstack.push_back(3);
        lstack.push_back(4);
        lstack.push_back(5);
        lstack.push_back(0);
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
    }
    {
        std::cout << "Mutantstack reverse_iterator" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        mstack.push(0);
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();
        ++rit;
        --rit;
        while (rit != ite)
        {
        std::cout << *rit << std::endl;
        ++rit;
        }
    }
    {
        std::cout << "List reverse_iterator" << std::endl;
        std::list<int> mstack;
        mstack.push_back(1);
        mstack.push_back(2);
        mstack.push_back(3);
        mstack.push_back(4);
        mstack.push_back(5);
        mstack.push_back(0);
        std::list<int>::reverse_iterator rit = mstack.rbegin();
        std::list<int>::reverse_iterator ite = mstack.rend();
        ++rit;
        --rit;
        while (rit != ite)
        {
        std::cout << *rit << std::endl;
        ++rit;
        }
    }
    return 0;
}