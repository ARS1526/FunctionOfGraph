#include "Extra.hpp"
#include <iostream>

int Forming()
{
    for (int x = -5; x <= 5; x++)
        {
            double y = F(x);
            std::cout<<"y = "<<y<<"\n";
        }
}