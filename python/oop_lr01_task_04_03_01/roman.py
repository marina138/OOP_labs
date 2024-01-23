# Программирование на языке высокого уровня (Python).
# Задание №1. Вариант !!!
#
# Выполнила: Глущенко Марина Анатольевна
# Группа: ПИН-б-о-21-1
# E-mail: marinalime36@gmail.com


from tkinter.font import ROMAN
class Roman:
    ARABIC_MIN = 1
    ARABIC_MAX = 3999
    ROMAN_MIN = "I"
    ROMAN_MAX = "MMMCMXCIX"

    LETTERS = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    NUMBERS = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

    def __init__(self, value):
        if not isinstance(value, (int, str)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(value)))
        if isinstance(value, int):
            self.__check_arabic(value)
            self._arabic = value
        elif isinstance(value, str):
            self._arabic = self.to_arabic(value)

    def __add__(self, other):
        add = 0
        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))
        if isinstance(other, Roman):
            add = self._arabic + other._arabic
        elif isinstance(other, int):
            add = self._arabic + other
        return Roman.to_roman(add)
    
    def __sub__(self, other):
        sub = 0
        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))
        if isinstance(other, Roman):
            sub = self._arabic - other._arabic
        elif isinstance(other, int):
            sub = self._arabic - other
        return Roman.to_roman(sub)
    
    def __mul__(self, other):
        mul = 0
        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))
        if isinstance(other, Roman):
            mul = self._arabic * other._arabic
        elif isinstance(other, int):
            mul = self._arabic * other
        return Roman.to_roman(mul)
    
    def __floordiv__(self, other):
        flo = 0
        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))
        if isinstance(other, Roman):
            flo = self._arabic // other._arabic
        elif isinstance(other, int):
            flo = self._arabic // other
        return Roman.to_roman(flo)
    
    def __truediv__(self, other):
        return self.__floordiv__(other)

    def __str__(self):
        return Roman.to_roman(self._arabic)

    @staticmethod
    def __check_arabic(value):
        if value > Roman.ARABIC_MAX or value < Roman.ARABIC_MIN:
            raise ValueError("Число выходит за пределы диапазона {0}".format(value))
        
    @staticmethod
    def __check_roman(value):
        for letters in value:
            if letters not in Roman.LETTERS:
                raise ValueError("Используется недопустимый символ {0}".format(value))
        
    @property
    def arabic(self):
        """Вернуть арабское представление числа."""
        return self._arabic

    @staticmethod
    def to_arabic(roman):
        def letter_to_number(letter):
            index = Roman.LETTERS.index(letter)
            return Roman.NUMBERS[index]    
        Roman.__check_roman(roman)
            
        i = 0  # Позиция в строке roman
        value = 0  # Преобразованное число
        while i < len(roman):
            number = letter_to_number(roman[i])
            i += 1
            if i == len(roman):
                value += number
            else:
                next_number = letter_to_number(roman[i])
                if next_number > number:
                    value += next_number - number
                    i += 1
                else:
                    value += number
        Roman.__check_arabic(value)
        return value
    
    @staticmethod
    def to_roman(arabic):
        Roman.__check_arabic(arabic)
        roman = ""
        for i, number in enumerate(Roman.NUMBERS):
            while arabic >= number:
                roman += Roman.LETTERS[i]
                arabic -= Roman.NUMBERS[i]
        return roman
