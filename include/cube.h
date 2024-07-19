#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <array>
#include <string>

class Cube {
    public:
        // Default constructor (solved cube)
        Cube();

        // Parameter constructor with an initial scramble
        Cube(const std::string& init_scramble);

        // Method for printing the current cube state in an understandable format
        void print_cube() const;

        // Method for scrambling a cube with a given scramble
        void scramble_cube(const std::string& scramble);

        // Method for retrieving the scramble of the cube
        std::string get_scramble() const;

        // Method for retrieving the current cube state
        std::array<unsigned short, 54> get_cube() const;
    private:
        // Saving the initial scramble in the scrmable object
        std::string scramble;

        // Cube representation through a array (fixed length) called state
        std::array<unsigned short, 54> state;

        // Turns
};

#endif // CUBE_H
