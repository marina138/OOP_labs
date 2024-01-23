# Программирование на языке высокого уровня (Python).
# Задание №4.3.4-5. Вариант 4
#
# Выполнила: Глущенко М.А
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


import json
import re


class Time:
    HOUR_MIN = 0
    HOUR_MAX = 24
    MINUTE_MIN = 0
    MINUTE_MAX = 60
    SECOND_MIN = 0
    SECOND_MAX = 60

    def __init__(self, hour=0, minute=0, second=0):
        if not ((isinstance(hour, int)) and (isinstance(minute, int)) and
                (isinstance(second, int))):
            raise ValueError("Агрументы не соответствуют необходимому типу!")
        if not ((self.HOUR_MIN <= hour < self.HOUR_MAX) and
                (self.MINUTE_MIN <= minute < self.MINUTE_MAX) and
                (self.SECOND_MIN <= second < self.SECOND_MAX)):
            raise ValueError("Нарушение границ допустимых значений!")
        self._hour = hour
        self._minute = minute
        self._second = second

    def __str__(self):
        hour = self._hour
        minute = self._minute
        second = self._second

        if self.hour < 10:
            hour = "0{}".format(hour)
        if self.minute < 10:
            minute = "0{}".format(minute)
        if self.second < 10:
            second = "0{}".format(second)

        time_str = "{}:{}:{}".format(hour, minute, second)

        return time_str

    def __eq__(self, other):
        if not (isinstance(other, Time)):
            return False

        return ((self._hour == other.hour) and
                (self._minute == other.minute) and
                (self._second == other.second))

    def __add__(self, other):
        if not isinstance(other, Time):
            raise TypeError
        if self.second + other.second >= 60:
            if self.minute + other.minute >= 60:
                return Time(self.hour + other.hour + 1, self.minute + other.minute + 1 - 60, self.second + other.second - 60)
            return Time(self.hour + other.hour, self.minute + other.minute + 1, self.second + other.second - 60)
        return Time(self.hour + other.hour, self.minute + other.minute, self.second + other.second)

    def __sub__(self, other):
        if not isinstance(other, Time):
            raise TypeError
        if self.second < other.second:
            if self.minute < other.minute:
                return Time(self.hour - other.hour - 1, 59 + self.minute - other.minute, 60 + self.second - other.second)
            return Time(self.hour - other.hour, self.minute - 1 - other.minute, 60 + self.second - other.second)
        elif self.minute < other.minute:
            return Time(self.hour - other.hour - 1, 60 + self.minute - other.minute, self.second - other.second)
        elif (self.hour > other.hour) and (self.minute > other.minute) and (self.second > other.second):
            return Time(self.hour - other.hour, self.minute - other.minute, self.second - other.second)


    @classmethod
    def from_string(cls, str_value):
        # format "00:00:00", "00:00:00.000000", "00:00:00.000000 UTC+3:0"

        if not(isinstance(str_value, str)):
            raise TypeError("Аргумент должен быть строкой")

        m = re.search(r"(?P<hour>\d+):(?P<minute>\d+):(?P<second>\d+)",
                      str_value)

        if not m:
            raise ValueError("Не удалось создать экземпляр класса из строки")

        result = m.groupdict()
        hour = int(result["hour"])
        minute = int(result["minute"])
        second = int(result["second"])

        return cls(hour, minute, second)

    def save(self, filename):
        if not (isinstance(filename, str)):
            raise TypeError("Имя файла должно быть строкой!")

        with open("{}.json".format(filename), "w", encoding="utf-8") as fh:
            fh.write(json.dumps(str(self), ensure_ascii=False, indent=4))

    def load(self, filename):
        if not (isinstance(filename, str)):
            raise TypeError("Имя файла должно быть строкой!")

        try:
            with open("{}.json".format(filename), encoding="utf-8") as fh:
                time_str = json.loads(fh.read())
                return self.from_string(time_str)
        except Exception as err:
            print("При загрузке файла произошла ошибка {}!".format(err))

    @property
    def min(self):
        return str(Time())

    @property
    def max(self):
        return str(Time(23, 59, 59))

    @property
    def resolution(self):
        return str(Time(0, 0, 0))
    @property
    def hour(self):
        return self._hour

    @property
    def minute(self):
        return self._minute

    @property
    def second(self):
        return self._second
