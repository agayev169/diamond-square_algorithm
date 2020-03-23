#include <vector>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "terrain.h"
#include "vector3.h"

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

void Terrain::to_stl(const std::string &filename, uint8_t stl_type) const {
    assert(stl_type == STL_ASCII || stl_type == STL_BIN);

    if (stl_type == STL_ASCII) {
        std::ofstream out_file(filename, std::ofstream::out);

        out_file << "solid terrain" << std::endl;

        for (unsigned int i = 0; i < height_ - 1; ++i) {
            for (unsigned int j = 0; j < width_ - 1; ++j) {
                Vector3 p1(j + 1, i    , data_[i    ][j + 1]);
                Vector3 p2(j    , i    , data_[i    ][j    ]);
                Vector3 p3(j    , i + 1, data_[i + 1][j    ]);

                Vector3 norm1 = (p2 - p1) * (p3 - p2);

                out_file << "facet normal " << norm1.x_ << " " << norm1.y_ << " " << norm1.z_ << std::endl;
                out_file << "outer loop" << std:: endl;
                out_file << "vertex " << p1.x_ << " " << p1.y_ << " " << p1.z_ << std::endl;
                out_file << "vertex " << p2.x_ << " " << p2.y_ << " " << p2.z_ << std::endl;
                out_file << "vertex " << p3.x_ << " " << p3.y_ << " " << p3.z_ << std::endl;
                out_file << "endloop" << std:: endl;
                out_file << "endfacet" << std:: endl;


                Vector3 p4(j + 1, i    , data_[i    ][j + 1]);
                Vector3 p5(j    , i + 1, data_[i + 1][j    ]);
                Vector3 p6(j + 1, i + 1, data_[i + 1][j + 1]);

                Vector3 norm2 = (p5 - p4) * (p6 - p5);

                out_file << "facet normal " << norm1.x_ << " " << norm1.y_ << " " << norm1.z_ << std::endl;
                out_file << "outer loop" << std:: endl;
                out_file << "vertex " << p4.x_ << " " << p4.y_ << " " << p4.z_ << std::endl;
                out_file << "vertex " << p5.x_ << " " << p5.y_ << " " << p5.z_ << std::endl;
                out_file << "vertex " << p6.x_ << " " << p6.y_ << " " << p6.z_ << std::endl;
                out_file << "endloop" << std:: endl;
                out_file << "endfacet" << std:: endl;
            }
        }

        out_file << "endsolid terrain" << std::endl;
        out_file.close();
    } else {
        std::ofstream out_file(filename, std::ofstream::out | std::ofstream::binary);
        char header[STL_HEADER_SIZE];
        for (unsigned int i = 0; i < STL_HEADER_SIZE; ++i) {
            header[i] = 0;
        }

        out_file.write(header, STL_HEADER_SIZE);

        unsigned int triangles_n = (height_ - 1) * (width_ - 1) * 2;
        out_file.write(reinterpret_cast <char *>(&triangles_n), sizeof(triangles_n));

        for (unsigned int i = 0; i < height_ - 1; ++i) {
            for (unsigned int j = 0; j < width_ - 1; ++j) {
                Vector3 p1(j + 1, i    , data_[i    ][j + 1]);
                Vector3 p2(j    , i    , data_[i    ][j    ]);
                Vector3 p3(j    , i + 1, data_[i + 1][j    ]);

                Vector3 norm1 = (p2 - p1) * (p3 - p2);

                Vector3 p4(j + 1, i    , data_[i    ][j + 1]);
                Vector3 p5(j    , i + 1, data_[i + 1][j    ]);
                Vector3 p6(j + 1, i + 1, data_[i + 1][j + 1]);

                Vector3 norm2 = (p5 - p4) * (p6 - p5);

                float vectors1[] = {norm1.x_, norm1.y_, norm1.z_, p1.x_, p1.y_, p1.z_, p2.x_, p2.y_, p2.z_, p3.x_, p3.y_, p3.z_};
                float vectors2[] = {norm2.x_, norm2.y_, norm2.z_, p4.x_, p4.y_, p4.z_, p5.x_, p5.y_, p5.z_, p6.x_, p6.y_, p6.z_};

                uint16_t margin = 0;

                out_file.write(reinterpret_cast <char*>(vectors1), sizeof(float) * 12);
                out_file.write(reinterpret_cast <char*>(&margin), sizeof(margin));

                out_file.write(reinterpret_cast <char*>(vectors2), sizeof(float) * 12);
                out_file.write(reinterpret_cast <char*>(&margin), sizeof(margin));
            }
        }
        out_file.close();
    }
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