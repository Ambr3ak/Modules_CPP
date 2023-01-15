#include <iostream>
#include <stdint.h>

struct Data{
    int var1;
    int var2;
    int var3;
    std::string var4;
};

uintptr_t serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data *dataTest = new Data;
    Data *pointeurData;
    uintptr_t returnData;

    std::cout << "Original Data pointer : " << dataTest << std::endl;
    returnData = serialize(dataTest);
    pointeurData = deserialize(returnData);
    std::cout << "Return from deserialize pointer Data : " << pointeurData << std::endl;

    delete dataTest;
    return 0;
}