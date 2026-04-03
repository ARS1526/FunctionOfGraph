#include <iostream>
#include "Extra.hpp"

int main()
{
    int Widht, Height;
    std::cin>>Widht;
    std::cin>>Height;
    FunInPPM(Widht, Height);
    system("C:/Users/doris/OneDrive/Documents/BackApp1/ppmViewer/bin/DebugMain.exe ./data/texture/FirstTest.ppm");
    return 0;
}