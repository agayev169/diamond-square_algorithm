#include <iostream>
#include <cstdlib>
#include <ctime>

#include "terrain.h"
#include "diamond-square.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 6 && argc != 7) {
        std::cerr << "Usage: " << argv[0] << " n tl tr br bl [rs]" << std::endl;
        return 1;
    }

    double rs = 1;
    if (argc == 7) rs = atoi(argv[6]);

    Terrain terrain = diamond_square::diamond_square(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), rs);

    terrain.to_stl("obj.stl", Terrain::STL_BIN);

    return 0;
}