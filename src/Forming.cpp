#include "Extra.hpp"
#include <iostream>
#include <fstream>

int Forming()
{
    std::fstream myFile("./src/Formula.txt", std::fstream::in);

    if (!(myFile.is_open()))
    {
        std::cout<<"Error dont open File F.cpp\n";
        return 1;
    }

    int For;
    myFile>>For;

    myFile.close();

    for (int x = -5; x <= 5; x++)
        {
            double y = For;
            std::cout<<"y = "<<y<<"\n";
        }
    return 0;
}