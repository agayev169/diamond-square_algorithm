#pragma once

#include <vector>
#include <iostream>

#include "vector2.h"

class Terrain {
    private:
        std::vector<std::vector<double>> data_;
        unsigned int width_;
        unsigned int height_;

    public:
        Terrain(unsigned int width, unsigned int height);
        Terrain(const Terrain &other);
        ~Terrain();

        Terrain operator=(const Terrain &other);

        double operator[](const Vector2 &coord) const;
        double &operator[](const Vector2 &coord);

        void set(unsigned int x, unsigned int y, double val);
        void set(const Vector2 &coord, double val);
        double get(unsigned int x, unsigned int y) const;
        double get(const Vector2 &coord) const;

        unsigned int width() const;
        unsigned int height() const;
};

std::ostream &operator<<(std::ostream &os, const Terrain &terrain);