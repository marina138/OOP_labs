# Программирование на языке высокого уровня (Python).
# Задание №______. Вариант !!!
#
# Выполнил: Фамилия И.О.
# Группа: !!!
# E-mail: !!!


from os import name


class TimeDeposit:

    def __init__(self, name, interest_rate, period_limit, sum_limit):
        """Инициализировать атрибуты класса."""
        self.name = name
        self.interest_rate = interest_rate
        self.period_limit = period_limit
        self.sum_limit = sum_limit
        self._check_self()

    def __str__(self):
        self.name = "Срочный вклад"
        a = int(input(interest_rate = ""))
        self.period_limit = (6, 18)
        self.sum_limit = (1000, 100000)
        print (f"Наименование: {self.name}")
        print (f"Валюта: {self.currency}")
        print (f"Процентная ставка: {a}")
        print (f"Допустимый срок вклада от{self.period_limit[0]} до {self.period_limit[1]}")
        print (f"Допустимая сумма вклада от{self.sum_limit[0]} до {self.sum_limit[1]}")

    @property
    def currency(self):
        return "руб."  # свойство

    def _check_self(self):
        assert 0 < self.interest_rate <= 100, \
            "Неверно указан процент по вкладу!"
        assert 1 <= self.period_limit[0] < self.period_limit[1], \
            "Неверно указаны ограничения по сроку вклада!"
        assert 0 < self.sum_limit[0] <= self.sum_limit[1], \
            "Неверно указаны ограничения по сумме вклада!"

    def _check_user_params(self, initial_sum, period):
        """Проверить, что данные депозита соответствуют его ограничениям."""
        is_sum_ok = self.sum_limit[0] <= initial_sum < self.sum_limit[1]
        is_period_ok = self.period_limit[0] <= period < self.period_limit[1]
        assert is_sum_ok and is_period_ok, "Условия вклада не соблюдены!"

    def get_profit(self, initial_sum, period):
        # Проверить, укладывается ли вклад в ограничения
        self._check_user_params(initial_sum, period)
        # Выполнить расчет
        return initial_sum * self.interest_rate / 100 * period / 12

    def get_sum(self, initial_sum, period):
        # Проверить, укладывается ли вклад в ограничения
        return initial_sum + self.get_profit(initial_sum, period)


class BonusTimeDeposit(TimeDeposit):

    def __init__(self, name, interest_rate, period_limit, sum_limit, bonus):
        """Инициализировать атрибуты класса."""
        self.name = name
        self.interest_rate = interest_rate
        self.period_limit = period_limit
        self.sum_limit = sum_limit
        self.bonus = bonus
        # Уберите raise и добавьте необходимый код

        super().__init__(name, interest_rate, period_limit, sum_limit)

    def __str__(self):

        self.name = "Бонусный вклад"
        self.interest_rate = 5
        self.period_limit = (6, 18)
        self.sum_limit = (1000, 100000)
        self.bonus = {"percent" : 5, "sum" : 2000}
        print (f"Наименование: {self.name}")
        print (f"Валюта: {self.currency}")
        print (f"Процентная ставка: {self.interest_rate}")
        print (f"Срок (мес.): {self.period_limit}")
        print (f"Сумма: {self.sum_limit}")
        print (f"Бонус(%): {self.bonus['persents']}")
        print (f"Бонус(мин. сумма): {self.bonus['sum']}")
        # Уберите raise и добавьте необходимый код

    def _check_self(self):
        """Проверить, что данные депозита являются допустимыми."""
        assert 0 < self.interest_rate <= 100, \
            "Неверно указан процент по вкладу!"
        assert 1 <= self.period_limit[0] < self.period_limit[1], \
            "Неверно указаны ограничения по сроку вклада!"
        assert 0 < self.sum_limit[0] <= self.sum_limit[1], \
            "Неверно указаны ограничения по сумме вклада!"
        # Уберите raise и добавьте необходимый код

    def get_profit(self, initial_sum, period):
        # Выполнить расчет
        a = initial_sum * self.interest_rate / 100 * period / 12
        while (a < initial_sum):
            a += self.bonus['sum']
        return a

class CompoundTimeDeposit(TimeDeposit):

    def __str__(self):

        self.name = "Вклад с капитализацией"
        self.interest_rate = 5
        self.period_limit = (6, 18)
        self.sum_limit = (1000, 100000)
        print (f"Наименование: {self.name}")
        print (f"Валюта: {self.currency}")
        print (f"Процентная ставка: {self.interest_rate}")
        print (f"Срок (мес.): {self.period_limit}")
        print (f"Сумма: {self.sum_limit}")
        print (f"Капитализация(%): Да")
        
    def _check_self(self):
        """Проверить, что данные депозита являются допустимыми."""
        assert 0 < self.interest_rate <= 100, \
            "Неверно указан процент по вкладу!"
        assert 1 <= self.period_limit[0] < self.period_limit[1], \
            "Неверно указаны ограничения по сроку вклада!"
        assert 0 < self.sum_limit[0] <= self.sum_limit[1], \
            "Неверно указаны ограничения по сумме вклада!"
        # Уберите raise и добавьте необходимый код
    def get_profit(self, initial_sum, period):

        return (initial_sum * (1 + self.interest_rate / 100 / 12) ** period - initial_sum)
        # Уберите raise и добавьте необходимый код

# ---

deposits_data = dict(interest_rate = 5, period_limit = (6, 18), sum_limit = (1000, 100000))
# Список имеющихся депозитов
deposits = (
    TimeDeposit("Сохраняй", interest_rate=5,period_limit=(6, 18),sum_limit=(1000, 100000)),
    BonusTimeDeposit("Бонусный 2", **deposits_data,bonus=dict(percent=5, sum=2000)),
    CompoundTimeDeposit("С капитализацией", **deposits_data))

