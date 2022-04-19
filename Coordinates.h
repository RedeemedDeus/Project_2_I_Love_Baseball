#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
using namespace std;

class Coordinates
{
private:
    string name;
    int x;
    int y;

public:
    Coordinates()
    {
        name =" ";
        x = 0;
        y = 0;
    }
    Coordinates(string n, int xcord, int ycord)
    {
       name = n;
       x = xcord;
       y = ycord;
    }

    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    string getname()
    {
        return  name;
    }

};

#endif // COORDINATES_H
