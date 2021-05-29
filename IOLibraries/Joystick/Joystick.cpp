#include <Arduino.h>
#include "Joystick.h"

Joystick::Joystick(int __x, int __y) {
	joystickHomeX = __x;
	joystickHomeY = __y;
    pinMode(BUTTON_PIN, INPUT);
    pinMode(JOYSTICKX, INPUT);
    pinMode(JOYSTICKY, INPUT);
}

void Joystick::scanJoystick(int& __direction, int delay = 0) {
    previousDirection = __direction;
    int X = analogRead(JOYSTICKX);
    int Y = analogRead(JOYSTICKY);
    if (millis() - timestamp > delay) {
        Y < joystickHomeY - joystickThreshold ? __direction = DIRECTION_RIGHT : 0; //вверх
        Y > joystickHomeY + joystickThreshold ? __direction = DIRECTION_LEFT : 0;//вниз
        X < joystickHomeX - joystickThreshold ? __direction = DIRECTION_UP : 0;//влево
        X > joystickHomeX + joystickThreshold ? __direction = DIRECTION_DOWN : 0;//вправо
        timestamp = millis();
    }
}

void Joystick::calibrateJoystick() {
    int valueX = 0;
    int valueY = 0;

    for (int i = 0; i < 10; i++) {
        valueX += analogRead(JOYSTICKX);
        valueY += analogRead(JOYSTICKY);
    }

    joystickHomeX = valueX / 10;
    joystickHomeY = valueY / 10;
}

void Joystick::buttClicks() {
    bool reading = digitalRead(BUTTON_PIN);
    if (reading && !lastReading) {
        onTime = millis();
    }
    if (!reading && lastReading) {
        if (((millis() - onTime) > bounceTime)) {
            if ((millis() - lastSwitchTime) >= doubleTime) {
                lastSwitchTime = millis();
                buttonSingle = true;
                clicks = 1;
            }
            else {
                clicks++;
                lastSwitchTime = millis();
                buttonSingle = false;
                buttonMulti = true;
            }
        }
    }
    lastReading = reading;
}

int Joystick::getClicks() {
    return clicks;
}

void Joystick::resetClicks() {
    clicks = 0;
}

int Joystick::getPreviousDirection() {
    return previousDirection;
}

void Joystick::resetPreviousDirection() {
    previousDirection = 0;
}
int Joystick::getX() {
    return joystickHomeX;
}
int Joystick::getY() {
    return joystickHomeY;
}