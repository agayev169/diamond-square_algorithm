#include <cstdlib>

#include "diamond-square.h"
#include "terrain.h"
#include "utils.h"
#include "vector2.h"

Terrain diamond_square::diamond_square(unsigned int n, double tl, double tr, double br, double bl, double random_scale) {
    unsigned int vertices_n = power(2, n) + 1;
    Terrain terrain(vertices_n, vertices_n);

    terrain[Vector2(0             , 0             )] = tl;
    terrain[Vector2(vertices_n - 1, 0             )] = tr;
    terrain[Vector2(vertices_n - 1, vertices_n - 1)] = br;
    terrain[Vector2(0             , vertices_n - 1)] = bl;

    for (unsigned int i = 0, step_size = vertices_n - 1; i < n; ++i, step_size /= 2, random_scale /= 2) {
        for (unsigned int j = 0; j < (vertices_n - 1) / step_size; ++j) {
            for (unsigned int k = 0; k < (vertices_n - 1) / step_size; ++k) {
                // Diamond
                Vector2 tl( k      * step_size,  j      * step_size);
                Vector2 tr((k + 1) * step_size,  j      * step_size);
                Vector2 bl( k      * step_size, (j + 1) * step_size);
                Vector2 br((k + 1) * step_size, (j + 1) * step_size);

                Vector2 middle = (tl + tr + bl + br) / 4;

                terrain[middle] = (terrain[tl] + terrain[tr] + terrain[bl] + terrain[br]) / 4 + random_scale * (rand() % 20000 / 10000.0 - 1);

                // Square
                // TODO: Correct this!
                Vector2 t = tl + Vector2(step_size / 2, 0            );
                Vector2 r = tr + Vector2(0            , step_size / 2);
                Vector2 b = br - Vector2(step_size / 2, 0            );
                Vector2 l = bl - Vector2(0            , step_size / 2);

                Vector2 rr = r + Vector2(step_size / 2, 0            );
                Vector2 bb = b + Vector2(0            , step_size / 2);
                
                if (j == 0) {
                    terrain[t] = (terrain[tl] + terrain[middle] + terrain[tr]) / 3 + random_scale * (rand() % 20000 / 10000.0 - 1);
                }
                if (between(rr, Vector2(0, 0), Vector2(vertices_n - 1, vertices_n - 1))) {
                    terrain[r] = (terrain[tr] + terrain[middle] + terrain[br] + terrain[rr]) / 4 + random_scale * (rand() % 20000 / 10000.0 - 1);
                } else {
                    terrain[r] = (terrain[tr] + terrain[middle] + terrain[br]) / 3 + random_scale * (rand() % 20000 / 10000.0 - 1);
                }
                if (between(bb, Vector2(0, 0), Vector2(vertices_n - 1, vertices_n - 1))) {
                    terrain[b] = (terrain[br] + terrain[middle] + terrain[bl] + terrain[bb]) / 4 + random_scale * (rand() % 20000 / 10000.0 - 1);
                } else {
                    terrain[b] = (terrain[br] + terrain[middle] + terrain[bl]) / 3 + random_scale * (rand() % 20000 / 10000.0 - 1);
                }
                if (k == 0) {
                    terrain[l] = (terrain[bl] + terrain[middle] + terrain[tl]) / 3 + random_scale * (rand() % 20000 / 10000.0 - 1);
                }
            }
        }
    }
    return terrain;
}