#include <iostream>
#include <fstream>
#include <string>
#include "Extra.hpp"

int FInFile(std::string args);

int main(int argc, char** argv)
{

    if(FInFile(argv[1]) == 1) std::cerr<<"Fuction not saved";

    int Widht, Height;
    Widht = 500;//*argv[2];
    Height = 500;//*argv[3];
    FunInPPM(Widht, Height);
    system("X:/ОП_21/SaviukArseniy/ppmViewer/bin/DebugMain.exe X:/ОП_21/SaviukArseniy/FunctionOfGraph/data/texture/FirstTest.ppm");
    
    return 0;
}

int FInFile(std::string args)
{
    std::fstream myFile("./src/F.cpp", std::fstream::out | std::fstream::binary | std::fstream::in);

    if (!(myFile.is_open()))
    {
        std::cout<<"Error dont open File F.cpp\n";
        return 1;
    }

    std::string temp;
    bool Flag = true;
    while(myFile>>temp)
    {
        if (temp=="return") 
        {
            myFile<<' ';
            myFile<<args;
            myFile<<";}";
            Flag = false;
        }
    }
    if(Flag == true)return 1;
    myFile.clear();
    myFile.close();
    return 0;
}

