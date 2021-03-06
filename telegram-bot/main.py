import asyncio
import serial
from aiogram import Bot, Dispatcher, executor

from config import BOT_TOKEN
score: str = ""
mode: str = "1"
diff: str = "1"
dict_table = {}
list_of_users = set()
file = open("C:/Users/acer/PycharmProjects/pythonProject/users_list.txt", "r")
for line in file:
    list_of_users.add(line.strip())
file.close()

loop = asyncio.get_event_loop()
bot = Bot(BOT_TOKEN, parse_mode="HTML")
dp = Dispatcher(bot, loop=loop)


if __name__ == "__main__":
    from handlers import dp, save_id
    executor.start_polling(dp)


