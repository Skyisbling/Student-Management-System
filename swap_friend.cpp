#include <iostream>
using namespace std;

class Second;

class First {
private:
    int a;

public:
    First(int x) {
        a = x;
    }

    friend void swapNumbers(First &, Second &);
};

class Second {
private:
    int b;

public:
    Second(int y) {
        b = y;
    }

    friend void swapNumbers(First &, Second &);
};

void swapNumbers(First &obj1, Second &obj2) {
    int temp = obj1.a;
    obj1.a = obj2.b;
    obj2.b = temp;

    cout << "After swapping:" << endl;
    cout << "First number: " << obj1.a << endl;
    cout << "Second number: " << obj2.b << endl;
}

int main() {
    int x, y;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    First obj1(x);
    Second obj2(y);

    cout << "\nBefore swapping:" << endl;
    cout << "First number: " << x << endl;
    cout << "Second number: " << y << endl;

    swapNumbers(obj1, obj2);

    return 0;
}