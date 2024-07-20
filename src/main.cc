#include "../include/cube.h"
#include "../include/turns.h"
#include <iostream>

int main() {
    for (int i = 0; i <= 5; ++i) {
        Cube test_cube{};
        Turns::turn_d_prime(test_cube);
        std::cout << test_cube.is_solved() << std::endl;
        test_cube.print_cube();
    }
    return 0;
}
