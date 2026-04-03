#include <fstream>
#include <iostream>
#include <string>

void Zeroing(std::fstream *myFile, int VERSION, std::streampos VERSION_POINT);

int main(int argc, char** argv)
{
    int VERSION_MAJOR;
    int VERSION_MINOR;
    std::streampos VERSION_MAJOR_POINT;
    std::streampos VERSION_MINOR_POINT;

    std::string arg = argv[1];
    // Specify the path to the include file
    std::fstream myFile("./include/Extra.hpp", std::fstream::out | std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error dont open Basic.hpp\n";
        return 1;
    } 

    std::string temp;
    while(myFile>>temp)
    {
        if (temp=="VERSION_MAJOR")
        {
            VERSION_MAJOR_POINT = myFile.tellg();
            VERSION_MAJOR_POINT+=1;
            myFile>>VERSION_MAJOR;
        }
        if (temp=="VERSION_MINOR")
        {
            VERSION_MINOR_POINT = myFile.tellg();
            VERSION_MINOR_POINT+=1;
            myFile>>VERSION_MINOR;    
        }  
    }
    myFile.clear();

    if(arg == "Ma")
    {
        ++VERSION_MAJOR;
        myFile.seekp(VERSION_MAJOR_POINT);
        myFile<<VERSION_MAJOR;
        Zeroing(&myFile, VERSION_MINOR, VERSION_MINOR_POINT);
    }
    else if(arg == "Mi")
    {
        ++VERSION_MINOR;
        myFile.seekp(VERSION_MINOR_POINT);
        myFile<<VERSION_MINOR;
    }
    else 
    {
        std::cout<<"Error not founded flags";
        return 1;
    }

    myFile.close();
    return 0;    
}

void Zeroing(std::fstream *myFile, int VERSION, std::streampos VERSION_POINT)
{
    myFile->seekp(VERSION_POINT);
    *myFile<<0;
    int ColNumbers=0;
    while (VERSION>0)
        {
            VERSION/=10;
            ColNumbers++;
        }
    for (int i = 0; i < ColNumbers-1; i++)*myFile<<' ';   
}