#ifndef LedMatrix
#define LedMatrix
#define PIN_ROW1 7
#define PIN_ROW2 9
#define PIN_ROW3 6
#define PIN_ROW4 8
#define PIN_ROW5 2
#define PIN_ROW6 5
#define PIN_ROW7 3
#define PIN_ROW8 4
//------------------------------
#define PIN_COL1 A5
#define PIN_COL2 13
#define PIN_COL3 12
#define PIN_COL4 10
#define PIN_COL5 11
#define PIN_COL6 A2
#define PIN_COL7 A4
#define PIN_COL8 A3

void setLed(int row, int column);
void cleanMatrix();
void initMatrix();

#endif