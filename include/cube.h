#ifndef CUBE_H
#define CUBE_H

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

        // Method for printing the current scramble to stdout
        void print_scramble() const;

        // Method for scrambling a cube with a given scramble
        void scramble_cube(const std::string& scramble);

        // Method for retrieving the scramble of the cube
        std::string get_scramble() const;

        // Method for retrieving the current cube state
        std::array<unsigned short, 54> get_state() const;

        // Method for setting the current cube state
        void set_state(const std::array<unsigned short, 54>& new_state);

        // Method for checking if the cube is solved
        bool is_solved() const;
    private:
        // Saving the initial scramble in the scramble object
        std::string scramble = "";

        // Cube representation through an array (fixed length) called state
        std::array<unsigned short, 54> state;
};

#endif // CUBE_H
