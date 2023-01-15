#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <limits>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Convert{

public:
        Convert();
        Convert (const Convert & src);
        ~Convert(void);
        Convert & operator=(Convert const & value);

        void toChar(const char inputCast);
        void toInt(int inputCast);
        void toFloat(float inputCast);
        void toDouble(double inputCast);
        int isFloat(std::string input);
        int isDouble(std::string input);
        int isChar(std::string input);
        int isInt(std::string input);

        int isValidInput(std::string input);
        
        void overflowRange(std::string input);
        int isExceptions(std::string input);
private:
        bool _isIntType;
        bool _isCharType;
        bool _isFloatType;
        bool _isDoubleType;
        bool _isSpecial;
        bool _outOfRange;
        bool _outOfRangeChar;
};

#endif
