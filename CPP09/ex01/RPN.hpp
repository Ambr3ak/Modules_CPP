#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class RPN{

public:
        RPN();
        RPN (const RPN & src);
        ~RPN(void);
        RPN & operator=(RPN const & value);

    
        int parseString();
        void executeCalcul(char *arg);
        int isOperation(char it);

        int doOperation(int num1, int num2, char op);
class InvalidFormat : public std::exception
        {
        public:
                

                virtual const char* what() const throw()
                {
                        return "Invalid Format\n";
                }
        };
private:

        std::string _calculLine;

        std::stack<int> stackNum;
       
};

#endif
