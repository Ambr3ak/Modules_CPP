#include "RPN.hpp"
#include <sstream> 

static size_t stringtoint(std::string c){
    std::istringstream is(c);
    int i;

    is >> i;
    return i;
}

RPN::RPN(void){
    std::cout << COLOR_GREEN << "[RPN] Constructor called." << COLOR_END << std::endl;
}

RPN::RPN(const RPN & src){
    std::cout << COLOR_YELLOW << "[RPN] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

RPN::~RPN(void){
    std::cout << COLOR_RED << "[RPN] Destructor called" << COLOR_END << std::endl;
}

RPN & RPN::operator=(RPN const & value) {

    std::cout << COLOR_YELLOW << "[RPN] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}

int RPN::parseString(){
    std::string tmpNum;
    int countNum = 0;
    int countOp = 0;
    for (std::string::iterator it = _calculLine.begin(); it != _calculLine.end(); ++it){
        if (!isdigit(*it) && (*it) != '/' && (*it) != '*' && (*it) != '+' && (*it) != '-' && (*it) != ' ')
            return -1;
    }
    for (std::string::iterator it = _calculLine.begin(); it != _calculLine.end(); ++it){
        if ((*it) != ' ')
            tmpNum += (*it);
        else
            tmpNum = "";
        if (tmpNum.size() > 1){
            // if (tmpNum.size() == 2 && (*tmpNum.begin()) == '-'){
            //     ;
            // }
            // else{
                return -1;
            // }
        }
        if (isdigit(*it))
            countNum++;
        else if (*it != ' ')
            countOp++;
    }
    if (countNum != countOp + 1)
        return -1;
    return 0;
}

int RPN::isOperation(char it){
    return (it == '+' || it == '-' || it == '/' || it == '*' );
}

int RPN::doOperation(int num1, int num2, char op){
    int result = 0;
    if (op == '+')
        result = num1 + num2;
    if (op == '-')
        result = num1 - num2;
    if (op == '/')
        result = num1 / num2;
    if (op == '*')
        result = num1 * num2;
    stackNum.pop();
    return (result);
}

void RPN::executeCalcul(char *arg){

    this->_calculLine = arg;
    std::string tmpNum;
    int result;
    int tmp2;

    if (parseString() == -1)
        throw InvalidFormat();
    else{
        for (std::string::iterator it = _calculLine.begin(); it != _calculLine.end(); ++it){
            if (isdigit(*it)){
                tmpNum = *it;
                stackNum.push(stringtoint(tmpNum));
            }
            else if (isOperation(*it)){
                if (stackNum.size() >= 2){
                    tmp2 = stackNum.top();
                    stackNum.pop();
                    result = doOperation(stackNum.top(),tmp2, *it);
                    stackNum.push(result);
                }
            }
        }
    }
    std::cout << stackNum.top() << std::endl;
}