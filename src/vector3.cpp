#include "vector3.h"

Vector3::Vector3() : x_(0), y_(0), z_(0) {}

Vector3::Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

Vector3::~Vector3() {}

Vector3 Vector3::operator=(const Vector3 &other) {
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;

    return *this;
}

Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Vector3 Vector3::operator+=(const Vector3 &other) {
    x_ += other.x_;
    y_ += other.y_;
    z_ += other.z_;

    return *this;
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Vector3 Vector3::operator-=(const Vector3 &other) {
    x_ -= other.x_;
    y_ -= other.y_;
    z_ -= other.z_;

    return *this;
}

Vector3 Vector3::operator*(const Vector3 &other) const {
    return Vector3(y_ * other.z_ - z_ * other.y_, 
                   z_ * other.x_ - x_ * other.z_,
                   x_ * other.y_ - y_ * other.x_);
}

Vector3 Vector3::operator*=(const Vector3 &other) {
    x_ = y_ * other.z_ - z_ * other.y_;
    y_ = z_ * other.x_ - x_ * other.z_;
    z_ = x_ * other.y_ - y_ * other.x_;

    return *this;
}

bool Vector3::operator<(const Vector3 &other) const {
    return x_ < other.x_ && y_ < other.y_ && z_ < other.z_;
}

bool Vector3::operator<=(const Vector3 &other) const {
    return x_ <= other.x_ && y_ <= other.y_ && z_ <= other.z_;
}

bool Vector3::operator>(const Vector3 &other) const {
    return x_ > other.x_ && y_ > other.y_ && z_ > other.z_;
}

bool Vector3::operator>=(const Vector3 &other) const {
    return x_ >= other.x_ && y_ >= other.y_ && z_ >= other.z_;
}

bool Vector3::operator==(const Vector3 &other) const {
    return x_ == other.x_ && y_ == other.y_ && z_ == other.z_;
}