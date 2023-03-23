#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <algorithm>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

typedef struct s_data{
        int _year;
        int _month;
        int _day;
        float _value;
}               t_data;


class BitcoinExchange{

public:
        BitcoinExchange(std::string fileName);
        BitcoinExchange (const BitcoinExchange & src);
        ~BitcoinExchange(void);
        BitcoinExchange & operator=(BitcoinExchange const & value);

        void setFileName(const std::string & name);
        const std::string & getFileName();
        int checkFile();
        void addData();
        void parseDate(std::string tmp, std::string line);

        void searchData(unsigned long date);          


        void initData(unsigned long date, int year, int month, int day, float value);
        void initCsv(unsigned long date, int year, int month, int day, float value);

        std::map<unsigned long, t_data> dateValue;
        std::map<unsigned long, t_data> csvData;


        class InvalidFormat : public std::exception
        {
        public:
                

                virtual const char* what() const throw()
                {
                        return "Invalid Format\n";
                }
        };
        class InvalidDate : public std::exception
        {
        public:
                InvalidDate(const std::string& date) : _date(date) {}

        virtual const char* what() const throw() {
                std::cout << "Invalid date: " + _date;
                return "\n";
        }
        virtual ~InvalidDate() throw() {}

        private:
                std::string _date;
        };

         class InvalidValue : public std::exception
        {
        public:
                InvalidValue(const std::string& value) : _value(value) {}

        virtual const char* what() const throw() {
                std::cout << "Invalid value: " + _value;
                return "\n";
        }
        virtual ~InvalidValue() throw() {}

        private:
                std::string _value;
        };
	
private:
       std::string date;
       int year;
       int month;
       int day;
       std::string file;
       unsigned long date_int;
};

#endif
