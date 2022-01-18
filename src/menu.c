#include "../inc/header.h"

int menu(SDL_Renderer* renderer){

    SDL_Texture *background = SDL_CreateTextureFromSurface(renderer, IMG_Load("resource/menu.png")); 
        SDL_Rect background1_st;
        background1_st.x = 0;
        background1_st.y = 0;
        background1_st.w = SCREEN_WIDTH;
        background1_st.h = SCREEN_HEIGHT;

    // SDL_Texture *button1 = SDL_CreateTextureFromSurface(renderer, IMG_Load("resource/button.png"));
    //     SDL_Rect button1_st;
    //     button1_st.x = 240;
    //     button1_st.y = 120;
    //     button1_st.w = 100;
    //     button1_st.h = 30;

    // SDL_Texture *button2 = SDL_CreateTextureFromSurface(renderer, IMG_Load("resource/button.png"));
    // SDL_Rect button2_st;
    //     button2_st.x = 240;
    //     button2_st.y = 220;
    //     button2_st.w = 100;
    //     button2_st.h = 30;

    // SDL_Texture *button3 = SDL_CreateTextureFromSurface(renderer, IMG_Load("resource/button.png"));
    // SDL_Rect button3_st;
    //     button3_st.x = 240;
    //     button3_st.y = 320;
    //     button3_st.w = 100;
    //     button3_st.h = 30;

    // SDL_Texture *background_win_2 = SDL_CreateTextureFromSurface(renderer, IMG_Load("resource/2.bmp")); 
    //     SDL_Rect background_win_2_st;
    //     background_win_2_st.x = 0;
    //     background_win_2_st.y = 0;
    //     background_win_2_st.w = SCREEN_HEIGHT;
    //     background_win_2_st.h = SCREEN_WIDTH;



    bool running = true;
    int flag = 0;


   
    while( running )
    {
        SDL_RenderCopy(renderer, background, NULL, &background1_st);
        // SDL_RenderCopy(renderer, button1, NULL, &button1_st);
        // SDL_RenderCopy(renderer, button2, NULL, &button2_st);
        // SDL_RenderCopy(renderer, button3, NULL, &button3_st);


        int x, y;
        Uint32 buttons;
        SDL_PumpEvents(); 
        buttons = SDL_GetMouseState(&x, &y);


       if(((buttons & SDL_BUTTON_LMASK) != 0) && x > 768 && x < 1152 && y > 565 & y < 650){ // up button 
            running = false;
             flag = 1;
       }
       if(((buttons & SDL_BUTTON_LMASK) != 0) && x > 880 && x <1030 && y > 815 & y < 870) { /// down button
            exit(0);
           running = false;
       }
       SDL_RenderPresent( renderer );
        
    }
        SDL_Delay(100);
        SDL_DestroyTexture(background);
            
            // SDL_DestroyTexture(button1);
            // SDL_DestroyTexture(button2);
            // SDL_DestroyTexture(button3);

    //int running2 = true;

  

        // while (running2)
        // {

        //     SDL_RenderCopy(renderer, background_win_2, NULL, &background_win_2_st);
        //     SDL_RenderPresent( renderer );


        //     int x1, y1;
        //     Uint32 buttons1;
        //     SDL_PumpEvents(); 
        //     buttons1 = SDL_GetMouseState(&x1, &y1);


        //     if(((buttons1 & SDL_BUTTON_LMASK) != 0) && x1 < 20){ /// up button 
        //         running2 = false;
        //     }


        // }
    


    return 0;
}



