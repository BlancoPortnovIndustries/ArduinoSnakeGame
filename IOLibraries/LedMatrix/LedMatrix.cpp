#include <Arduino.h>
#include "LedMatrix.h"

void setLed(int row, int column) {
	digitalWrite(PIN_ROW1, LOW);
	digitalWrite(PIN_ROW2, LOW);
	digitalWrite(PIN_ROW3, LOW);
	digitalWrite(PIN_ROW4, LOW);
	digitalWrite(PIN_ROW5, LOW);
	digitalWrite(PIN_ROW6, LOW);
	digitalWrite(PIN_ROW7, LOW);
	digitalWrite(PIN_ROW8, LOW);
	digitalWrite(PIN_COL1, HIGH);
	digitalWrite(PIN_COL2, HIGH);
	digitalWrite(PIN_COL3, HIGH);
	digitalWrite(PIN_COL4, HIGH);
	digitalWrite(PIN_COL5, HIGH);
	digitalWrite(PIN_COL6, HIGH);
	digitalWrite(PIN_COL7, HIGH);
	digitalWrite(PIN_COL8, HIGH);

	switch (column)
	{
	case 0: digitalWrite(PIN_COL1, LOW); break;
	case 1: digitalWrite(PIN_COL2, LOW); break;
	case 2: digitalWrite(PIN_COL3, LOW); break;
	case 3: digitalWrite(PIN_COL4, LOW); break;
	case 4: digitalWrite(PIN_COL5, LOW); break;
	case 5: digitalWrite(PIN_COL6, LOW); break;
	case 6: digitalWrite(PIN_COL7, LOW); break;
	case 7: digitalWrite(PIN_COL8, LOW); break;
	default: break;
	}

	switch (row)
	{
	case 0: digitalWrite(PIN_ROW1, HIGH); break;
	case 1: digitalWrite(PIN_ROW2, HIGH); break;
	case 2: digitalWrite(PIN_ROW3, HIGH); break;
	case 3: digitalWrite(PIN_ROW4, HIGH); break;
	case 4: digitalWrite(PIN_ROW5, HIGH); break;
	case 5: digitalWrite(PIN_ROW6, HIGH); break;
	case 6: digitalWrite(PIN_ROW7, HIGH); break;
	case 7: digitalWrite(PIN_ROW8, HIGH); break;
	default: break;
	}
}
void cleanMatrix() {
	digitalWrite(PIN_ROW1, LOW);
	digitalWrite(PIN_ROW2, LOW);
	digitalWrite(PIN_ROW3, LOW);
	digitalWrite(PIN_ROW4, LOW);
	digitalWrite(PIN_ROW5, LOW);
	digitalWrite(PIN_ROW6, LOW);
	digitalWrite(PIN_ROW7, LOW);
	digitalWrite(PIN_ROW8, LOW);
	digitalWrite(PIN_COL1, HIGH);
	digitalWrite(PIN_COL2, HIGH);
	digitalWrite(PIN_COL3, HIGH);
	digitalWrite(PIN_COL4, HIGH);
	digitalWrite(PIN_COL5, HIGH);
	digitalWrite(PIN_COL6, HIGH);
	digitalWrite(PIN_COL7, HIGH);
	digitalWrite(PIN_COL8, HIGH);
}
void initMatrix() {
	pinMode(PIN_ROW1, OUTPUT);
	pinMode(PIN_ROW2, OUTPUT);
	pinMode(PIN_ROW3, OUTPUT);
	pinMode(PIN_ROW4, OUTPUT);
	pinMode(PIN_ROW5, OUTPUT);
	pinMode(PIN_ROW6, OUTPUT);
	pinMode(PIN_ROW7, OUTPUT);
	pinMode(PIN_ROW8, OUTPUT);
	pinMode(PIN_COL1, OUTPUT);
	pinMode(PIN_COL2, OUTPUT);
	pinMode(PIN_COL3, OUTPUT);
	pinMode(PIN_COL4, OUTPUT);
	pinMode(PIN_COL5, OUTPUT);
	pinMode(PIN_COL6, OUTPUT);
	pinMode(PIN_COL7, OUTPUT);
	pinMode(PIN_COL8, OUTPUT);
}
