#include <bits/stdc++.h>
using namespace std;

class IShape2D {
public:
    virtual ~IShape2D() = default;
    virtual double calculateArea() const = 0;
};

class IShape3D {
public:
    virtual ~IShape3D() = default;
    virtual double calculateVolume() const = 0;
};

class Square : public IShape2D {
private:
    double side;

public:
    Square(double s) : side(s) {}
    double calculateArea() const override {
        return side * side;
    }
};

class Circle : public IShape2D {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

class Cube : public IShape3D {
private:
    double side;

public:
    Cube(double s) : side(s) {}
    double calculateVolume() const override {
        return side * side * side;
    }
};

class Sphere : public IShape3D {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}
    double calculateVolume() const override {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
};

int main() {
    cout << "Demonstrating Interface Segregation Principle (ISP)\n";
    cout << "---------------------------------------------------\n\n";

    cout << "2D Shapes:\n";
    Square square(5.0);
    Circle circle(3.0);

    IShape2D* shape2D_1 = &square;
    IShape2D* shape2D_2 = &circle;

    cout << "Square Area: " << shape2D_1->calculateArea() << std::endl;
    cout << "Circle Area: " << shape2D_2->calculateArea() << std::endl;

    cout << "\n";

    cout << "3D Shapes:\n";
    Cube cube(4.0);
    Sphere sphere(2.5);

    IShape3D* shape3D_1 = &cube;
    IShape3D* shape3D_2 = &sphere;

    cout << "Cube Volume: " << shape3D_1->calculateVolume() << std::endl;
    cout << "Sphere Volume: " << shape3D_2->calculateVolume() << std::endl;

    return 0;
}
