~РУССКАЯ ВЕРСИЯ README~

Данная библиотека предназначена для управления светодиодной матрицей 8x8 с общим катодом моделей 1588B[x] из Arduino.
Настройка библиотеки под свой проект на Arduino:
	1. В файле LedMatrix.h поменять значения пинов в следующих строках на свои:
		#define PIN_ROW1
		#define PIN_ROW2
		#define PIN_ROW3
		#define PIN_ROW4
		#define PIN_ROW5
		#define PIN_ROW6
		#define PIN_ROW7
		#define PIN_ROW8
		#define PIN_COL1
		#define PIN_COL2
		#define PIN_COL3
		#define PIN_COL4
		#define PIN_COL5
		#define PIN_COL6
		#define PIN_COL7
		#define PIN_COL8
Назначение функций:
	• #include <LedMatrix.h> // Подключение библиотеки для работы с матрицей 
	• setLed(int ROW, int COLUMN) // Функция для включения светодиода, находящегося по физическим координатам [ROW][COLUMN], передаваемым в функцию.
	• cleanMatrix() // Функция выключения всех светодиодов в матрице.
	• initMatrix() // Функция для инициализации пинов матрицы на вывод.

~ENGLISH VERSION OF README~

This library is designed to drive an 8x8 Common Cathode LED Array 1588B [x] from Arduino.
Setting up the library for your Arduino project:
	1. In the LedMatrix.h file, change the pin values in the following lines to your own:
		#define PIN_ROW1
		#define PIN_ROW2
		#define PIN_ROW3
		#define PIN_ROW4
		#define PIN_ROW5
		#define PIN_ROW6
		#define PIN_ROW7
		#define PIN_ROW8
		#define PIN_COL1
		#define PIN_COL2
		#define PIN_COL3
		#define PIN_COL4
		#define PIN_COL5
		#define PIN_COL6
		#define PIN_COL7
		#define PIN_COL8
Purpose of functions:
	• #include <LedMatrix.h> // Connecting the library for working with the matrix
	• setLed (int ROW, int COLUMN) // A function to turn on the LED located at the physical coordinates [ROW] [COLUMN] passed to the function.
	• cleanMatrix () // Function to turn off all LEDs in the matrix.
	• initMatrix () // Function for initializing matrix pins for output.

