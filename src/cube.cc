#include "../include/cube.h"
#include <iostream>

// Default constructor: Initializes the solved state
Cube::Cube() {
    // Corners:
    // 0 = ULB, 1 = URB, 2 = URF, 3 = ULF,
    // 4 = LUB, 5 = LUF, ...
    // Edges:
    // 24 = UB, 25 = UR, 26 = UF, 27 = UL,
    // 28 = LU, 29 = LF, ...
    // Centers:
    // 50 = white, 51 = orange, ...
    state = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53
    };
}

// Parameter constructor: Scrambles the cube with a given initial scramble
Cube::Cube(const std::string& init_scramble) : scramble{init_scramble} {
    state = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53
    };
    scramble_cube(scramble);
}

// Getter function for the scramble
std::string Cube::get_scramble() const {
    return scramble;
}

// Getter function for the state array
std::array<unsigned short, 54> Cube::get_state() const {
    return state;
}

// Setter function for the state of the cube
void Cube::set_state(const std::array<unsigned short, 54>& new_state) {
    state = new_state;
}

// Visualization of the current cube state
void Cube::print_cube() const {
    const std::array<char, 54> colors = {
        'W', 'W', 'W', 'W', 'O', 'O', 'O', 'O', 'G', 'G', 'G', 'G', 
        'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'Y', 'Y', 'Y', 'Y',
        'W', 'W', 'W', 'W', 'O', 'O', 'O', 'O', 'G', 'G', 'G', 'G',
        'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'Y', 'Y', 'Y', 'Y',
        'W', 'O', 'G', 'R', 'B', 'Y'
    };
    for (unsigned short elem : state) {
        std::cout << colors[elem] << " ";
    }
    std::cout << std::endl;
}

// Printing the scramble of the instance
void Cube::print_scramble() const {
    std::cout << scramble << std::endl;
}

// Scrambler of the cube
void Cube::scramble_cube(const std::string& scramble) {

}

// Checking if the cube is solved
bool Cube::is_solved() const {
    const std::array<unsigned short, 54> solved_state = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53
    };
    return state == solved_state;
}
