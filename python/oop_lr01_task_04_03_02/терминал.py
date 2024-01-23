# Программирование на языке высокого уровня (Python).
# Задание №4.3.2. Вариант 4
#
# Выполнила: Глущенко М.А
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


from заказ import Order
from пицца import ПиццаПепперони, ПиццаБарбекю, ПиццаДарыМоря


class Terminal:
    Company = "Пиццерия №1"
    Cancellation = -1
    Confirmation = 0

    def __init__(self):
        self.menu = [ПиццаПепперони(), ПиццаБарбекю(), ПиццаДарыМоря()]
        self.Order = None
        self.SeeMenu = True

    def __str__(self):
        return (self.Company + "\nДобро пожаловать!\n")

    def показать_меню(self):
        if not self.SeeMenu:
            return

        print("Меню: ")
        for i in range(len(self.menu)):
            print(str(i + 1) + ".  " + str(self.menu[i]))
        print("Для выбора укажите цифру через <ENTER>. \nДля отмены заказа введите -1 \nДля подтверждения заказа "
              "введите 0")

        self.SeeMenu = False

    def Processing(self, point):
        Confirmation = False
        if Confirmation == False:
            try:
                point = int(point)
                if point == Terminal.Cancellation:
                    self.Order.OrderPizza = []

                elif point == Terminal.Confirmation:
                    print("Заказ подтверждён")
                    print(f"Заказ №{Order.counter}")
                    for i in range(len(self.Order.OrderPizza)):
                        print(str(i + 1) + ".  " + str(self.Order.OrderPizza[i]))
                    print(f"Сумма заказа: {self.Order.sum()} р.")
                    Confirmation = True
                    self.AcceptMoney()

                elif 1 <= point <= len(self.menu):
                    if self.Order is None:
                        self.Order = Order()
                    Pizza = self.menu[point - 1]
                    self.Order.ADD(Pizza)
                    print(f"Пицца {self.menu[point - 1].name} добавлена!")
                else:
                    raise ValueError
            except ValueError:
                print("Не могу распознать команду! Проверьте ввод.")
            except Exception as err:
                print("Во время работы терминала произошла ошибка...")

    def CalculateMoney(self, Oplata):
        SumMoney = int(Oplata)
        if SumMoney >= self.Order.sum():
            change = SumMoney - self.Order.sum()
            return change
        else:
            print('Недостаточно средств.')
            return self.AcceptMoney()

    def AcceptMoney(self):
        try:
            SumMoney = input('Введите сумму: ')

            change = int(self.CalculateMoney(SumMoney))
            if change >= 0:
                print(f"Вы внесли {SumMoney} р. Сдача: {change} р.\n")
                self.Order.выполнить()
                self.Processing()
        except Exception as err:
            print("\n")
