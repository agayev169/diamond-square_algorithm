#pragma once

#include "terrain.h"
#include "vector2.h"

namespace diamond_square {
    Terrain diamond_square(unsigned int n, double tl, double tr, double br, double bl, double random_scale=1.0);
};