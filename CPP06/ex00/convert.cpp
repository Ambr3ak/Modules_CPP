#include "convert.hpp"

Convert::Convert(void): _isIntType(true), _isCharType(false), _isFloatType(false), _isDoubleType(false), _isSpecial(false), _outOfRange(false), _outOfRangeChar(false){
    std::cout << COLOR_GREEN << "[Convert] Constructor called." << COLOR_END << std::endl;
}

Convert::Convert(const Convert & src){
    std::cout << COLOR_YELLOW << "[Convert] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Convert::~Convert(void){
    std::cout << COLOR_RED << "[Convert] Destructor called" << COLOR_END << std::endl;
}

Convert & Convert::operator=(Convert const & value) {

    std::cout << COLOR_YELLOW << "[Convert] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_isCharType = value._isCharType;
        this->_isDoubleType = value._isDoubleType;
        this->_isFloatType = value._isFloatType;
        this->_isIntType = value._isIntType;
        this->_isSpecial = value._isSpecial;
        this->_outOfRange = value._outOfRange;
        this->_outOfRangeChar = value._outOfRangeChar;
    }
    return *this;
}

void Convert::toChar(const char inputCast)
{
    if ((inputCast >= 32 && inputCast <= 127) && !_outOfRangeChar)
        std::cout << "char : '" << static_cast<char>(inputCast) << "'" << std::endl;
    else if ((inputCast >= 0 && inputCast <= 31) && !_isSpecial && !_outOfRangeChar)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : impossible" << std::endl;
    return ;
}

void Convert::toInt(int inputCast)
{
    if (_outOfRange)
        std::cout << "int : Out of range" << std::endl;
    else if (_isSpecial)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << inputCast << std::endl;
}

void Convert::toFloat(float inputCast)
{
    if (std::fmod(inputCast, 1) == 0)
        std::cout << "float : " << inputCast << ".0f" << std::endl;
    else
        std::cout << "float : " << inputCast << "f" << std::endl;
}

void Convert::toDouble(double inputCast)
{
    if (std::fmod(inputCast, 1) == 0)
        std::cout << "double : " << inputCast << ".0" << std::endl;
    else
        std::cout << "double : " << inputCast << std::endl;

}

int Convert::isFloat(std::string input)
{
    char *endptr;
    float inputCast = std::strtof(input.c_str(), &endptr);
    toChar(static_cast<char>(inputCast));
    toInt(static_cast<int>(inputCast));
    toFloat(inputCast);
    toDouble(static_cast<double>(inputCast));
    return (1);
}

int Convert::isDouble(std::string input)
{
    char *endptr;
    double inputCast = std::strtod(input.c_str(), &endptr);
    toChar(static_cast<char>(inputCast));
    toInt(static_cast<int>(inputCast));
    toFloat(static_cast<float>(inputCast));
    toDouble(inputCast);
    return (1);
}

int Convert::isChar(std::string input)
{
    _isCharType = true;
    toChar(input[0]);
    toInt(static_cast<int>(input[0]));
    toFloat(static_cast<float>(input[0]));
    toDouble(static_cast<double>(input[0]));
    return (1);
}
int Convert::isInt(std::string input)
{
    char *endptr;
    double inputCast = std::strtod(input.c_str(), &endptr);
    toChar(static_cast<char>(inputCast));
    toInt(static_cast<int>(inputCast));
    toFloat(static_cast<float>(inputCast));
    toDouble(static_cast<double>(inputCast));
    return (1);
}

void Convert::overflowRange(std::string input)
{
    char *endptr;
    double inputCast = std::strtod(input.c_str(), &endptr);

    if (inputCast < std::numeric_limits<int>::min() || inputCast > std::numeric_limits<int>::max())
       _outOfRange = true;
    if (inputCast < 0 || inputCast > 127)
        _outOfRangeChar = true;
}

int Convert::isValidInput(std::string input){

    int n = input.size();
    int i = 0;

    if (n == 1 && ((input[0] >= 31 && input[0] <= 47) || (input[0] >= 58 && input[0] <= 127)))
        return (isChar(input));
    if (input [0] == '-' ||input [0] == '+')
        i++;
    while (i < n && std::isdigit(input[i]))
        i++;
    if (input[i] == '.')
    {
        _isIntType = false;
        i++;
        while (i < n && std::isdigit(input[i]))
            i++;
    }
    if (input[i] == 'f' && input[i + 1] == '\0')
        _isFloatType = true;
    else if (i == n)
        _isDoubleType = true;
    else if (input[i] != '\0')
        return (0);
    overflowRange(input);
    if (_isFloatType == true)
        return (isFloat(input));
    if (_isIntType == true)
        return (isInt(input));
    if (_isDoubleType == true)
        return (isDouble(input));
    return (0);
}

int Convert::isExceptions(std::string input){

    if (input == "nan" || input == "+inf" || input == "-inf" )
    {
        _isSpecial = true;
        return (isDouble(input));
    }
    else if (input == "nanf" || input == "+inff" || input == "-inff")
    {
        _isSpecial = true;
        return (isFloat(input));
    }
    return (0);
}