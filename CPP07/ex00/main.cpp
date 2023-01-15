#include "whatever.hpp"

int main()
{
    {
        std::cout << "*********** INT ***********" << std::endl;
        int a = 21;
        int b = 42;

        std::cout << "Max of " << a << " and " << b << " is ";
        std::cout << max<int>(a, b) << std::endl;
        std::cout << "Min of " << a << " and " << b << " is ";
        std::cout << min<int>(a, b) << std::endl;
        std::cout << "Swap of a = " << a << " and b =  " << b << std::endl;
        swap<int>(a, b);
        std::cout << "Now a = " << a << " and b = " << b << std::endl;


        std::cout << "*********** FLOAT ***********" << std::endl;
        float c = 432.90f;
        float d = 56.0213f;

        std::cout << "Max of " << c << " and " << d << " is ";
        std::cout << max<float>(c, d) << std::endl;
        std::cout << "Min of " << c << " and " << d << " is ";
        std::cout << min<float>(c, d) << std::endl;
        std::cout << "Swap of c = " << c << " and d =  " << d << std::endl;
        swap<float>(c, d);
        std::cout << "Now c = " << c << " and d = " << d << std::endl;

        std::cout << "*********** CHAR ***********" << std::endl;
        char e = 'K';
        char f = 'D';

        std::cout << "Max of " << e << " and " << f << " is ";
        std::cout << max<char>(e, f) << std::endl;
        std::cout << "Min of " << e << " and " << f << " is ";
        std::cout << min<char>(e, f) << std::endl;
        std::cout << "Swap of e = " << e << " and f =  " << f << std::endl;
        swap<char>(e, f);
        std::cout << "Now e = " << e << " and f = " << f << std::endl;

        std::cout << "*********** DOUBLE ***********" << std::endl;
        double g = 5494847373834948474738393.0387;
        double h = -5494847373834948474738393.0387;

        std::cout << "Max of " << g << " and " << h << " is ";
        std::cout << max<double>(g, h) << std::endl;
        std::cout << "Min of " << g << " and " << h << " is ";
        std::cout << min<double>(g, h) << std::endl;
        std::cout << "Swap of g = " << g << " and h =  " << h << std::endl;
        swap<double>(g, h);
        std::cout << "Now g = " << g << " and h = " << h << std::endl;
    }
    {
        std::cout << "*********** TEST MAIN ***********" << std::endl;
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return 0;
}