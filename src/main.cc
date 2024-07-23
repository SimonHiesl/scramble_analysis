#include "../include/cube.h"
#include "../include/turns.h"
#include "../include/tracing.h"
#include <fstream>
#include <iostream>
#include <array>

void print_vector(std::vector<int> vec) {
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

void print_average(std::vector<int> vec) {
    double count = 0.0;
    for (size_t i = 0; i < vec.size(); ++i) {
        count += i * vec[i];
    }
    std::cout << count / 1'000'000 << '\n';
}

int get_algs(const std::vector<unsigned short>& corner_targets, const std::vector<unsigned short>& edge_targets) {
    static constexpr std::array<unsigned short, 7> twist_lookup = {1, 2, 2, 3, 4, 4, 5};
    int algs = edge_targets[0] / 2 + corner_targets[0] / 2 + corner_targets[0] % 2;
    algs += edge_targets[1] / 2 + edge_targets[1] % 2;
    int offset = std::max(corner_targets[1], corner_targets[2]) - std::min(corner_targets[1], corner_targets[2]);
    algs += std::min(corner_targets[1], corner_targets[2]) + twist_lookup[offset - 1];
    return algs;
}

/* int main() { */
/*     constexpr std::array<char, 24> letterpair_lookup = { */
/*         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', */
/*         'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X' */
/*     }; */
/*     std::ifstream inputFile("../data/edge.txt"); */
/*     /1* std::ofstream outputFile("../data/result.txt"); *1/ */
/*     std::string line; */
/*     while (std::getline(inputFile, line)) { */
/*         Cube cube{line}; */
/*         std::vector<unsigned short> corner_targets = Tracing::trace_corners(cube); */
/*         std::vector<unsigned short> edge_targets; */
/*         edge_targets = Tracing::trace_edges_parity(cube); */
/*         for (unsigned short target : corner_targets) { */
/*             std::cout << letterpair_lookup[target] << " "; */
/*         } */
/*         std::cout << "\n"; */
/*         for (unsigned short target : edge_targets) { */
/*             std::cout << letterpair_lookup[target - 24] << " "; */
/*         } */
/*         std::cout << "\n"; */
/*     } */
/*     inputFile.close(); */
/*     /1* outputFile.close(); *1/ */
/*     return 0; */
/* } */

int main() {
    constexpr std::array<char, 24> letterpair_lookup = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'
    };
    std::ifstream inputFile("../data/set_01.txt");
    /* std::ofstream outputFile("../data/result.txt"); */
    std::array<int, 4> results = {0, 0, 0, 0};
    std::string line;
    std::vector<int> flips(12, 0);
    std::vector<int> solved_edges(12, 0);
    std::vector<int> twists(8, 0);
    std::vector<int> solved_corners(8, 0);
    long number_edge_targets = 0;
    long number_corner_targets = 0;
    std::vector<int> number_algs(20, 0);
    while (std::getline(inputFile, line)) {
        Cube cube{line};
        std::vector<unsigned short> corner_targets = Tracing::trace_corners(cube);
        std::vector<unsigned short> edge_targets;
        if (corner_targets[0] % 2 == 0) {
            edge_targets = Tracing::trace_edges(cube);
        } else {
            edge_targets = Tracing::trace_edges_parity(cube);
        }
        ++flips[edge_targets[1]];
        ++twists[corner_targets[1]+corner_targets[2]];
        number_corner_targets += corner_targets[0];
        number_edge_targets += edge_targets[0];
        ++solved_corners[corner_targets[3]];
        ++solved_edges[edge_targets[2]];
        ++number_algs[get_algs(corner_targets, edge_targets)];
        if (get_algs(corner_targets, edge_targets) == 5) {
            cube.print_scramble();
            for (unsigned short elem : edge_targets) {
                std::cout << elem << " ";
            }
            std::cout << "\n";
            for (unsigned short elem : corner_targets) {
                std::cout << elem << " ";
            }
            std::cout << "\n";
        }
        /* outputFile << line << std::endl; */
    }
    print_vector(flips);
    print_vector(twists);
    print_vector(solved_corners);
    print_vector(solved_edges);
    std::cout << number_corner_targets << std::endl;
    std::cout << number_edge_targets << std::endl;
    print_vector(number_algs);
    print_average(number_algs);
    inputFile.close();
    /* outputFile.close(); */
    return 0;
}
