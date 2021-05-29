#ifndef Joystick_h
#define Joystick_h

#define BUTTON_PIN 0
#define JOYSTICKX A0 
#define JOYSTICKY A1

#define DIRECTION_UP 1
#define DIRECTION_RIGHT 2
#define DIRECTION_DOWN 3
#define DIRECTION_LEFT 4

class Joystick {
private:
	int bounceTime = 10;          // �������� ��� ���������� ��������
	int doubleTime = 500;
	bool lastReading = false;  // ���� ����������� ��������� ������
	bool buttonSingle = false; // ���� ��������� "������� �������"
	bool buttonMulti = false; // ���� ��������� "������� �������"
	int clicks = 0;
	long onTime = 0;              // ���������� ��������� ���������� ���������
	long lastSwitchTime = 0;      // ���������� ������� ����������� ������������ ���������
	const int joystickThreshold = 60;
	int joystickHomeX;
	int joystickHomeY;
	int previousDirection = 0;
	unsigned long timestamp = millis();

public:
	Joystick(int __x, int __y);
	void scanJoystick(int& __direction, int delay = 0);
	void calibrateJoystick();
	void buttClicks();
	int getClicks();
	void resetClicks();
	int getPreviousDirection();
	void resetPreviousDirection();
	int getX();
	int getY();
};

#endif