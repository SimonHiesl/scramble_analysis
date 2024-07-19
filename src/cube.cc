#include "../include/cube.h"

// Default constructor: Initializes the solved state
Cube::Cube() {
    for (unsigned short i = 0; i < 54; ++i) {
        state[i] = i;
    }
}

// Parameter constructor: Scrambles the cube with a given initial scramble
Cube::Cube(const std::string& init_scramble) : scramble{init_scramble} {
    for (unsigned short i = 0; i < 54; ++i) {
        state[i] = i;
    }
    scramble_cube(scramble);
}

// Getter function for the scramble
std::string Cube::get_scramble() const {
    return scramble;
}

// Getter function for the state array
std::array<unsigned short, 54> Cube::get_cube() const {
    return state;
}

// Visualization of the current cube state
void Cube::print_cube() const {
    for (unsigned short elem : state) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Scrambler of the cube
void Cube::scramble_cube(const std::string& scramble) {

}
