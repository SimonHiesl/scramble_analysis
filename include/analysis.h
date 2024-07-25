#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <fstream>
#include <vector>

class Analysis {
    public:
        // Calculates the number of algorithms
        static int get_algs(const std::vector<unsigned short>& corner_targets, const std::vector<unsigned short>& edge_targets);

        // Analyzes one input file
        static void analyze(std::ifstream& inputFile,
                std::vector<unsigned long>& flips,
                std::vector<unsigned long>& solved_edges,
                std::vector<unsigned long>& twists,
                std::vector<unsigned long>& solved_corners,
                std::vector<unsigned long>& targets,
                std::vector<unsigned long>& number_algs);

        // Prints a vector
        static void print_vector(const std::vector<unsigned long>& vec); 

        // Prints the average of each vector element
        static void print_vector_average(const std::vector<unsigned long>& vec, unsigned long number_scrambles);

        // Prints the average of a vector
        static void print_average(std::vector<unsigned long> vec, unsigned long number_scrambles);

        // Prints all three methods above
        static void print_all(std::vector<unsigned long> vec, unsigned long number_scrambles);
};

#endif
