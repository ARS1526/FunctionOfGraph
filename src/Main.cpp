#include <iostream>
#include <fstream>
#include <string>
#include "Extra.hpp"

int FInFile(std::string args);

int main(int argc, char** argv)
{

    if(FInFile(argv[1]) == 1) std::cerr<<"Fuction not saved";

    int Widht, Height;
    Widht = std::stoi(argv[2]);
    Height = std::stoi(argv[3]);
    FunInPPM(Widht, Height);
    system("C:/Users/doris/OneDrive/Documents/BackApp1/ppmViewer/bin/DebugMain.exe C:/Users/doris/OneDrive/Documents/BackApp1/FunctionGraph/data/texture/FirstTest.ppm");

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

/*
int FInFile(std::string args)
{
    std::fstream myFile("./src/Formula.txt", std::fstream::out | std::fstream::binary);

    if (!(myFile.is_open()))
    {
        std::cout<<"Error dont open File Formula.txt\n";
        return 1;
    }

    myFile<<args;
    myFile.close();
    return 0;
}
*/
