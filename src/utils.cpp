#include "utils.h"
#include "vector2.h"

unsigned int diamond_square::power(unsigned int a, unsigned int b) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < b; ++i) {
        result *= a;
    }
    return result;
}

bool diamond_square::between(const Vector2 &point, const Vector2 &tl, const Vector2 &br) {
    return tl <= point && point <= br;
}