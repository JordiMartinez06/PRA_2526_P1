#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (s) {
            s->print();
            std::cout << std::endl;
        }
    }
}

double Drawing::get_area_all_circles() {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (auto c = dynamic_cast<Circle*>(s)) {
            total += c->area();
        }
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (auto sq = dynamic_cast<Square*>(s)) {
            sq->translate(incX, incY);
        }
    }
}

