#include <iostream>
#include "Extra.hpp"

int main()
{
    /*
    int Widht, Height;
    std::cin>>Widht;
    std::cin>>Height;
    FunInPPM(Widht, Height);
    system("X:/ОП_21/SaviukArseniy/ppmViewer/bin/DebugMain.exe ./data/texture/FirstTest.ppm");
    */
    
    std::string F = "x=2*y";
    int y = 0;
    int x;
    for (int i = -5; i < 5; i++)
    {
        x = i;
        std::cout<<"x = 2 * y"<<"\tx = "<<x<<"\ty = "<<y<<"\n";
    }
    
    
    return 0;
}