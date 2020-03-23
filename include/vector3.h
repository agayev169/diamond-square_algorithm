#pragma once

class Vector3 {
    public:
        float x_;
        float y_;
        float z_;

        Vector3();
        Vector3(float x, float y, float z);
        ~Vector3();

        Vector3 operator=(const Vector3 &other);
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator+=(const Vector3 &other);
        Vector3 operator-(const Vector3 &other) const;
        Vector3 operator-=(const Vector3 &other);
        Vector3 operator*(const Vector3 &other) const;
        Vector3 operator*=(const Vector3 &other);

        bool operator<(const Vector3 &other) const;
        bool operator<=(const Vector3 &other) const;
        bool operator>(const Vector3 &other) const;
        bool operator>=(const Vector3 &other) const;
        bool operator==(const Vector3 &other) const;
};