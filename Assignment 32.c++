Overriding, overloading, constructor in inheritance

1. Create a class FLOAT that contains one float data member. Overload all the four
arithmetic operators so that they can operate on the objects of FLOAT.
2. Define a class Rectangle and overload area function for different types of data type.
3. Define a base class Animals having member function sound() . Define another
derived class from Animals class named Dogs. You need to override the sound
function of the base class in the derived class.
4. Define a class Addition that can add 2 or 3 numbers of different data types using
function overloading.
5. Define a class A having multiple constructors. Define another class B derived from
class A. Create derived class constructors and show use of constructor in this single
inheritance.
6. C++ Program to illustrate the use of Constructors in multilevel inheritance of your
choice.
7. C++ Program to illustrate the use of Constructors in single inheritance of your choice.
8. Write a C++ program to find the factorial of a number using copy constructor
9. Write a C++ program to calculate the area of triangle, rectangle and circle using
constructor overloading. The program should be menu driven.
10. Create a C++ class for player objects with the following attributes: player no., name,
number of matches and number of goals done in each match. The number of
matches varies for each player. Write a parameterized constructor which initializes
player no., name, number of subjects and creates an array for number of goals and
number of matches dynamically.

Solution:-

1. #include <iostream>
using namespace std;

class FLOAT {
private:
    float value;
public:
    FLOAT(float val = 0.0) : value(val) {}

    FLOAT operator+(const FLOAT& other) {
        return FLOAT(value + other.value);
    }

    FLOAT operator-(const FLOAT& other) {
        return FLOAT(value - other.value);
    }

    FLOAT operator*(const FLOAT& other) {
        return FLOAT(value * other.value);
    }

    FLOAT operator/(const FLOAT& other) {
        if (other.value != 0)
            return FLOAT(value / other.value);
        else {
            cout << "Division by zero!" << endl;
            return FLOAT();
        }
    }

    void display() const {
        cout << value << endl;
    }
};

int main() {
    FLOAT f1(5.5), f2(2.2);
    FLOAT f3 = f1 + f2;
    FLOAT f4 = f1 - f2;
    FLOAT f5 = f1 * f2;
    FLOAT f6 = f1 / f2;

    cout << "f1 + f2 = "; f3.display();
    cout << "f1 - f2 = "; f4.display();
    cout << "f1 * f2 = "; f5.display();
    cout << "f1 / f2 = "; f6.display();

    return 0;
}

2. #include <iostream>
using namespace std;

class Rectangle {
public:
    int area(int length, int width) {
        return length * width;
    }

    float area(float length, float width) {
        return length * width;
    }

    double area(double length, double width) {
        return length * width;
    }
};

int main() {
    Rectangle r;
    cout << "Area (int): " << r.area(5, 3) << endl;
    cout << "Area (float): " << r.area(5.5f, 3.2f) << endl;
    cout << "Area (double): " << r.area(5.5, 3.2) << endl;

    return 0;
}

3. #include <iostream>
using namespace std;

class Animals {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dogs : public Animals {
public:
    void sound() override {
        cout << "Bark" << endl;
    }
};

int main() {
    Animals *a;
    Dogs d;
    a = &d;

    a->sound(); // Should print "Bark"

    return 0;
}

4. #include <iostream>
using namespace std;

class Addition {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Addition add;
    cout << "Addition of 2 int: " << add.add(5, 3) << endl;
    cout << "Addition of 2 float: " << add.add(5.5f, 3.2f) << endl;
    cout << "Addition of 3 int: " << add.add(5, 3, 2) << endl;

    return 0;
}

5. #include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "Default constructor of A" << endl;
    }

    A(int x) {
        cout << "Parameterized constructor of A with value " << x << endl;
    }

    A(const A& a) {
        cout << "Copy constructor of A" << endl;
    }
};

class B : public A {
public:
    B() : A() {
        cout << "Default constructor of B" << endl;
    }

    B(int x) : A(x) {
        cout << "Parameterized constructor of B" << endl;
    }

    B(const B& b) : A(b) {
        cout << "Copy constructor of B" << endl;
    }
};

int main() {
    B b1;
    B b2(10);
    B b3 = b2;

    return 0;
}

6. #include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructor of Base" << endl;
    }
};

class Derived1 : public Base {
public:
    Derived1() {
        cout << "Constructor of Derived1" << endl;
    }
};

class Derived2 : public Derived1 {
public:
    Derived2() {
        cout << "Constructor of Derived2" << endl;
    }
};

int main() {
    Derived2 d2;
    return 0;
}

7. #include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructor of Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Constructor of Derived" << endl;
    }
};

int main() {
    Derived d;
    return 0;
}

8. #include <iostream>
using namespace std;

class Factorial {
private:
    int num;
    int fact;
public:
    Factorial(int n) : num(n), fact(1) {
        for (int i = 1; i <= num; ++i) {
            fact *= i;
        }
    }

    Factorial(const Factorial& f) : num(f.num), fact(f.fact) {
        cout << "Copy constructor called" << endl;
    }

    void display() const {
        cout << "Factorial of " << num << " is " << fact << endl;
    }
};

int main() {
    Factorial f1(5);
    f1.display();

    Factorial f2 = f1; // Copy constructor
    f2.display();

    return 0;
}

9. #include <iostream>
#include <cmath>
using namespace std;

class Area {
public:
    // Constructor for triangle
    Area(float base, float height) {
        cout << "Area of Triangle: " << 0.5 * base * height << endl;
    }

    // Constructor for rectangle
    Area(int length, int width) {
        cout << "Area of Rectangle: " << length * width << endl;
    }

    // Constructor for circle
    Area(double radius) {
        cout << "Area of Circle: " << M_PI * radius * radius << endl;
    }
};

int main() {
    int choice;
    cout << "Calculate area of: \n1. Triangle\n2. Rectangle\n3. Circle\nEnter choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            float base, height;
            cout << "Enter base and height: ";
            cin >> base >> height;
            Area(base, height);
            break;
        case 2:
            int length, width;
            cout << "Enter length and width: ";
            cin >> length >> width;
            Area(length, width);
            break;
        case 3:
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            Area(radius);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

10. #include <iostream>
#include <string>
using namespace std;

class Player {
private:
    int player_no;
    string name;
    int num_matches;
    int* goals;

public:
    Player(int p_no, string n, int matches) : player_no(p_no), name(n), num_matches(matches) {
        goals = new int[num_matches];
        for (int i = 0; i < num_matches; ++i) {
            cout << "Enter goals for match " << i + 1 << ": ";
            cin >> goals[i];
        }
    }

    ~Player() {
        delete[] goals;
    }

    void display() const {
        cout << "Player No: " << player_no << ", Name: " << name << ", Number of Matches: " << num_matches << endl;
        for (int i = 0; i < num_matches; ++i) {
            cout << "Goals in match " << i + 1 << ": " << goals[i] << endl;
        }
    }
};

int main() {
    int p_no, matches;
    string name;
    cout << "Enter player number: ";
    cin >> p_no;
    cin.ignore();
    cout << "Enter player name: ";
    getline(cin, name);
    cout << "Enter number of matches: ";
    cin >> matches;

    Player p(p_no, name, matches);
    p.display();

    return 0;
}
