#include <iostream>
#include <cstdlib>
#include <ctime>

#include "terrain.h"
#include "diamond-square.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 6 && argc != 7 && argc != 8) {
        std::cerr << "Usage: " << argv[0] << " n tl tr br bl [rs] [filename]" << std::endl;
        return 1;
    }

    std::string filename = "obj.stl"; 
    double rs = 1;
    if (argc >= 7) rs = atoi(argv[6]);
    if (argc == 8) filename = argv[7];

    Terrain terrain = diamond_square::diamond_square(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), rs);

    terrain.to_stl(filename, Terrain::STL_BIN);

    return 0;
}