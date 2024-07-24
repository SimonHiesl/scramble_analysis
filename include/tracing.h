#ifndef TRACING_H
#define TRACING_H

#include "cube.h"
#include <vector>

class Tracing {
    public:
        static std::vector<unsigned short> trace_corners(Cube& cube);
        static std::vector<unsigned short> trace_edges(const Cube& cube);
};

#endif
