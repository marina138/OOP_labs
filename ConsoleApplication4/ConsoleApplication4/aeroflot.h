#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class AEROFLOT {
private:
    string nameAeroflot;
    string type;
    int nomer;

public:
    AEROFLOT();
    AEROFLOT(const string& name, const string& ty, int no);
    const string& getnameAeroflot() const;
    const string& gettype() const;
    int getnomer() const;

    friend ostream& operator<<(ostream& out, const AEROFLOT& aeroflot);
    friend istream& operator>>(istream& in, AEROFLOT& aeroflot);
    
};

bool compareAeroflots(const AEROFLOT& aeroflot1, const AEROFLOT& aeroflot2);

#endif