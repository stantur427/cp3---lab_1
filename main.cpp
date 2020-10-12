#include <iostream>
#include <cmath>
using namespace std;

class point
{
protected:
    double x;
    double y;
public:
    point()
    {
        cout << "Type coordinates." << endl;
        cin >> x;
        cin >> y;
    }
    void show()
    {
        cout << "Coordinates are: (" << x;
        cout << " ," << y << ")" << endl;
    }
};

class circle: public point
{
private:
    double radius;
public:
    circle()
    {
        cout << "Type radius" << endl;
        cin.ignore();
        cin >> radius;
    }
    double area()
    {
        return (3.14159265 * radius * radius);
    }
    double circumference()
    {
        return (2 * 3.14159265 * radius);
    }
    void check(double a, double b)
    {
     if (sqrt((a-x)*(a-x)+(b-y)*(b-y)) < radius)
     {
         cout << "Point is in circle" << endl;
     }
     else
     {
         cout << "Point isn't in circle" << endl;
     }
    }
};

class square: public point
{
private:
    double side;
public:
    square()
    {
        cout << "Type side length" << endl;
        cin.ignore();
        cin >> side;
    }
    double area()
    {
        return (side * side);
    }
    double circumference()
    {
        return (4 * side);
    }
    void check(double a, double b)
    {
        if(a > x && a < (x+side) && b > y && b < (y+side) )
        {
            cout << "Point is in square" << endl;
        }
        else
        {
            cout << "Point is not in square" << endl;
        }
    }
};

class rectangle: public point//I thought about this class being a triangle but since I had no idea how to mathematically check if a point is in a triangle I decided to go with a rectangle
{
private:
    double first_side;
    double second_side;
public:
    rectangle()
    {
        cout << "Type side's lenghts" << endl;
        cin.ignore();
        cin >> first_side;
        cin >> second_side;
    }
    double area()
    {
        return (first_side * second_side);
    }
    double circumference ()
    {
        return (2 * (first_side + second_side));
    }
    void check(double a, double b)
    {
        if (a > x && a < (x+first_side) && b > y && b < (y+second_side) )
        {
            cout << "Point is in rectangle" << endl;
        }
        else
        {
            cout << "Point isn't in rectangle" << endl;
        }
    }
};
// P.S after all this is programming not maths
//P.P.S circumference to obwód wed³ug google
void print_two(double a, double b)
{
    cout << "Area is: " << a << endl;
    cout << "Circumference is: " << b << endl;
}

int main()
{
    double a,b;
    circle first;
    first.show();
    a = first.area();
    b = first.circumference();
    print_two(a,b);
    first.check(4.0, 5.0);
    square second;
    a = second.area();
    b = second.circumference();
    print_two(a,b);
    second.check(4.1, 5.1);
    rectangle third;
    a = third.area();
    b = third.circumference();
    print_two(a,b);
    third.check(4.2,5.2);
    return 4;
}
