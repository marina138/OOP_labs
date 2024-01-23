# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 4
#
# Выполнила: Глущенко Марина Анатольевна
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


class MoneyTransfer:

    def __init__(self, name, name1):
        if not isinstance(name, str):
            raise TypeError("Название должно быть строкой")
        if not isinstance(name1, str):
            raise TypeError("Название должно быть строкой")
        self._name = name
        self._name1 = name1

    def run(self):
        print(f"Средства в размере {self._name} переводятся на счёт {self._name1}\n")
