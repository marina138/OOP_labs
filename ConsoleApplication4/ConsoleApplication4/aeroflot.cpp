#include "aeroflot.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

AEROFLOT::AEROFLOT() : nameAeroflot(""), type(""), nomer(0) {}

AEROFLOT::AEROFLOT(const string& name, const string& ty, int nom)
    : nameAeroflot(name), type(ty), nomer(nom) {}

const string& AEROFLOT::getnameAeroflot() const {
    return nameAeroflot;
}

const string& AEROFLOT::gettype() const {
    return type;
}

bool compareAeroflots(const AEROFLOT& aeroflot1, const AEROFLOT& aeroflot2) {
    return aeroflot1.getnameAeroflot() < aeroflot2.getnameAeroflot();
}

int AEROFLOT::getnomer() const {
    return nomer;
}

ostream& operator<<(ostream& out, const AEROFLOT& aeroflot) {
    out << "Название пункта назначения рейса: " << aeroflot.nameAeroflot << endl;
    out << "Тип самолёта: " << aeroflot.type << endl;
    out << "Номер рейса: " << aeroflot.nomer << endl;
    return cout;
}

istream& operator>>(istream& in, AEROFLOT& aeroflot) {
    cout << "Введите название пункта назначения рейса: ";
    getline(in, aeroflot.nameAeroflot);

    cout << "Введите тип самолёта: ";
    getline(in, aeroflot.type);

    cout << "Введите номер рейса: ";
    in >> aeroflot.nomer;

    // Очистка входного буфера
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    return in;
}