#ifndef ENDGAME_H
#define ENDGAME_H

#define SCREEN_WIDTH          1920
#define SCREEN_HEIGHT         1080

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'

#define PLAYER_MOVE_SPEED      3

#define MAX_TILES              8

#define TILE_SIZE              32

#define MAP_WIDTH              90
#define MAP_HEIGHT             48

#define MAP_RENDER_WIDTH       40
#define MAP_RENDER_HEIGHT      24

#define MAX_NAME_LENGTH        32
#define MAX_LINE_LENGTH        1024
#define MAX_FILENAME_LENGTH    1024

#define MAX_KEYBOARD_KEYS      350

#define MAX_SND_CHANNELS       8

#define EF_NONE       0
#define EF_WEIGHTLESS (2 << 0)
#define EF_SOLID      (2 << 1)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "struct.h"

extern void cleanup(void);
extern void initSDL(void);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
void blit(SDL_Texture *texture, int x, int y, int center);
void doKeyUp(SDL_KeyboardEvent *event);
void doKeyDown(SDL_KeyboardEvent *event);
char *readFile(const char *filename);
void initMap(char *adress);
void drawMap(void);
void loadTiles(void);
void loadMap(const char *filename);
void initStage(char *adress);
void logic(void);
void draw(char *adress_background);
void draw1();
void capFrameRate(long *then, float *remainder);
void initGame(void);
SDL_Texture *loadTexture(char *filename);
SDL_Texture *getTexture(char *name);
void addTextureToCache(char *name, SDL_Texture *sdlTexture);
void doCamera(void);
void doPlayer(void);
void doEntities(void);
void move(struct Entity *e);
void moveToWorld(struct Entity *e, float dx, float dy);
void drawEntities(void);
void initPlayer(void);
void doPlayer(void);
void initEntities(void);
int isInsideMap(int x, int y);
void moveToEntities(struct Entity *e, float dx, float dy);
void loadEnts(const char *filename);
void addEntFromLine(char *line);
int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

int menu_level(SDL_Renderer* renderer);
int menu(SDL_Renderer* renderer);

struct Entity *player;

struct Entity *self;

Stage stage;

App app;

#endif
