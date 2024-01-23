# Программирование на языке высокого уровня (Python).
# Задание №4.3.2. Вариант 4
#
# Выполнила: Глущенко М.А
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


from терминал import Terminal

if __name__ == "__main__":

    Terminal1 = Terminal()
    print(Terminal1)
    while True:
        Terminal1.показать_меню()
        point = input()
        Terminal1.Processing(point)
