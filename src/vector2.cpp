#include "vector2.h"

Vector2::Vector2() : x_(0), y_(0) {}

Vector2::Vector2(unsigned int x, unsigned int y) : x_(x), y_(y) {}

Vector2::~Vector2() {}

Vector2 Vector2::operator=(const Vector2 &other) {
    x_ = other.x_;
    y_ = other.y_;

    return *this;
}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return Vector2(x_ + other.x_, y_ + other.y_);
}

Vector2 Vector2::operator+=(const Vector2 &other) {
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return Vector2(x_ - other.x_, y_ - other.y_);
}

Vector2 Vector2::operator-=(const Vector2 &other) {
    x_ -= other.x_;
    y_ -= other.y_;

    return *this;
}

Vector2 Vector2::operator/(unsigned int n) const {
    return Vector2(x_ / n, y_ / n);
}

Vector2 Vector2::operator/=(unsigned int n) {
    x_ /= n;
    y_ /= n;

    return *this;
}

bool Vector2::operator<(const Vector2 &other) const {
    return x_ < other.x_ && y_ < other.y_;
}

bool Vector2::operator<=(const Vector2 &other) const {
    return x_ <= other.x_ && y_ <= other.y_;
}

bool Vector2::operator>(const Vector2 &other) const {
    return x_ > other.x_ && y_ > other.y_;
}

bool Vector2::operator>=(const Vector2 &other) const {
    return x_ >= other.x_ && y_ >= other.y_;
}

bool Vector2::operator==(const Vector2 &other) const {
    return x_ == other.x_ && y_ == other.y_;
}