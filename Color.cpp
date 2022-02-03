#include "Color.h"

Color::Color(float red, float green, float blue): red(red), green(green), blue(blue), alpha(1.0f) {
}

Color::Color(float red, float green, float blue, float alpha): red(red), green(green), blue(blue), alpha(alpha) {
}

float Color::Red() const {
    return this->red;
}

float Color::Green() const {
    return this->green;
}

float Color::Blue() const {
    return this->blue;
}

float Color::Alpha() const {
    return this->alpha;
}

void Color::Red(float value) {
    this->red = value;
}

void Color::Green(float value) {
    this->green = value;
}

void Color::Blue(float value) {
    this->blue = value;
}

void Color::Alpha(float value) {
    this->alpha = value;
}

void Color::Set(float r, float g, float b) {
    this->red = r;
    this->green = g;
    this->blue = b;
}

void Color::Set(float r, float g, float b, float a) {
    this->red = r;
    this->green = g;
    this->blue = b;
    this->alpha = a;
}
