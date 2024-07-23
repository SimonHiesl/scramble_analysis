#ifndef TRACING_H
#define TRACING_H

#include "cube.h"
#include <vector>

class Tracing {
    public:
        static std::vector<unsigned short> trace_corners(const Cube& cube);
        static std::vector<unsigned short> trace_edges(const Cube& cube);
        static std::vector<unsigned short> trace_edges_parity(const Cube& cube);
};

#endif
