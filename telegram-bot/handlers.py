import asyncio

import serial
from main import bot, dp,list_of_users, score,mode,diff,dict_table


from config import admin_id




# Декоратор
@dp.message_handler(commands=['start'])
async def save_id(message):

    if not (message.chat.id) in list_of_users:
        file = open("C:/Users/acer/PycharmProjects/pythonProject/users_list.txt", "a")
        file.write(str(message.chat.id) + '\n')
        list_of_users.add(message.chat.id)
        await bot.send_message(chat_id=message.chat.id, text="ArduinoSnakeBot приветствует тебя!")

@dp.message_handler(commands=['play'])
async def game(message):
    ##await bot.send_message(chat_id=message.chat.id, text="Игра началась!")
    ser = serial.Serial('COM3', 9600)
    global score
    global mode
    global diff
    mode = ser.readline()
    mode = mode.decode('utf-8')
    mode = mode.rstrip("\n")
    mode = mode.rstrip("\r")
    diff = ser.readline()
    diff = diff.decode('utf-8')
    diff = diff.rstrip("\n")
    diff = diff.rstrip("\r")
    score = ser.readline()
    score = score.decode('utf-8')
    score = score.rstrip("\n")
    score = score.rstrip("\r")
    print(mode)
    await bot.send_message(chat_id=message.chat.id, text=f"Ваш текущий результат {score}!\n"
                                                         "Введите команду /save, чтобы сохранить свой результат")

@dp.message_handler(commands=['save'])
async def save_result(message):
    await bot.send_message(chat_id=message.chat.id, text="Сохраняю ваш результат!\n"
                                                         "Чтобы посмотреть таблицу лидеров по определенному режиму игры и уровня сложности, введите "
                                                         "2 цифры слитно: первая цифра - режим игры, вторая цифра - уровень сложности."
                                                         "Всего режимов игры: 1, 2, 3. Уровней сложности: 1, 2, 3, 4"
                                                         "Пример ввода: 12 (вы получите таблицу лидеров по 1 режиму игры и 2 уровню сложности."
                                                         "(Если таблица пуста, бот не ответит на ваше сообщение)")
    global mode
    global diff
    global dict_table
    file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "r")
    for line in file:
        line = line.rstrip("\n")
        tmp = line.split("=", 1)
        print(tmp)
        dict_table[tmp[0]] = tmp[1]
    file.close()
    dict_table[str(message.chat.id)] = score
    print(dict_table)
    sorted_dict = {}
    sorted_keys = sorted(dict_table, key=dict_table.get, reverse=-1)
    for w in sorted_keys:
        sorted_dict[w] = dict_table[w]
    dict_table = sorted_dict
    file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "w")
    for x, y in dict_table.items():
        file.write(str(x) + "=" + str(y) + '\n')
    file.close()


@dp.message_handler(content_types=["text"])
async def text_for_table(message):
    global mode
    global diff
    if message.text == "11":
        mode = "1"
        diff = "1"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "12":
        mode = "1"
        diff = "2"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "13":
        mode = "1"
        diff = "3"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "14":
        mode = "1"
        diff = "4"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "21":
        mode = "2"
        diff = "1"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "22":
        mode = "2"
        diff = "2"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "23":
        mode = "2"
        diff = "3"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "24":
        mode = "2"
        diff = "4"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "31":
        mode = "3"
        diff = "1"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "32":
        mode = "3"
        diff = "2"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "33":
        mode = "3"
        diff = "3"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    elif message.text == "34":
        mode = "3"
        diff = "4"
        file = open(f"C:/Users/acer/PycharmProjects/pythonProject/{mode}{diff}.txt", "rb")
        await bot.send_document(chat_id=message.chat.id, document=file)
    else:
        await bot.send_message(chat_id=message.chat.id, text="Вы ввели неверное число")













