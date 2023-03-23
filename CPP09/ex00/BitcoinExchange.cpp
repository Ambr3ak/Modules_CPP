#include "BitcoinExchange.hpp"
#include <sstream> 

static size_t stringtoint(std::string toConvert){
    std::istringstream is(toConvert);
    int i;

    is >> i;
    return i;
}


BitcoinExchange::BitcoinExchange(std::string fileName): year(0), month(0), day(0), file(fileName), date_int(0){
    std::cout << COLOR_GREEN << "[BitcoinExchange] Constructor called." << COLOR_END << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src){
    std::cout << COLOR_YELLOW << "[BitcoinExchange] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

BitcoinExchange::~BitcoinExchange(void){
    std::cout << COLOR_RED << "[BitcoinExchange] Destructor called" << COLOR_END << std::endl;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & value) {

    std::cout << COLOR_YELLOW << "[BitcoinExchange] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
       this->date = value.date;
       this->year = value.year;
       this->month = value.month;
       this->day = value.day;
       this->file = value.file;
       this->date_int = value.date_int;
    }
    return *this;
}

//         //
//FONCTIONS//
//         //

void BitcoinExchange::setFileName(const std::string & name){
    this->file = name;
}

const std::string & BitcoinExchange::getFileName(){
   return (file);
}

void BitcoinExchange::initData(unsigned long date, int year, int month, int day, float value)
{
    dateValue[date]._year = year;;
    dateValue[date]._month = month;;
    dateValue[date]._day = day;;
    dateValue[date]._value = value;
}

void BitcoinExchange::initCsv(unsigned long date, int year, int month, int day, float value)
{
    csvData[date]._year = year;;
    csvData[date]._month = month;;
    csvData[date]._day = day;;
    csvData[date]._value = value;
}

void BitcoinExchange::searchData(unsigned long date){
    std::map<unsigned long, t_data>::iterator it;

    for (it = csvData.begin(); it != csvData.end(); ++it) {
        if (date < it->first)
        {
            std::cout << "Date too old" << std::endl;
            return;
        }
        while (it->first <= date)
        {
            if (it->first == date)
            {
                std::cout << this->date << " => " << dateValue[date]._value << " = " << (csvData[(it)->first]._value * dateValue[date]._value) << std::endl;
                return ;
            }
            ++it;
        }
        unsigned long tmp = (--it)->first;
        if (tmp)
        {
            std::cout << this->date << " => " << dateValue[date]._value << " = " << (csvData[tmp]._value * dateValue[date]._value) << std::endl;
            return;
        }
    }
 
}

void BitcoinExchange::parseDate(std::string tmp, std::string line){

    size_t pos;
    int count = 0;
    if (tmp.size() != 10)
        throw InvalidDate(this->date);
    for (std::string::iterator it = tmp.begin(); it != tmp.end(); ++it)
        if (!isdigit(*it) && (*it) != '-')
            throw InvalidDate(this->date);
    while ((pos = tmp.find("-")) != std::string::npos){
        if (this->year == 0){
            this->year = stringtoint(tmp.substr(0, pos));
            if (this->year < 0 || this->year > 2023)
                throw InvalidDate(this->date);
        }
        else if (this->month == 0){
            this->month = stringtoint(tmp.substr(0, pos));
            if (this->month < 1 || this->month > 12 )
                throw InvalidDate(this->date);
        }
        tmp.erase(0, pos + 1);
        count++;
    }
    if (this->day == 0){
        this->day = stringtoint(tmp.substr(0, pos));
        switch (this->month) {
            case 2:
                if (this->day < 1 || this->day > 28 )
                    throw InvalidDate(this->date);
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (this->day < 1 || this->day > 30 )
                    throw InvalidDate(this->date);
                break;
            default:
                if (this->day < 1 || this->day > 31 )
                    throw InvalidDate(this->date);
        }
    }
    if (count != 2)
        throw InvalidDate(this->date);
    else if (std::atof(line.c_str()) < 0 || std::atof(line.c_str()) > 1000)
        throw InvalidValue(line);

}


int BitcoinExchange::checkFile(){
    std::ifstream ifs(this->file.c_str());
    std::string line;
    std::string tmp;
    size_t pos;

    while (std::getline(ifs, line)){
        if ((pos = line.find(" | ")) != std::string::npos){

            this->date = line.substr(0, pos);
            std::string date_str;
            if (this->date != "date")
            {
                date_str = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2); 
                date_int = stringtoint(date_str);
                tmp = this->date;
                line.erase(0, pos + 3);
                try{
                    parseDate(tmp, line);
                    initData(date_int, year, month, day, std::atof(line.c_str()));
                    searchData(date_int);
                }
                catch  (std::exception & e){
                    std::cout << e.what();
                }
                this->year = 0;
                this->month = 0;
                this->day = 0;
            }
        }
        else
            std::cout << "Invalid Format => " << line << std::endl;
    }
    return 0;
}

void BitcoinExchange::addData(){
    std::ifstream ifs("data.csv");

    if (!ifs.is_open())
        std::cout << "No file name data.csv" << std::endl;
    else{
        std::string date;
        size_t pos = 0;
        std::string line;
        std::string tmp;
        std::string date_str;

        while (std::getline(ifs, line)){
            if ((pos = line.find(",")) != std::string::npos) {
                date = line.substr(0, pos);
                tmp = date;
                if (date != "date")
                {
                    date_str = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2); 
                    date_int = stringtoint(date_str);
                    line.erase(0, pos + 1);
                    try{
                        parseDate(tmp, line);
                        initCsv(date_int, year, month, day, std::atof(line.c_str()));
                    }
                    catch  (std::exception & e){
                        throw InvalidDate("20202");
                    }
                    this->year = 0;
                    this->month = 0;
                    this->day = 0;
                }
            }
        }
    }
}