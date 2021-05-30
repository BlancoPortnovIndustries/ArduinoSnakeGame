~РУССКАЯ ВЕРСИЯ README~

Данная библиотека предназначена для считывания значений с джойстика модели KY-023 для Arduino.
Настройка библиотеки под свой проект на Arduino:
	1. В файле Joystick.h поменять значения пинов в следующих строках на свои:
		#define BUTTON_PIN
		#define JOYSTICKX  
		#define JOYSTICKY 
	2. В файле Joystick.cpp поменять условия определения направлений в методе scanJoystick.
	3. По желанию можно изменить нижнее пороговое значение считывания с джойстика. Эта переменная называется «joystickThreshold» и находится в файле Joystick.h.
Назначение функций:
	• #include <Joystick.h> // Подключение библиотеки для работы с модулем
	• Joystick ИМЯ (ЗНАЧЕНИЕ, ЗНАЧЕНИЕ) // Создание объекта для работы с методами библиотеки, передаем туда центральные позиции джойстика по осям X и Y.
	• scanJoystick ((адрес)НАПРАВЛЕНИЕ, ЗАДЕРЖКА) // Функция для определения направления отклонения джойстика от центральной оси, передаем туда адрес переменной, в которую будет записано направление, и опциональный параметр задержки, который ограничивает количество считываний с джойстика. Если не передавать значение задержки считывания, то она автоматически будет равна нулю.
	• calibrateJoystick() // Калибровка значений центральных позиций джойстика по осям X и Y.
	• buttClicks() // Функция для обработки количества нажатий на джойстик. Количество нажатий хранится в переменной.
	• getClicks() // Функция получения количества нажатий на джойстик.
	• resetClicks() // Функция для сброса количества нажатий на джойстик.
	• getPreviousDirection() // Функция получения последнего направления отклонения джойстика от центральной оси.
	• resetPreviousDirection() // Функция сброса последнего направления отклонения джойстика от центральной оси.
	• getX() // Функция получения значения центральной позиции джойстика по оси X.
	• getY() // Функция получения значения центральной позиции джойстика по оси Y.

~ENGLISH VERSION OF README~

This library is designed to read values from the joystick model KY-023 for Arduino.
Setting up the library for your Arduino project:
	1. In the Joystick.h file, change the pin values in the following lines to your own:
		#define BUTTON_PIN
		#define JOYSTICKX
		#define JOYSTICKY
	2. In the Joystick.cpp file, change the conditions for determining the directions in the scanJoystick method.
	3. If desired, you can change the lower threshold value for reading from the joystick. This variable is called «joystickThreshold» and is located in the Joystick.h file.
Purpose of functions:
	• #include <Joystick.h> // Connecting the library for working with the module
	• Joystick NAME (VALUE, VALUE) // Create an object for working with library methods, transfer there the central positions of the joystick along the X and Y axes.
	• scanJoystick ((address) DIRECTION, DELAY) // A function to determine the direction of the joystick deflection from the central axis, transfer there the address of the variable to which the direction will be written, and an optional delay parameter that limits the number of readings from the joystick. If you do not transmit the value of the readout delay, then it will automatically be equal to zero.
	• calibrateJoystick () // Calibrate the values of the center positions of the joystick along the X and Y axes.
	• buttClicks () // Function for handling the number of times the joystick was pressed. The number of clicks is stored in a variable.
	• getClicks () // Function for getting the number of clicks on the joystick.
	• resetClicks () // Function for resetting the number of joystick clicks.
	• getPreviousDirection () // Function for getting the last direction of the joystick deviation from the central axis.
	• resetPreviousDirection () // Function for resetting the last direction of the joystick's deviation from the central axis.
	• getX () // Function for getting the value of the central position of the joystick along the X axis.
	• getY () // Function for getting the value of the central position of the joystick along the Y axis.
