#include "../inc/header.h"

void initStage(char *adress)
{
    app.delegate.logic = logic;
    app.delegate.draw = draw;

    initMap(adress);

    stage.entityTail = &stage.entityHead;

    initEntities();

    initPlayer();
}

void logic(void)
{
    doPlayer();

    doCamera();
    // menu_level(app.renderer);

    doEntities();
}

void draw(char *adress_background)
{
    //SDL_SetRenderDrawColor(app.renderer, 128, 192, 255, 255);
        SDL_Texture *background = SDL_CreateTextureFromSurface(app.renderer, IMG_Load(adress_background)); 
        SDL_Rect background1_st;
        background1_st.x = 0;
        background1_st.y = 0;
        background1_st.w = SCREEN_WIDTH;
        background1_st.h = SCREEN_HEIGHT;

    SDL_RenderCopy(app.renderer, background, NULL, &background1_st);
    // menu_level(app.renderer);
    //SDL_RenderFillRect(app.renderer, NULL);
    drawMap();

    drawEntities();
}

void capFrameRate(long *then, float *remainder)
{
    long wait, frameTime;

    wait = 16 + *remainder;

    *remainder -= (int)*remainder;

    frameTime = SDL_GetTicks() - *then;

    wait -= frameTime;

    if (wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *remainder += 0.667;

    *then = SDL_GetTicks();
}
