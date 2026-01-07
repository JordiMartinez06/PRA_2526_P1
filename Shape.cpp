#include "Shape.h"
#include <string>
#include <stdexcept>

static bool valid_color(const std::string& c) {
    return c == "red" || c == "green" || c == "blue";
}

Shape::Shape() : color("red") {}

Shape::Shape(const std::string& color) : color(color) {
    if (!valid_color(this->color)) throw std::invalid_argument("invalid color");
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(const std::string& c) {
    if (!valid_color(c)) throw std::invalid_argument("invalid color");
    color = c;
}

