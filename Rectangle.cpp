
#include "Rectangle.h"
#include <cmath>
#include <ostream>
#include <iostream>

static bool equal_double(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) <= eps;
}

bool Rectangle::check(Point2D* vertices) {
    if (!vertices) return false;
    double a = Point2D::distance(vertices[0], vertices[1]);
    double b = Point2D::distance(vertices[1], vertices[2]);
    double c = Point2D::distance(vertices[2], vertices[3]);
    double d = Point2D::distance(vertices[3], vertices[0]);
    return equal_double(a, c) && equal_double(b, d);
}

Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1.0,  0.5);
    vs[1] = Point2D( 1.0,  0.5);
    vs[2] = Point2D( 1.0, -0.5);
    vs[3] = Point2D(-1.0, -0.5);
}

Rectangle::Rectangle(const std::string& color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) throw std::invalid_argument("invalid rectangle vertices");
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.get_color()) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
}

Rectangle::~Rectangle() {
    delete[] vs;
    vs = nullptr;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) throw std::out_of_range("vertex index out of range");
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind >= N_VERTICES) throw std::out_of_range("operator[] index out of range");
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("invalid rectangle vertices");
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        set_color(r.get_color());
        for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
    }
    return *this;
}

double Rectangle::area() const {
    double w = Point2D::distance(vs[0], vs[1]);
    double h = Point2D::distance(vs[1], vs[2]);
    return w * h;
}

double Rectangle::perimeter() const {
    double w = Point2D::distance(vs[0], vs[1]);
    double h = Point2D::distance(vs[1], vs[2]);
    return 2.0 * (w + h);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    out << "Rectangle{color=" << r.get_color()
        << ", v0=" << r.vs[0]
        << ", v1=" << r.vs[1]
        << ", v2=" << r.vs[2]
        << ", v3=" << r.vs[3]
        << ", area=" << r.area()
        << ", perimeter=" << r.perimeter()
        << "}";
    return out;
}

