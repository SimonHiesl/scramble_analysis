#include "../include/analysis.h"

#include <fstream>
#include <iostream>
#include <string>

int main() {
    unsigned long number_scrambles = 50'000'000;
    std::vector<unsigned long> flips(12, 0);
    std::vector<unsigned long> solved_edges(12, 0);
    std::vector<unsigned long> twists(8, 0);
    std::vector<unsigned long> solved_corners(8, 0);
    std::vector<unsigned long> targets(2, 0);
    std::vector<unsigned long> number_algs(20, 0);
    for (int set_number = 1; set_number <= 50; ++set_number) {
        std::string filename;
        if (set_number < 10) {
            filename = "../data/set_0" + std::to_string(set_number) + ".txt";
        } else {
            filename = "../data/set_" + std::to_string(set_number) + ".txt";
        }
        std::ifstream inputFile(filename);
        Analysis::analyze(inputFile, flips, solved_edges, twists, solved_corners, targets, number_algs);
    }
    std::cout << "Number of flips:" << '\n';
    Analysis::print_all(flips, number_scrambles);

    std::cout << "Number of solved edges:" << '\n';
    Analysis::print_all(solved_edges, number_scrambles);

    std::cout << "Number of twists:" << '\n';
    Analysis::print_all(twists, number_scrambles);

    std::cout << "Number of solved corners:" << '\n';
    Analysis::print_all(solved_corners, number_scrambles);

    std::cout << "Number of targets (edges, corners):" << '\n';
    Analysis::print_all(targets, number_scrambles);

    std::cout << "Number of algs:" << '\n';
    Analysis::print_all(number_algs, number_scrambles);

    return 0;
}
