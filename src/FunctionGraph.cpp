#include <iostream>//
#include <fstream>
#include "include/muParser.h"
#include "Extra.hpp"

int FunInPPM(int Widht, int Height, std::string Equation)
{
    std::ofstream fout("./data/texture/FirstTest.ppm", std::fstream::binary);

    const int IMAGE_WIDHT = Widht, IMAGE_HEIGHT = Height;
    fout<<"P3\n"<<IMAGE_WIDHT<<' '<<IMAGE_HEIGHT<<"\n1\n";

    int WAxis = 2;
    int PolW = IMAGE_WIDHT/2;
    int PolH = IMAGE_HEIGHT/2;

    for(int y = PolH; y >= PolH*-1; y--)
    {
        for(int x = PolW*-1; x < PolW; x++)
        {
            if(x > 0-WAxis && x < 0+WAxis)fout<<0<<' '<<0<<' '<<0<<"\n";
            else if(y < 0+WAxis && y > 0-WAxis)
            {
                fout<<0<<' '<<0<<' '<<0<<"\n";
            }
            else fout<<1<<' '<<1<<' '<<1<<"\n";
            
        }
    }
    mu::Parser parser;
    int y;
    for (double x = PolW*-1; x <= PolW; x++)
    {
        int NumLine = 3;
        mu::value_type X = x;
        parser.SetExpr(Equation);
        parser.DefineVar("x", &X);
        y = parser.Eval();
        std::cout<<"Y = "<<parser.Eval()<<std::endl;//
        NumLine += Widht*(PolH+y*-1) + (PolW+x);
        std::cout<<"NumLine = "<<NumLine<<std::endl;// 

        fout.seekp(NumLine, std::ios::beg);
        fout<<0<<' '<<0<<' '<<0<<"\n";
    }
    
       
    fout.close();
    return 0;
}