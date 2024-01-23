# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 4
#
# Выполнила: Глущенко Марина Анатольевна
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


from Денежный_перевод import MoneyTransfer


class BankTransfer(MoneyTransfer):
    def __init__(self, name, name1):
        if not isinstance(name, str):
            raise TypeError
        if not isinstance(name1, str):
            raise TypeError

        super().__init__(name)
        super().__init__(name1)

    def run(self):
        super().run()
