#include "Point.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


int main()
{
    Point p1;

    double d[3] = {1,2,3};
    Point p2(3,d);
    Point p3(p2);

    cout << "Point p1 is: " << endl;
    p1.display();
    cout << "Point p2 is: " << p2 << endl;
    cout << "Point p3 is: " << p3 << endl;

    if(p2==p3)
        cout << "p2 and p3 are the same.";
    else
        cout << "p2 and p3 are different";
    

    cout << "The value of dimension 1 of p3 is :" << p3.getVal(1);
    p3.setVal(1,99);
    cout << "p3 after setup is:"<< p3 <<endl;

    if(p2==p3)
        cout << "p2 and p3 are the same.";
    else
        cout << "p2 and p3 are different";

    Point p4;
    cout << "Please enter dimensions and values of Point p4:" << endl;
    cin >> p4;

    cout << "Point p4 is :"<< p4 << endl;

    Point p5 = p2 + p3;
    cout << "p2+p3 is :" << p5 << endl;

    p5 += p2;
    cout << "p2+p2+p3 is :" << p5 << endl;

    p5++;
    cout << "p2+p2+p3+1 is :" << p5 << endl;

    p5 = p2 * 1.5;
    cout << "p2 * 1.5 is :" << p5 << endl;

    double D = p2 - p3;
    cout << "The distance between p2 and p3 is :" << D << endl;
    p5 = !p4;
    cout << "p4 after reversing the sign is :" << p5 << endl;

    cout << "The number of Points now is :" << Point::getCount() << endl;  
    cout << "The comment for this class is :" << Point::comment << endl;  

    return 0;
}