# Программирование на языке высокого уровня (Python).
# Задание №4.3.2. Вариант 4
#
# Выполнила: Глущенко М.А
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com

from пицца import Pizza
from пицца import ПиццаПепперони, ПиццаБарбекю, ПиццаДарыМоря
import time


class Order:
    counter = 0

    def __init__(self):
        self.OrderPizza = []
        Order.counter += 1

    def __str__(self):
        print("Заказ №" + Order.counter)
        for i in self.OrderPizza:
            print(i + 1 + self.OrderPizza[i].__str__())
        print("Сумма заказа: " + self.sum() + "р.")

    def ADD(self, pizza):
        self.OrderPizza.append(pizza)

    def sum(self):
        cost = 0
        for i in range(len(self.OrderPizza)):
            cost += self.OrderPizza[i].price
        return cost

    def выполнить(self):
        print("Заказ поступил на выполнение...")
        for i in range(len(self.OrderPizza)):
            pizza = self.OrderPizza[i]
            print(f"{i + 1}. {pizza.name}")
            self.pizza = Pizza()
            self.pizza.подготовить(pizza)
        print(f"Заказ №{Order.counter} выполнен! Приятного аппетита!")
        self.OrderPizza = []
        Order.counter += 1
