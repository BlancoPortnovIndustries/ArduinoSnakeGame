/*@@@@@@@@@@@@~~LIBRARIES~~@@@@@@@@@@@@*/

#include <LedMatrix.h>
#include <Joystick.h>

/*@@@@@@@@@@@@~~DEFINES~~@@@@@@@@@@@@*/

#define MAX_BODY_LENGTH 64
#define GAME_AREA_HEIGHT 8
#define GAME_AREA_WIDTH 8
//-------------------------------
#define DIRECTION_UP 1
#define DIRECTION_RIGHT 2
#define DIRECTION_DOWN 3
#define DIRECTION_LEFT 4

/*@@@@@@@@@@@@~~VARIABLES~~@@@@@@@@@@@@*/

struct Point {
  int row = 0, col = 0;
  Point(int row = 0, int col = 0): row(row), col(col) {}
};

Point snake;
Point mirrorSnake;
Point food(-1, -1);
Point score;

Joystick js(500,500);

int snakeDelay = 500;
int mode = 1;
int elapsedTime;
int gameboard[8][8] = {};
int scoreBoard[8][8] = {};
int initialSnakeLength = 3;
int snakeDirection = 0;
int snakeLength = initialSnakeLength;
int difficult = 1;

bool flagLevel = true;
bool flagMode = true;
bool gameOver = false;
bool win = false;

unsigned long timestamp = millis();
unsigned long previousTime;

/*@@@@@@@@@@@@~~MESSAGES~~@@@@@@@@@@@@*/

int levelF[8][8] = {
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}};

int levelS[8][8]={
  {0, 0, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0}};

int levelT[8][8] ={
  {0, 0, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 1, 1, 0, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}};

int levelFo[8][8] ={
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 1, 1, 0, 1, 1},
  {0, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0}};
int logo[8][8] = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 0, 0, 1}};
  
  const PROGMEM bool gameOverMessage[8][90] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
const PROGMEM bool snakeMessage[8][56] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

const PROGMEM bool scoreMessage[8][58] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
const PROGMEM bool winMessage[8][66] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
};

/*@@@@@@@@@@@@~~METHODS~~@@@@@@@@@@@@*/

int getRandomSeed(){
  int seed = analogRead(A0);
  seed += analogRead(A1);
  seed += analogRead(A2);
  seed += analogRead(A3);
  seed += analogRead(A4);
  seed += analogRead(A5);
  seed %= 6;  
  switch(seed){
    case 0:
    return analogRead(A0);
    case 1:
    return digitalRead(A1);
    case 2:
    return analogRead(A2);
    case 3:
    return analogRead(A3);
    case 4:
    return analogRead(A4);
    case 5:
    return analogRead(A5);
  }
}

void generateFood() {
  if (food.row == -1 || food.col == -1) {
    if ((snakeLength >= 64 && mode != 3) || (snakeLength >=32 && mode == 3)) {
      win = true;
      return;
    }
    do {
      food.col = random(8);
      food.row = random(8);
    } while (gameboard[food.row][food.col] > 0);
  }
}

void checkValidDirection(){
  int prevDir = js.getPreviousDirection();
  snakeDirection + 2 == prevDir && prevDir != 0 ? snakeDirection = prevDir : 0;
  snakeDirection - 2 == prevDir && prevDir != 0 ? snakeDirection = prevDir : 0;
}

void calculateSnake() {
  switch (snakeDirection) {
    case DIRECTION_UP:
      snake.row--;
      if(mode != 2){
        if(mode == 3) mirrorSnake.row++;
        fixEdge();
      }
      else checkEdge();
      break;

    case DIRECTION_RIGHT:
      snake.col++;
       if(mode != 2){
        if(mode == 3) mirrorSnake.col--;
        fixEdge();
      }
      else checkEdge();
      break;

    case DIRECTION_DOWN:
      snake.row++;
       if(mode != 2){
        if(mode == 3) mirrorSnake.row--;
        fixEdge();
      }
      else checkEdge();
      break;

    case DIRECTION_LEFT:
      snake.col--;
       if(mode != 2){
        if(mode == 3) mirrorSnake.col++;
        fixEdge();
      }
      else checkEdge();
      break;

    default:
      return;
  }
  
  if (gameboard[snake.row][snake.col] > 1 && snakeDirection != 0) {
    gameOver = true;
    return;
  }
  
  if ((snake.row == food.row && snake.col == food.col) || (mode == 3 && mirrorSnake.row == food.row && mirrorSnake.col == food.col )) {
    food.row = -1;
    food.col = -1;
    snakeLength++;
    scoreBoard[score.row][score.col++] = 1;
    if(score.col == 8){
      ++score.row;
      score.col = 0;
    }
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if (gameboard[row][col] > 0 ) {
          gameboard[row][col]++;
        }
      }
    }
  }

  gameboard[snake.row][snake.col] = snakeLength + 1;
  if(mode == 3)  gameboard[mirrorSnake.row][mirrorSnake.col] = snakeLength + 1;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (gameboard[row][col] > 0 ) {
        gameboard[row][col]--;
      }
    }
  }
}

void fixEdge() {
  snake.col < 0 ? snake.col += 8 : 0;
  snake.col > 7 ? snake.col -= 8 : 0;
  snake.row < 0 ? snake.row += 8 : 0;
  snake.row > 7 ? snake.row -= 8 : 0;
  if(mode == 3){
    mirrorSnake.col < 0 ? mirrorSnake.col += 8 : 0;
    mirrorSnake.col > 7 ? mirrorSnake.col -= 8 : 0;
    mirrorSnake.row < 0 ? mirrorSnake.row += 8 : 0;
    mirrorSnake.row > 7 ? mirrorSnake.row -= 8 : 0;
  }
}

void checkEdge(){
  if(snake.col < 0){
    gameOver = true;
    snake.col = 0;
  }
  if(snake.col > 7){
    gameOver = true;
    snake.col = 7;
  }
  if(snake.row < 0){
    gameOver = true;
    snake.row = 0;
  }
  if(snake.row > 7){
    gameOver = true;
    snake.row = 7;
  }
}

void gameState() {
  if (gameOver || win) {
    unroll();
    if(gameOver) showGameOverMessage();
    if(win) showWinMessage();
    showScoreMessage();
    String b = (String) mode;
    Serial.println(b);
    switch(snakeDelay){
      case 500: 
        difficult = 1;
        break;
      case 400:
        difficult = 2;
        break;
      case 300:
        difficult = 3;
        break;
      case 200:
        difficult = 4;
        break;
    }
    b = (String) difficult;
    Serial.println(difficult);
    int Score = snakeLength - initialSnakeLength;
    b = (String) Score;
    Serial.println(b);
    flagLevel = true;
    flagMode = true;
    win = false;
    gameOver = false;
    js.resetClicks();
    snake.row = random(8);
    snake.col = random(8);
    food.row = -1;
    food.col = -1;
    snakeLength = initialSnakeLength;
    snakeDirection = 0;
    memset(gameboard, 0, sizeof(gameboard[0][0]) * 8 * 8);
    gameboard[snake.row][snake.col] = snakeLength;
    memset(scoreBoard, 0, sizeof(scoreBoard[0][0]) * 8 * 8);
    score.row = 0;
    score.col = 0;
  }
}

void draw(){
  cleanMatrix();
  if(millis() % 100 < 50){
      setLed(food.row, food.col);
    }
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
       if (gameboard[row][col] > 0 ) {
        setLed(row,col);
       }
    }
  } 
}

void showGameOverMessage(){
    for (int d = 0; d < sizeof(gameOverMessage[0]) - 7; d++) {
      for (int col = 0; col < 8; col++) {
        for (int row = 0; row < 8; row++) {
          if(pgm_read_byte(&(gameOverMessage[row][col + d]))){
              setLed(row,col);
              delay(2);
          } 
        }
      } 
    }
    cleanMatrix();
    timestamp = millis();
    while(millis() - timestamp < 1000){}
  }
  void showSnakeMessage() {
    for (int d = 0; d < sizeof(snakeMessage[0]) - 7; d++) {
      for (int col = 0; col < 8; col++) {
        for (int row = 0; row < 8; row++) {
          if(pgm_read_byte(&(snakeMessage[row][col + d]))){
              setLed(row,col);
              delay(2);
        }
      }
     
    }
  }
  }
  void showWinMessage(){
    for (int d = 0; d < sizeof(winMessage[0]) - 7; d++) {
      for (int col = 0; col < 8; col++) {    
        for (int row = 0; row < 8; row++) {
          if(pgm_read_byte(&(winMessage[row][col + d]))){
              setLed(row,col);
              delay(2);
          } 
        }
      }  
    }
    cleanMatrix();
    timestamp = millis();
    while(millis() - timestamp < 1000){}
  }
  
  void showScoreMessage() {
    for (int d = 0; d < sizeof(scoreMessage[0]) - 7; d++) {
      for (int col = 0; col < 8; col++) {
        for (int row = 0; row < 8; row++) {
            if(pgm_read_byte(&(scoreMessage[row][col + d]))){
              setLed(row,col);
              delay(2);
          }
        }
      } 
    }
    cleanMatrix();
    timestamp = millis();
    while(millis() - timestamp < 1000){}
    timestamp = millis();
    while(millis() - timestamp < 3000){
      for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
          if(scoreBoard[row][col] == 1){
            setLed(row,col);
          }
        }
      } 
  }
 }
void showLogo(){
  for(int row = 0; row < 8; ++row){
    for(int col = 0; col < 8; ++col)
    if(logo[row][col] == 1)
      setLed(row,col);
  }
}
 void unroll(){
  for (int i = 0; i < 50; i++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        setLed(row,col);
      }
    }
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        if(gameboard[row][col] == 1) setLed(row,col);
      }
    }
  }
  for(int j = 0; j < 3 ; ++j){
    for (int i = 1; i <= snakeLength; i++) {
      for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
          if (gameboard[row][col] == i) {
              setLed(row,col);
              delay(100);
          }
        }
      }
    }
  }
}

 
void initialize() {
  randomSeed(getRandomSeed());
  snake.row = random(8);
  snake.col = random(8);
  mirrorSnake.row = snake.row - GAME_AREA_HEIGHT + 1;
  mirrorSnake.col = snake.col - GAME_AREA_WIDTH + 1;
  mirrorSnake.row  < 0? mirrorSnake.row = -mirrorSnake.row : 0;
  mirrorSnake.col < 0? mirrorSnake.col = -mirrorSnake.col : 0;
  gameboard[snake.row][snake.col] = snakeLength;
}

void levelSelect(){
  js.scanJoystick(snakeDirection,200);
  js.buttClicks();
  if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
  if(snakeDelay == 500){      
      for(int i = 0; i < 8; ++i){
         for(int j = 0; j < 8; ++j){
           if(levelF[i][j] == 1) setLed(i,j);
         }
       }
     //if(js.getClicks() == 1 ){flagLevel = false; snakeDirection = 0; return;}
     if(snakeDirection == DIRECTION_RIGHT) snakeDelay = 400;
     else if (snakeDirection == DIRECTION_LEFT) snakeDelay = 200; 
     snakeDirection == DIRECTION_UP || snakeDirection == DIRECTION_DOWN? flagMode = true : 0;
     snakeDirection = 0;
   }
    
   if(snakeDelay == 400){   
     for(int i = 0; i < 8; ++i){
         for(int j = 0; j < 8; ++j){
           if(levelS[i][j] == 1)setLed(i,j);
         }
       }
     //if(js.getClicks() == 1){flagLevel = false; snakeDirection = 0; return;}
     if(snakeDirection == DIRECTION_RIGHT) snakeDelay = 300;
     else if (snakeDirection == DIRECTION_LEFT) snakeDelay = 500;
     snakeDirection == DIRECTION_UP || snakeDirection == DIRECTION_DOWN? flagMode = true : 0; 
     snakeDirection = 0;
   }
    
   if(snakeDelay == 300){
     for(int i = 0; i < 8; ++i){
         for(int j = 0; j < 8; ++j){
           if(levelT[i][j] == 1) setLed(i,j);
         }
       }
     //if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
     if(snakeDirection == DIRECTION_RIGHT) snakeDelay = 200;
     else if (snakeDirection == DIRECTION_LEFT) snakeDelay = 400;
     snakeDirection == DIRECTION_UP || snakeDirection == DIRECTION_DOWN? flagMode = true : 0; 
     snakeDirection = 0;
   }
    
   if(snakeDelay == 200){
     for(int i = 0; i < 8; ++i){
         for(int j = 0; j < 8; ++j){
           if(levelFo[i][j] == 1) setLed(i,j);
         }
       }
     //if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
     if(snakeDirection == DIRECTION_RIGHT) snakeDelay = 500;
     else if (snakeDirection == DIRECTION_LEFT) snakeDelay = 300;
     snakeDirection == DIRECTION_UP || snakeDirection == DIRECTION_DOWN? flagMode = true : 0; 
     snakeDirection = 0;
   }
}

void modeSelect(){
  js.scanJoystick(snakeDirection,200);
  js.buttClicks();
  if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
  if(mode == 1){
    for(int i = 0; i < 8; ++i){
          for(int j = 0; j < 8; ++j){
            if(levelF[i][j] == 1) setLed(i,j);
          }
        }
      //if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
      if(snakeDirection == DIRECTION_UP) mode = 2;
      else if(snakeDirection == DIRECTION_DOWN) mode = 3;
      snakeDirection == DIRECTION_LEFT || snakeDirection == DIRECTION_RIGHT? flagMode = false : 0; 
      snakeDirection = 0;
  }
  if(mode == 2){
    for(int i = 0; i < 8; ++i){
          for(int j = 0; j < 8; ++j){
            if(levelS[i][j] == 1) setLed(i,j);
          }
        }
      //if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
      if(snakeDirection == DIRECTION_UP) mode = 3;
      else if(snakeDirection == DIRECTION_DOWN) mode = 1;
      snakeDirection == DIRECTION_LEFT || snakeDirection == DIRECTION_RIGHT? flagMode = false : 0; 
      snakeDirection = 0;
  }
  if(mode == 3){
    for(int i = 0; i < 8; ++i){
          for(int j = 0; j < 8; ++j){
            if(levelT[i][j] == 1) setLed(i,j);
          }
        }
      //if(js.getClicks() == 1) {flagLevel = false; snakeDirection = 0; return;}
      if(snakeDirection == DIRECTION_UP) mode =1;
      else if(snakeDirection == DIRECTION_DOWN) mode = 2;
      snakeDirection == DIRECTION_LEFT || snakeDirection == DIRECTION_RIGHT? flagMode = false : 0; 
      snakeDirection = 0;
  }
}

/*@@@@@@@@@@@@~~SETUP & LOOP~~@@@@@@@@@@@@*/

void setup() {
  Serial.begin(9600);
  initialize();
  initMatrix();
  js.calibrateJoystick();
  while(js.getClicks() != 1){
    js.buttClicks();
    showLogo();
  }
  js.resetClicks();
  showSnakeMessage();
}

void loop() {
  if(flagLevel){
    if(!flagMode)
      levelSelect();
    else modeSelect();
  }
  else {
    unsigned long currentTime = millis(); 
    elapsedTime += currentTime - previousTime;
    draw();
    if(elapsedTime > snakeDelay){
      generateFood(); 
      calculateSnake(); 
      gameState();
      elapsedTime = 0;
    }
    js.scanJoystick(snakeDirection,snakeDelay);
    checkValidDirection();  
    previousTime = currentTime;
 }
}


  
