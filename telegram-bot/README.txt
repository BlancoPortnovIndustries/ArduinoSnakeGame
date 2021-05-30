~РУССКАЯ ВЕРСИЯ README~

Альфа версия бота. Обладает множеством недоработок, но при правильном использовании возможна корректная работа бота.

Перед началом использования бота нужно сделать следующее:
1) В файле main.py поменять директорию к файлу users_list.txt
2) В файле handlers.py поменять директории КО ВСЕМ текстовым файлам, в которых хранятся результаты игры пользователей и users_list.txt
3) В файле handlers.py поменять COM-порт на тот порт, к которому подключено устройство
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
Инструкция для пользователя:
1) Введите /start, чтобы запустить бота
2) Введите /play для того, чтобы сыграть в Змейку в режиме записи результата (Устройство перезапустится и будет работать в обычном режиме,
но в конце игры бот пришлёт вам в телеграме сообщение о количестве набранных очков за игру.
3) Введите /save для того, чтобы сохранить ваш результат. Результаты хранятся в текстовых файлах, у которых название состоит из двух цифр:
первая цифра - это режим игры, вторая цифра - это уровень сложности данного режима игры. Если пользователь уже есть в таблице, его счёт
будет перезаписан, независимо от того побил ли пользователь свой рекорд или нет.
4) Введите число из диапазона значений [11,14] || [21,24] || [31,34], чтобы получить "таблицу" лидеров по данному режиму игры и сложности
в виде файла в формате txt. В файле каждый пользователь хранится в виде id=score, где id - id пользователя в телеграме и score - счёт, набранный
данным пользователем.
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
Доработки для следующей версии:
1) Хранение ЛУЧШЕГО результата пользователя за все игры.
2) Оптимизация хранения таблиц лидеров
3) Оптимизация кода телеграм бота
4) Кнопки в телеграм боте для более удобного управления им
5) Возможность создания никнейма пользователя, который будет привязан к его id телеграма
6) Вывод таблицы лидеров не в виде файла, а его содержимого с красивым оформлением
7) Автоматическое определение COM-порта, к которому подключено устройство
8) Общая таблица лидеров по всем режимам (Берётся сумма очков каждого пользователя из всех режимов игры и их сложностей)




~ENGLISH VERSION OF README~

Alpha version of the bot. It has many flaws, but if used correctly, the bot can work correctly.

Before using the bot, you need to do the following:
1) In the main.py file, change the directory to the users_list.txt file
2) In the handlers.py file, change the directories TO ALL text files that store the results of the users' game and users_list.txt
3) In the handlers.py file, change the COM port to the port to which the device is connected
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
Instructions for the user:
1) Enter / start to start the bot
2) Enter / play in order to play Snake in the result recording mode (The device will restart and will work normally,
but at the end of the game, the bot will send you a telegram message about the number of points scored per game.
3) Enter / save to save your result. The results are stored in text files whose name consists of two numbers:
the first number is the game mode, the second number is the difficulty level of this game mode. If the user is already in the table, his account
will be overwritten, regardless of whether the user has broken his own record or not.
4) Enter a number from the range [11.14] || [21,24] || [31,34] to get a leaderboard for a given game mode and difficulty
as a file in txt format. In the file, each user is stored in the form id = score, where id is the user's id in the telegram and score is the score typed
by the given user.
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
Improvements for the next version:
1) Storing the BEST result of the user for all games.
2) Optimizing the storage of leaderboards
3) Optimization of the telegram bot code
4) Buttons in the telegram bot for more convenient control of it
5) The ability to create a username, which will be tied to his telegram id
6) Output of the leaderboard not in the form of a file, but its contents with a beautiful design
7) Automatic detection of the COM port to which the device is connected
8) General leaderboard for all modes (The sum of the points of each user from all game modes and their difficulties is taken) 