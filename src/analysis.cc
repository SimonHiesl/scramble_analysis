#include "../include/analysis.h"
#include "../include/tracing.h"

#include <fstream>
#include <vector>
#include <array>
#include <iostream>

// Calculates the number of algs
int Analysis::get_algs(const std::vector<unsigned short>& corner_targets, const std::vector<unsigned short>& edge_targets) {
    static constexpr std::array<unsigned short, 7> twist_lookup = {1, 2, 2, 3, 4, 4, 5};
    int algs = edge_targets[0] / 2 + corner_targets[0] / 2 + corner_targets[0] % 2;
    algs += edge_targets[1] / 2 + edge_targets[1] % 2;
    int offset = std::max(corner_targets[1], corner_targets[2]) - std::min(corner_targets[1], corner_targets[2]);
    algs += std::min(corner_targets[1], corner_targets[2]) + twist_lookup[offset - 1];
    return algs;
}

// Calculates the number of flips, twists, solved edges/corners, targets and algs
void Analysis::analyze(std::ifstream& inputFile, std::vector<unsigned long>& flips,
                                                 std::vector<unsigned long>& solved_edges,
                                                 std::vector<unsigned long>& twists,
                                                 std::vector<unsigned long>& solved_corners,
                                                 std::vector<unsigned long>& targets,
                                                 std::vector<unsigned long>& number_algs) {
    std::string line;
    while (std::getline(inputFile, line)) {
        Cube cube{line};
        // Corner tracing has to be executed before tracing edges in order to set the parity correctly
        std::vector<unsigned short> corner_targets = Tracing::trace_corners(cube, false);
        std::vector<unsigned short> edge_targets = Tracing::trace_edges(cube, false);
        ++flips[edge_targets[1]];
        ++twists[corner_targets[1]+corner_targets[2]];
        targets[0] += edge_targets[0];
        targets[1] += corner_targets[0];
        ++solved_corners[corner_targets[3]];
        ++solved_edges[edge_targets[2]];
        ++number_algs[get_algs(corner_targets, edge_targets)];
    }
    inputFile.close();
}

// Prints a vector
void Analysis::print_vector(const std::vector<unsigned long>& vec) {
    for (unsigned long elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

// Prints the average of each element in a vector
void Analysis::print_vector_average(const std::vector<unsigned long>& vec, unsigned long number_scrambles) {
    for (unsigned long elem : vec) {
        double average = static_cast<double>(elem) / number_scrambles;
        std::cout << average << " ";
    }
    std::cout << '\n';
}

// Prints the average of a vector
void Analysis::print_average(std::vector<unsigned long> vec, unsigned long number_scrambles) {
    double count = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        count += i * vec[i];
    }
    std::cout << count / number_scrambles << '\n';
}

// Prints all three methods above at once
void Analysis::print_all(std::vector<unsigned long> vec, unsigned long number_scrambles) {
    print_vector(vec);
    print_vector_average(vec, number_scrambles);
    print_average(vec, number_scrambles);
    std::cout << '\n';
}
