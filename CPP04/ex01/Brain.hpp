#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Brain{

public:
        Brain(void);
        Brain (const Brain & src);
        virtual ~Brain(void);
        Brain & operator=(Brain const & value);

        int index;
        void setIdea(std::string idea);
        void getIdeas(void);

protected:
        std::string _ideas[100];
};

#endif
