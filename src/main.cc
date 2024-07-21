#include "../include/cube.h"
#include "../include/turns.h"
#include <fstream>

int main() {
    // Open the input and output files:
    std::ifstream inputFile("../data/set_1.txt");
    /* std::ofstream outputFile("../data/result.txt"); */
    // Read each scramble from the input line
    std::string line;
    while (std::getline(inputFile, line)) {
        Cube cube{line};
        /* cube.print_cube(); */
        /* outputFile << line << std::endl; */
    }
    // Close the files
    inputFile.close();
    /* outputFile.close(); */
    return 0;
}
