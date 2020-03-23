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
        const static uint8_t STL_ASCII = 0;
        const static uint8_t STL_BIN   = 1;
        const static unsigned int STL_HEADER_SIZE = 80;

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

        void to_stl(const std::string &filename, uint8_t stl_type) const;
};

std::ostream &operator<<(std::ostream &os, const Terrain &terrain);