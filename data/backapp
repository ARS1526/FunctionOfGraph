#include <iostream>//
#include <fstream>
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

    for(int j = IMAGE_WIDHT-1; j >= 0; j--)
    {
        for(int i = 0; i < IMAGE_HEIGHT; i++)
        {
            if(j > PolH-WAxis && j < PolH+WAxis)fout<<0<<' '<<0<<' '<<0<<"\n";
            else if(i > PolW-WAxis && i < PolW+WAxis)
            {
                var++;//
                fout<<0<<' '<<0<<' '<<0<<"\n";
            }
            else fout<<1<<' '<<1<<' '<<1<<"\n";
            
        }
    }
    std::cout<<var;//
    fout.close();
    return 0;
}