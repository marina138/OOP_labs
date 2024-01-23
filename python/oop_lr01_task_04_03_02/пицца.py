# Программирование на языке высокого уровня (Python).
# Задание №4.3.2. Вариант 4
#
# Выполнила: Глущенко М.А
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


class Pizza:
    def __init__(self):

        self.name = "Заготовка"
        self.dough = "тонкое"  # тонкое или пышное
        self.sauce = "кечтуп"  # или другой
        self.stuffing = []  # список начинок (по умолчанию - нет)
        self.price = 0

    def __str__(self):

        info = (f"Пицца: {self.name}, \nЦена: {self.price}, \nТесто: {self.dough}, \nСоус {self.sauce}, \nНачинка:  : {self.stuffing}")
        return info

    def подготовить(self, pizza):

        print(f"Начинаю готовить пиццу {pizza.name}"
              f"\n  - замешиваю {pizza.dough} тесто..."
              f"\n  - добавляю соус: {pizza.sauce}..."
              f"\n  - и: {pizza.stuffing}...")
        self.испечь()

    def испечь(self):

        print("Выпекаю пиццу...")
        self.нарезать()

    def нарезать(self):

        print("Уже пошёл процесс нарезки вашей пиццы...")
        self.упаковать()

    def упаковать(self):

        print("Упаковывается в фирменную упаковку!!\n")

class ПиццаПепперони(Pizza):

    def __init__(self):
        super().__init__()

        self.name = "Пепперони"
        self.price = 350
        self.sauce = "томатный"
        self.dough = "тонкое"
        self.stuffing = "пепперони, сыр моцарелла"

class ПиццаБарбекю(Pizza):

    def __init__(self):
        super().__init__()

        self.name = "Барбекю"
        self.price = 450
        self.sauce = "барбекю"
        self.dough = "тонкое"
        self.stuffing = "бекон, ветчина, зелень, сыр моцарелла"

class ПиццаДарыМоря(Pizza):

    def __init__(self):
        super().__init__()

        self.name = "Дары моря"
        self.price = 550
        self.sauce = "тар-тар"
        self.dough = "пышное"
        self.stuffing = "кальмары, креветки, мидии, сыр моцарелла"
