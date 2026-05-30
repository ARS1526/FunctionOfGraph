#if 0
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Extra.hpp"

int PpmViewer(std::string args)
{
    SDL_Init(SDL_INIT_VIDEO);
    
    std::string StandComand = "explorer /select ";
    std::fstream myFile(args, std::fstream::in | std::fstream::binary);
    std::string temp;

    myFile>>temp;
    int Wieht;
    myFile>>Wieht;
    int Heigt;
    myFile>>Heigt;

    

    SDL_Window*  myWindow = SDL_CreateWindow("TestThread", Wieht, Heigt, 0);
    
    SDL_Renderer* mainRenderer = SDL_CreateRenderer( myWindow, NULL);
    if (mainRenderer == nullptr)
    {
        std::cout<<"SDL_CreateRender Error:"<<SDL_GetError()<<std::endl;
    }

    SDL_Surface* imageLoader = IMG_Load(argv[1]);
    SDL_Texture* textureImage = SDL_CreateTextureFromSurface(mainRenderer, imageLoader);

    if(!imageLoader)std::cerr<<"Surface\n"<<SDL_GetError()<<"\n";
    if(!textureImage)std::cerr<<"Texture\n"<<SDL_GetError()<<"\n";

    SDL_FRect Image;
    Image.w = Wieht;
    Image.h = Heigt;
    Image.x = 0;
    Image.y = 0;
    
    SDL_RenderTexture(mainRenderer, textureImage, NULL, &Image);
    SDL_RenderPresent(mainRenderer);    

    //"C/Users/doris/OneDrive/Documents/BackApp1/Graphics/data/texture/SilverLining.ppm"

    
    SDL_Event event;
    bool quit = false;
    while (quit == false)
    {
        while ( SDL_PollEvent ( &event )) //пока происходит событие
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    quit = true;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    switch (event.key.key)
                    {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                    }
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    switch (event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                                if(event.button.button==SDL_BUTTON_LEFT && event.button.clicks==2)
                                {
                                    std::string Comand = StandComand + args;
                                    system(Comand.c_str());
                                }
                            break;
                        default:
                            break;
                    }
                    
            }
        }
    }
    
    SDL_DestroySurface(imageLoader);
    SDL_DestroyTexture(textureImage);
    SDL_DestroyWindow(myWindow);
    SDL_Quit();
    return 0;
}
#endif