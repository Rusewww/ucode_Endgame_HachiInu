#include "../inc/header.h"

static SDL_Texture *dog[22];

void initPlayer(void)
{
    player = malloc(sizeof(struct Entity));
    memset(player, 0, sizeof(struct Entity));
    stage.entityTail->next = player;
    stage.entityTail = player;

    dog[0] = loadTexture("gfx/idle1right.png");
    dog[1] = loadTexture("gfx/idle2right.png");
    dog[2] = loadTexture("gfx/idle3right.png");
    dog[3] = loadTexture("gfx/idle4right.png");
    dog[4] = loadTexture("gfx/idle1left.png");
    dog[5] = loadTexture("gfx/idle2left.png");
    dog[6] = loadTexture("gfx/idle3left.png");
    dog[7] = loadTexture("gfx/idle4left.png");
    dog[8] = loadTexture("gfx/jump_right.png");
    dog[9] = loadTexture("gfx/jump_left.png");
    dog[10] = loadTexture("gfx/run1right.png");
    dog[11] = loadTexture("gfx/run2right.png");
    dog[12] = loadTexture("gfx/run3right.png");
    dog[13] = loadTexture("gfx/run4right.png");
    dog[14] = loadTexture("gfx/run5right.png");
    dog[15] = loadTexture("gfx/run6right.png");
    dog[16] = loadTexture("gfx/run1left.png");
    dog[17] = loadTexture("gfx/run2left.png");
    dog[18] = loadTexture("gfx/run3left.png");
    dog[19] = loadTexture("gfx/run4left.png");
    dog[20] = loadTexture("gfx/run5left.png");
    dog[21] = loadTexture("gfx/run6left.png");


    player->texture = dog[0];

    SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

void doPlayer()
{
    player->dx = 0;

    if (app.keyboard[SDL_SCANCODE_A])
    {
        player->dx = -PLAYER_MOVE_SPEED;
        
        player->texture = dog[4];
        
        
        player->texture = dog[16];
        
        
        player->texture = dog[17];
        
        
        player->texture = dog[18];
        
        
        player->texture = dog[19];
        
        
        player->texture = dog[20];
       
       
        player->texture = dog[21];
        
        player->texture = dog[4];
    }

    if (app.keyboard[SDL_SCANCODE_D])
    {
        player->dx = PLAYER_MOVE_SPEED;
        
        player->texture = dog[0];
        
        player->texture = dog[11];
        
        player->texture = dog[12];
        
        player->texture = dog[13];
        
        player->texture = dog[14];
        
        player->texture = dog[15];
        
        player->texture = dog[16];
        
        player->texture = dog[0];
    }

    if (app.keyboard[SDL_SCANCODE_SPACE] && player->isOnGround)
    {
        
        if (player->texture == dog[0]) {
            
            player->dy = -20;
            player->texture = dog[8];
            player->texture = dog[0];
        
        } else {
            player->dy = -20;
            player->texture = dog[9];
            
            player->texture = dog[4];
            
        
        }
    }

    if (app.keyboard[SDL_SCANCODE_R])
    {
        player->x = player->y = 0;

        app.keyboard[SDL_SCANCODE_R] = 0;
    }
}

