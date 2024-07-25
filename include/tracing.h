#ifndef TRACING_H
#define TRACING_H

#include "cube.h"
#include <vector>

class Tracing {
    public:
        // Traces the corners and sets the parity
        static std::vector<unsigned short> trace_corners(Cube& cube, bool return_targets);

        // Traces the edges according to the parity
        static std::vector<unsigned short> trace_edges(const Cube& cube, bool return_targets);
};

#endif
