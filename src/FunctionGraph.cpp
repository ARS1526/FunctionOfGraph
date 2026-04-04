#include <iostream>//
#include <fstream>
#include <string>
#include <cmath>
#include "Extra.hpp"

int FunInPPM(int Widht, int Height)
{
    std::ofstream fout("./data/texture/FirstTest.ppm");

    const int IMAGE_WIDHT = Widht, IMAGE_HEIGHT = Height;
    fout<<"P3\n"<<IMAGE_WIDHT<<' '<<IMAGE_HEIGHT<<"\n1\n";

    int WAxis = 2;
    int PolW = IMAGE_WIDHT/2;
    int PolH = IMAGE_HEIGHT/2;
    int var = 0;//

    for(int y = PolH; y >= PolH*-1; y--)
    {
        for(int x = PolW*-1; x < PolW; x++)
        {
            if(x > 0-WAxis && x < 0+WAxis)fout<<0<<' '<<0<<' '<<0<<"\n";
            else if(y < 0+WAxis && y > 0-WAxis)
            {
                var++;//
                fout<<0<<' '<<0<<' '<<0<<"\n";
            }
            else fout<<1<<' '<<1<<' '<<1<<"\n";
            
        }
    }
    /*
    for (int x = PolW*-1; x < PolW; x++)
    {
        int y;
        if();
    }
    */
    
    std::cout<<var;//
    fout.close();
    return 0;
}

std::string Formla(std::string Formula)
{
    

    return NULL;
}