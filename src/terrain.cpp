#include <vector>
#include <assert.h>
#include <iostream>
#include <iomanip>

#include "terrain.h"

Terrain::Terrain(unsigned int width, unsigned int height) : 
    width_(width), 
    height_(height),
    data_(height, std::vector<double>(width)) {}

Terrain::Terrain(const Terrain &other) {
    if (other.height() != height_) {
        height_ = other.height();
        data_.resize(height_);
    }

    if (other.width() != width_) {
        width_ = other.width();
        for (size_t i = 0; i < height_; ++i) {
            data_[i].resize(width_);
            for (size_t j = 0; j < width_; ++j) {
                data_[i][j] = other.get(j, i);
            }
        }
    }
}

Terrain::~Terrain() {}

Terrain Terrain::operator=(const Terrain &other) {
    if (other.height() != height_) {
        height_ = other.height();
        data_.resize(height_);
    }

    if (other.width() != width_) {
        width_ = other.width();
        for (size_t i = 0; i < height_; ++i) {
            data_[i].resize(width_);
            for (size_t j = 0; j < width_; ++j) {
                data_[i][j] = other.get(j, i);
            }
        }
    }

    return *this;
}

double Terrain::operator[](const Vector2 &coord) const {
    assert(coord.y_ < height_ && coord.x_ < width_);
    return data_[coord.y_][coord.x_];
}

double& Terrain::operator[](const Vector2 &coord) {
    assert(coord.y_ < height_ && coord.x_ < width_);
    return data_[coord.y_][coord.x_];
}

void Terrain::set(unsigned int x, unsigned int y, double val) {
    assert(y < height_ && x < width_);
    data_[y][x] = val;
}

void Terrain::set(const Vector2 &coord, double val) {
    assert(coord.y_ < height_ && coord.x_ < width_);
    data_[coord.y_][coord.x_] = val;
}

double Terrain::get(unsigned int x, unsigned int y) const {
    assert(y < height_ && x < width_);
    return data_[y][x];
}

double Terrain::get(const Vector2 &coord) const {
    assert(coord.y_ < height_ && coord.x_ < width_);
    return data_[coord.y_][coord.x_];
}

unsigned int Terrain::width() const {
    return width_;
}

unsigned int Terrain::height() const {
    return height_;
}

std::ostream &operator<<(std::ostream &os, const Terrain &terrain) {
    for (unsigned int i = 0; i < terrain.height(); ++i) {
        for (unsigned int j = 0; j < terrain.width(); ++j) {
            os << std::setw(5) << std::setprecision(4) << terrain[Vector2(j, i)] << " ";
        }
        if (i < terrain.height() - 1) os << std::endl;
    }
    return os;
}