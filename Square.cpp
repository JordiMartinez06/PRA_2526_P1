#include "Square.h"
#include <cmath>
#include <ostream>
#include <iostream>

static bool equal_double(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) <= eps;
}

static double edge(const Point2D& a, const Point2D& b) {
    return Point2D::distance(a, b);
}

bool Square::check(Point2D* vertices) {
    if (!vertices) return false;
    double d01 = edge(vertices[0], vertices[1]);
    double d12 = edge(vertices[1], vertices[2]);
    double d23 = edge(vertices[2], vertices[3]);
    double d30 = edge(vertices[3], vertices[0]);
    return equal_double(d01, d12) && equal_double(d01, d23) && equal_double(d01, d30);
}

Square::Square() : Rectangle() {
    vs[0] = Point2D(-1.0,  1.0);
    vs[1] = Point2D( 1.0,  1.0);
    vs[2] = Point2D( 1.0, -1.0);
    vs[3] = Point2D(-1.0, -1.0);
}

Square::Square(const std::string& color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) throw std::invalid_argument("invalid square vertices");
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("invalid square vertices");
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Square& s) {
    out << "Square{color=" << s.get_color()
        << ", v0=" << s.vs[0]
        << ", v1=" << s.vs[1]
        << ", v2=" << s.vs[2]
        << ", v3=" << s.vs[3]
        << ", area=" << s.area()
        << ", perimeter=" << s.perimeter()
        << "}";
    return out;
}

