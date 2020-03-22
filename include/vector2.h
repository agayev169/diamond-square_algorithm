#pragma once

class Vector2 {
    public:
        unsigned int x_;
        unsigned int y_;

        Vector2();
        Vector2(unsigned int x, unsigned int y);
        ~Vector2();

        Vector2 operator=(const Vector2 &other);
        Vector2 operator+(const Vector2 &other) const;
        Vector2 operator+=(const Vector2 &other);
        Vector2 operator-(const Vector2 &other) const;
        Vector2 operator-=(const Vector2 &other);
        Vector2 operator/(unsigned int n) const;
        Vector2 operator/=(unsigned int n);

        bool operator<(const Vector2 &other) const;
        bool operator<=(const Vector2 &other) const;
        bool operator>(const Vector2 &other) const;
        bool operator>=(const Vector2 &other) const;
        bool operator==(const Vector2 &other) const;
};