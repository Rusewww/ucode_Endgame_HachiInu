#include "../inc/header.h"

int main()
{
    long then;
    float remainder;

    memset(&app, 0, sizeof(App));
    app.textureTail = &app.textureHead;

    initSDL();

    menu(app.renderer);
    


    atexit(cleanup);


switch (menu_level(app.renderer))
{
case 1:
     initGame();
    char *adress_map1 = "data/map01.dat";
    initStage(adress_map1);

    then = SDL_GetTicks();

    remainder = 0;

    while (1)
    {
        prepareScene();

        doInput();

        app.delegate.logic();

        app.delegate.draw("resource/first_lvl_back.png");

        presentScene();
        capFrameRate(&then, &remainder);
    }
    break;
case 2:
     initGame();
    char *adress_map2 = "data/map02.dat";
    initStage(adress_map2);

    then = SDL_GetTicks();

    remainder = 0;

    while (1)
    {
        prepareScene();

        doInput();

        app.delegate.logic();

        app.delegate.draw("resource/second_lvl_back.png");

        presentScene();
        capFrameRate(&then, &remainder);
    }
    break;
case 3:
    initGame();
    char *adress_map3 = "data/map03.dat";
    initStage(adress_map3);

    then = SDL_GetTicks();

    remainder = 0;

    while (1)
    {
        prepareScene();

        doInput();

        app.delegate.logic();

        app.delegate.draw("resource/third_lvl_back.png");

        presentScene();
        capFrameRate(&then, &remainder);
    }
     break;

default:
    break;
}



   

    return 0;
}
