#include "Circle.h"
#include <ostream>
#include <cmath>
#include <iostream>

static constexpr double PI = 3.141592;

Circle::Circle() : Shape(), center(0.0, 0.0), radius(1.0) {}

Circle::Circle(const std::string& color, const Point2D& center, double radius)
    : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(const Point2D& p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

double Circle::area() const {
    return PI * std::pow(radius, 2.0);
}

double Circle::perimeter() const {
    return 2.0 * PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Circle& c) {
    out << "Circle{color=" << c.get_color()
        << ", center=" << c.center
        << ", radius=" << c.radius
        << ", area=" << c.area()
        << ", perimeter=" << c.perimeter()
        << "}";
    return out;
}


