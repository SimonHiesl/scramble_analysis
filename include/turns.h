#ifndef TURNS_H
#define TURNS_H

#include "cube.h"

class Turns {
    public:
        // Implementation of every single turn
        static void turn_u(Cube& cube);
        static void turn_u2(Cube& cube);
        static void turn_u_prime(Cube& cube);
        static void turn_l(Cube& cube);
        static void turn_l2(Cube& cube);
        static void turn_l_prime(Cube& cube);
        static void turn_f(Cube& cube);
        static void turn_f2(Cube& cube);
        static void turn_f_prime(Cube& cube);
        static void turn_r(Cube& cube);
        static void turn_r2(Cube& cube);
        static void turn_r_prime(Cube& cube);
        static void turn_b(Cube& cube);
        static void turn_b2(Cube& cube);
        static void turn_b_prime(Cube& cube);
        static void turn_d(Cube& cube);
        static void turn_d2(Cube& cube);
        static void turn_d_prime(Cube& cube);
};

#endif // TURNS_H
